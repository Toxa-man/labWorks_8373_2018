#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string> 
#include <vector>
#include <ctime>

#define Player1_model "PL1"
#define Player2_model "PL2"

#define Death_area_model "F"
#define Occupied_area_model "A"
#define Unoccupied_area_model " "

#define Boon_plus_one_to_range "R"
#define Boon_plus_one_to_count "C"

#define Destroyable_wall 'W'
#define Destroyable_wall_model "W"
#define Immortal_wall '#'
#define Immortal_wall_model "#"

#define Bomb_model "(O)"
#define Bomb_in_hand_model "O"
#define Boom_model "XXX"
#define Erase "   "

#define ESC_BUTTON 27

#define Tie 0
#define Player_1_won 1
#define Player_2_won 2

const int y_size = 15, x_size = 30, Player_width = 3, Detonation_ping = 2, game_cicle_step_sleep = 100, Standard_generation_step_for_spawns = 2, Standard_number_of_Destroyable_walls_in_started_generation = 8, number_of_immortal_walls_on_line = (x_size - 2) / 6;
const int Gen1_standard_size = 2, Gen2_standard_size = 2;
const int Number_of_x_squares_on_playground = x_size / Player_width - 1, Number_of_y_squares_on_playground = y_size - 2;
const int Number_of_destroyable_walls = (Number_of_x_squares_on_playground + Number_of_y_squares_on_playground) + Standard_number_of_Destroyable_walls_in_started_generation, Number_of_immortal_walls = number_of_immortal_walls_on_line*(y_size / 2 - 1);
const int Gen1LineSize = x_size - Player_width - 4 * Player_width, Gen2LineSize = x_size - 3 * Player_width - number_of_immortal_walls_on_line * Player_width, Gen3LineSize = x_size - 3, Gen4LineSize = Gen3LineSize - number_of_immortal_walls_on_line * Player_width;
const int gen1_walls = Number_of_destroyable_walls / 8, gen2_walls = Number_of_destroyable_walls / 8, gen3_walls = Number_of_destroyable_walls / 2, gen4_walls = Number_of_destroyable_walls / 4;
const int System_wait = 2;

const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

enum class boon_class {No_class, Explosion, Counter};

struct Options
{
	int Top_Walk;
	int Bot_Walk;
	int Left_Walk;
	int Right_Walk;
	int Plant_Bomb;
};
struct Inventory
{
	int Bomb_counter;
	int Bomb_boom_range;
	int Planted_bomb_counter = 0;
	bool Bomb_planted = false;
};
struct Coordinate_of
{
	int identification_number; //Player1 - 1, Player2 - 2
	int coord_x;
	int coord_y;
	bool alive = true;
};
struct Objects
{
	int coord_x;
	int coord_y;
	bool boon_inside;
	bool boon_active = true;
	boon_class type_of_boon;
};
struct Bombs_settings
{
	int Bomb_number;
	int coord_x;
	int coord_y;
	time_t Bomb_activation = time(0)*2;
};

void Death_Check_while_boom_animation(Coordinate_of &Player, int boom_x_coordinate, int boom_y_coordinate)
{
	if (Player.coord_x == boom_x_coordinate && Player.coord_y == boom_y_coordinate)
	{
		Player.alive = false;
	}
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(handle, coord);
}
void SetColor (Coordinate_of Player)
{
	if (Player.identification_number == 1)
	{
		SetConsoleTextAttribute(handle, FOREGROUND_RED);
	}
	if (Player.identification_number == 2)
	{
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
	}
}
void ResetColor()
{
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
}
void Player1_Player2_started_pos(std::vector<std::string>* area, Coordinate_of &Player1, Coordinate_of &Player2)
{
	gotoxy(Player1.coord_x - 1, Player1.coord_y);
	area[Player1.coord_y][Player1.coord_x] = Occupied_area_model;
	SetConsoleTextAttribute(handle, FOREGROUND_RED);
	std::cout << Player1_model;
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
	gotoxy(Player2.coord_x - 1, Player2.coord_y);
	area[Player2.coord_y][Player2.coord_x] = Occupied_area_model;
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
	std::cout << Player2_model;
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
}
void Refresh_game_screen(std::vector<std::string>* area) 
{
	system("cls");
	for (int i = 0; i < y_size; ++i)
	{
		for (int j = 0; j < x_size; ++j)
		{
			std::cout << area[i][j];
		}
	}
}
void Player_movement(std::vector<std::string>* area, Coordinate_of &Player, Inventory &Inventory, std::vector<Bombs_settings> &Player_Bombs, Options &Options);
void Boon_drop(std::vector<Objects> &Destroyable_walls, int x, int y)
{
	int correct_number;
	gotoxy(x, y);
	for (int i = 0; i < Number_of_destroyable_walls; ++i)
	{
		if (Destroyable_walls[i].coord_x == x && Destroyable_walls[i].coord_y == y)
		{
			correct_number = i;
		}
	}
		switch (Destroyable_walls[correct_number].type_of_boon)
		{
		case boon_class::Counter:
		{
			std::cout << Boon_plus_one_to_count;
			break;
		}
		case boon_class::Explosion:
		{
			std::cout << Boon_plus_one_to_range;
			break;
		}
		}
}

void Boon_PickUp(Coordinate_of &Player, Inventory &Inventory, std::vector<Objects> &Destroyable_walls)
{
	for (int i = 0; i < Number_of_destroyable_walls; ++i)
	{
		if (Player.coord_x == Destroyable_walls[i].coord_x && Player.coord_y == Destroyable_walls[i].coord_y && Destroyable_walls[i].boon_active)
		{
			
			switch (Destroyable_walls[i].type_of_boon)
			{
			case boon_class::Counter:
			{
				Inventory.Bomb_counter += 1;
				Destroyable_walls[i].boon_active = false;
				break;
			}
			case boon_class::Explosion:
			{
				Inventory.Bomb_boom_range += 1;
				Destroyable_walls[i].boon_active = false;
				break;
			}
			}
		}
	}
}
void Boon_detection (bool &Bot, bool &Top, bool &Right, bool &Left, std::vector<Bombs_settings> &Player1_Bombs, std::vector<Bombs_settings> &Player2_Bombs, std::vector<Objects> &Destroyable_walls, int Bomb_number, int Wave_number)
{
	for (int i = 0; i < Number_of_destroyable_walls; ++i)
	{
		if (Destroyable_walls[i].boon_active)
		{
			if (Bot && Player1_Bombs[Bomb_number].coord_y + Wave_number < y_size - Wave_number && Player1_Bombs[Bomb_number].coord_y + Wave_number == Destroyable_walls[i].coord_y && Player1_Bombs[Bomb_number].coord_x == Destroyable_walls[i].coord_x)
			{
				Boon_drop(Destroyable_walls, Player1_Bombs[Bomb_number].coord_x, Player1_Bombs[Bomb_number].coord_y + Wave_number);
			}
			if (Top && Player1_Bombs[Bomb_number].coord_y - Wave_number > 0 && Player1_Bombs[Bomb_number].coord_y - Wave_number == Destroyable_walls[i].coord_y && Player1_Bombs[Bomb_number].coord_x == Destroyable_walls[i].coord_x)
			{
				Boon_drop(Destroyable_walls, Player1_Bombs[Bomb_number].coord_x, Player1_Bombs[Bomb_number].coord_y - Wave_number);
			}
			if (Right && (Player1_Bombs[Bomb_number].coord_x - 1 + Wave_number * Player_width) < x_size - 2 && Player1_Bombs[Bomb_number].coord_y == Destroyable_walls[i].coord_y && Player1_Bombs[Bomb_number].coord_x + Wave_number * Player_width == Destroyable_walls[i].coord_x)
			{
				Boon_drop(Destroyable_walls, Player1_Bombs[Bomb_number].coord_x + Wave_number * Player_width, Player1_Bombs[Bomb_number].coord_y);
			}
			if (Left && Player1_Bombs[Bomb_number].coord_x - Wave_number * Player_width > 1 && Player1_Bombs[Bomb_number].coord_y == Destroyable_walls[i].coord_y && Player1_Bombs[Bomb_number].coord_x - Wave_number * Player_width == Destroyable_walls[i].coord_x)
			{
				Boon_drop(Destroyable_walls, Player1_Bombs[Bomb_number].coord_x - Wave_number * Player_width, Player1_Bombs[Bomb_number].coord_y);
			}
		}
	}

}
void Immortal_object_check(bool &Bot, bool &Top, bool &Right, bool &Left, std::vector<std::string>* area, std::vector<Bombs_settings> &Player1_Bombs, std::vector<Bombs_settings> &Player2_Bombs, std::vector<Objects> &Immortal_walls, int Bomb_number, int Wave_number)
{
	if (Player1_Bombs[Bomb_number].coord_y + Wave_number < y_size - Wave_number && area[Player1_Bombs[Bomb_number].coord_y + Wave_number][Player1_Bombs[Bomb_number].coord_x] == Immortal_wall_model)
	{
		Bot = false;
	}
	if (Player1_Bombs[Bomb_number].coord_y - Wave_number > 0 && area[Player1_Bombs[Bomb_number].coord_y - Wave_number][Player1_Bombs[Bomb_number].coord_x] == Immortal_wall_model)
	{
		Top = false;
	}
	if ((Player1_Bombs[Bomb_number].coord_x - 1 + Wave_number * Player_width) < x_size - 2 && area[Player1_Bombs[Bomb_number].coord_y][Player1_Bombs[Bomb_number].coord_x + Wave_number * Player_width] == Immortal_wall_model)
	{
		Right = false;
	}
	if (Player1_Bombs[Bomb_number].coord_x - Wave_number * Player_width > 1 && area[Player1_Bombs[Bomb_number].coord_y][Player1_Bombs[Bomb_number].coord_x - Wave_number * Player_width] == Immortal_wall_model)
	{
		Left = false;
	}
}
void Bomb_explosion_animation_print_step(std::vector<std::string>* area, Coordinate_of &Player1, Inventory &Inventory1, std::vector<Bombs_settings> &Player1_Bombs, Options &Options1, Coordinate_of &Player2, Inventory &Inventory2, std::vector<Bombs_settings> &Player2_Bombs, Options &Options2, std::vector<Objects> &Immortal_walls, std::vector<Objects> &Destroyable_walls, int Bomb_number)
{
	bool Collision_left = true, Collision_right = true, Collision_top = true, Collision_bot = true, Destroyed_left = true, Destroyed_right = true, Destroyed_top = true, Destroyed_bot = true;
	for (int i = 1; i <= Inventory1.Bomb_boom_range; ++i)
	{
		SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
		Immortal_object_check(Collision_bot, Collision_top, Collision_right, Collision_left, area,  Player1_Bombs, Player2_Bombs, Immortal_walls, Bomb_number, i);
		if (Player1_Bombs[Bomb_number].coord_y + i < y_size - i && Collision_bot && Destroyed_bot)
		{
			Death_Check_while_boom_animation(Player1, Player1_Bombs[Bomb_number].coord_x, Player1_Bombs[Bomb_number].coord_y + i);
			Death_Check_while_boom_animation(Player2, Player1_Bombs[Bomb_number].coord_x, Player1_Bombs[Bomb_number].coord_y + i);
			area[Player1_Bombs[Bomb_number].coord_y + i][Player1_Bombs[Bomb_number].coord_x] = Death_area_model;
			gotoxy(Player1_Bombs[Bomb_number].coord_x - 1, Player1_Bombs[Bomb_number].coord_y + i);
			std::cout << Boom_model;
		}
		if (Player1_Bombs[Bomb_number].coord_y - i > 0 && Collision_top && Destroyed_top)
		{
			Death_Check_while_boom_animation(Player1, Player1_Bombs[Bomb_number].coord_x, Player1_Bombs[Bomb_number].coord_y - i);
			Death_Check_while_boom_animation(Player2, Player1_Bombs[Bomb_number].coord_x, Player1_Bombs[Bomb_number].coord_y - i);
			area[Player1_Bombs[Bomb_number].coord_y - i][Player1_Bombs[Bomb_number].coord_x] = Death_area_model;
			gotoxy(Player1_Bombs[Bomb_number].coord_x - 1, Player1_Bombs[Bomb_number].coord_y - i);
			std::cout << Boom_model;
		}
		if ((Player1_Bombs[Bomb_number].coord_x - 1 + i * Player_width) < x_size - 2 && Collision_right && Destroyed_right)
		{
			Death_Check_while_boom_animation(Player1, Player1_Bombs[Bomb_number].coord_x + i * Player_width, Player1_Bombs[Bomb_number].coord_y);
			Death_Check_while_boom_animation(Player2, Player1_Bombs[Bomb_number].coord_x + i * Player_width, Player1_Bombs[Bomb_number].coord_y);
			area[Player1_Bombs[Bomb_number].coord_y][Player1_Bombs[Bomb_number].coord_x + i * Player_width] = Death_area_model;
			gotoxy(Player1_Bombs[Bomb_number].coord_x - 1 + i * Player_width, Player1_Bombs[Bomb_number].coord_y);
			std::cout << Boom_model;
		}
		if (Player1_Bombs[Bomb_number].coord_x - i * Player_width > 1 && Collision_left && Destroyed_left)
		{
			Death_Check_while_boom_animation(Player1, Player1_Bombs[Bomb_number].coord_x - i * Player_width, Player1_Bombs[Bomb_number].coord_y);
			Death_Check_while_boom_animation(Player2, Player1_Bombs[Bomb_number].coord_x - i * Player_width, Player1_Bombs[Bomb_number].coord_y);
			area[Player1_Bombs[Bomb_number].coord_y][Player1_Bombs[Bomb_number].coord_x - i * Player_width] = Death_area_model;
			gotoxy(Player1_Bombs[Bomb_number].coord_x - 1 - i * Player_width, Player1_Bombs[Bomb_number].coord_y);
			std::cout << Boom_model;
		}
		Sleep(game_cicle_step_sleep);
		if (Player1.alive == true && Player2.alive == true)
		{
			Player_movement(area, Player1, Inventory1, Player1_Bombs, Options1);
			Player_movement(area, Player2, Inventory2, Player2_Bombs, Options2);
		}
	}
	ResetColor();
}
void Bomb_explosion_animation_erase_step(std::vector<std::string>* area, Coordinate_of &Player1, Inventory &Inventory1, std::vector<Bombs_settings> &Player1_Bombs, Options &Options1, Coordinate_of &Player2, Inventory &Inventory2, std::vector<Bombs_settings> &Player2_Bombs, Options &Options2, std::vector<Objects> &Immortal_walls, std::vector<Objects> &Destroyable_walls, int Bomb_number)
{
	bool Collision_left = true, Collision_right = true, Collision_top = true, Collision_bot = true;
	for (int i = 0; i <= Inventory1.Bomb_boom_range; ++i)
	{
		Immortal_object_check(Collision_bot, Collision_top, Collision_right, Collision_left, area,  Player1_Bombs, Player2_Bombs, Immortal_walls, Bomb_number, i);
		if (Player1_Bombs[Bomb_number].coord_y + i < y_size - i  && Collision_bot)
		{
			area[Player1_Bombs[Bomb_number].coord_y + i][Player1_Bombs[Bomb_number].coord_x] = Unoccupied_area_model;
			gotoxy(Player1_Bombs[Bomb_number].coord_x - 1, Player1_Bombs[Bomb_number].coord_y + i);
			std::cout << Erase;
		}
		if (Player1_Bombs[Bomb_number].coord_y - i > 0 && Collision_top)
		{
			area[Player1_Bombs[Bomb_number].coord_y - i][Player1_Bombs[Bomb_number].coord_x] = Unoccupied_area_model;
			gotoxy(Player1_Bombs[Bomb_number].coord_x - 1, Player1_Bombs[Bomb_number].coord_y - i);
			std::cout << Erase;
		}
		if ((Player1_Bombs[Bomb_number].coord_x - 1 + i * Player_width) < x_size - 2 && Collision_right)
		{
			area[Player1_Bombs[Bomb_number].coord_y][Player1_Bombs[Bomb_number].coord_x + i * Player_width] = Unoccupied_area_model;
			gotoxy(Player1_Bombs[Bomb_number].coord_x - 1 + i * Player_width, Player1_Bombs[Bomb_number].coord_y);
			std::cout << Erase;
		}
		if (Player1_Bombs[Bomb_number].coord_x - i * Player_width > 1 && Collision_left)
		{
			area[Player1_Bombs[Bomb_number].coord_y][Player1_Bombs[Bomb_number].coord_x - i * Player_width] = Unoccupied_area_model;
			gotoxy(Player1_Bombs[Bomb_number].coord_x - 1 - i * Player_width, Player1_Bombs[Bomb_number].coord_y);
			std::cout << Erase;
		}
		Boon_detection(Collision_bot, Collision_top, Collision_right, Collision_left, Player1_Bombs, Player2_Bombs, Destroyable_walls, Bomb_number, i);
		Sleep(game_cicle_step_sleep);
		if (Player1.alive == true && Player2.alive == true)
		{
			Player_movement(area, Player1, Inventory1, Player1_Bombs, Options1);
			Player_movement(area, Player2, Inventory2, Player2_Bombs, Options2);
		}
	}
}
void Bomb_explosion_time_check(std::vector<std::string>* area, Coordinate_of &Player1, Inventory &Inventory1, std::vector<Bombs_settings> &Player1_Bombs, Options &Options1, Coordinate_of &Player2, Inventory &Inventory2, std::vector<Bombs_settings> &Player2_Bombs, Options &Options2, std::vector<Objects> &Immortal_walls, std::vector<Objects> & Destroyable_walls)
{
	for (int k = 0; k < Inventory1.Bomb_counter; ++k)
	{
		if (time(0) > Player1_Bombs[k].Bomb_activation)
		{
			gotoxy(Player1_Bombs[k].coord_x - 1, Player1_Bombs[k].coord_y);
			area[Player1_Bombs[k].coord_y][Player1_Bombs[k].coord_x] = Unoccupied_area_model;
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			std::cout << Boom_model;
			ResetColor();
			Player1_Bombs[k].Bomb_activation *= 2;
			Bomb_explosion_animation_print_step(area, Player1, Inventory1, Player1_Bombs, Options1, Player2, Inventory2, Player2_Bombs, Options2, Immortal_walls, Destroyable_walls, k);
			Bomb_explosion_animation_erase_step(area, Player1, Inventory1, Player1_Bombs, Options1, Player2, Inventory2, Player2_Bombs, Options2, Immortal_walls, Destroyable_walls, k);
			--Inventory1.Planted_bomb_counter;
		}
	}

	for (int k = 0; k < Inventory2.Bomb_counter; ++k)
	{
		if (time(0) > Player2_Bombs[k].Bomb_activation)
		{
			gotoxy(Player2_Bombs[k].coord_x - 1, Player2_Bombs[k].coord_y);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			std::cout << Boom_model;
			ResetColor();
			Player2_Bombs[k].Bomb_activation *=2;
			Bomb_explosion_animation_print_step(area, Player2, Inventory2, Player2_Bombs, Options2, Player1, Inventory1, Player1_Bombs, Options1, Immortal_walls, Destroyable_walls, k);
			Bomb_explosion_animation_erase_step(area, Player2, Inventory2, Player2_Bombs, Options2, Player1, Inventory1, Player1_Bombs, Options1, Immortal_walls, Destroyable_walls, k);
			--Inventory2.Planted_bomb_counter;
		}
	}
}
void Update_bomb_settings(Coordinate_of &Player, Inventory &Inventory, std::vector<Bombs_settings> &Player_Bombs)
{
	Player_Bombs[Inventory.Planted_bomb_counter].coord_x = Player.coord_x;
	Player_Bombs[Inventory.Planted_bomb_counter].coord_y = Player.coord_y;
	Player_Bombs[Inventory.Planted_bomb_counter].Bomb_activation = time(0) + Detonation_ping;
	Player_Bombs[Inventory.Planted_bomb_counter].Bomb_number = Inventory.Planted_bomb_counter;
}
void Player_plant_the_bomb(std::vector<std::string>* area, Coordinate_of &Player, Inventory &Inventory, Options &Options)
{
	if (GetAsyncKeyState(Options.Plant_Bomb) < 0 && Inventory.Bomb_counter != Inventory.Planted_bomb_counter)
	{
		SetColor(Player);
		Inventory.Bomb_planted = true;
		gotoxy(Player.coord_x, Player.coord_y);
		std::cout << Bomb_in_hand_model;
		ResetColor();
	}
}
void Move_Player(Coordinate_of &Player)
{
	gotoxy(Player.coord_x - 1, Player.coord_y);
	SetColor(Player);
	if (Player.identification_number == 1)
	{
		SetConsoleTextAttribute(handle, FOREGROUND_RED);
		std::cout << Player1_model;
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
	}
	else
		if(Player.identification_number == 2)
		{
			SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
			std::cout << Player2_model;
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
		}
	ResetColor();
}
void Erase_player(std::vector<std::string>* area, Coordinate_of &Player, Inventory &Inventory, std::vector<Bombs_settings> &Player_Bombs)
{
	gotoxy(Player.coord_x - 1, Player.coord_y);
	SetColor(Player);
	if (Inventory.Bomb_planted)
	{
		std::cout << Bomb_model;
		area[Player.coord_y][Player.coord_x] = Occupied_area_model;
		Inventory.Bomb_planted = false;
		Update_bomb_settings(Player, Inventory, Player_Bombs);
		++Inventory.Planted_bomb_counter;
	}
	else
	{
		area[Player.coord_y][Player.coord_x] = Unoccupied_area_model;
		std::cout << Erase;
	}
	ResetColor();
}
void Player_movement(std::vector<std::string>* area, Coordinate_of &Player, Inventory &Inventory, std::vector<Bombs_settings> &Player_Bombs, Options &Options)
{
	if (GetAsyncKeyState(Options.Top_Walk) < 0 && (area[Player.coord_y - 1][Player.coord_x] == Unoccupied_area_model || area[Player.coord_y - 1][Player.coord_x] == Death_area_model) && area[Player.coord_y - 1][Player.coord_x] != "~")
	{
		Erase_player(area, Player, Inventory, Player_Bombs);
		if (area[Player.coord_y - 1][Player.coord_x] == Death_area_model)
		{
			Player.alive = false;
		}
		else
		{
			--Player.coord_y;
			Move_Player(Player);
			area[Player.coord_y][Player.coord_x] = Occupied_area_model;
		}
	}
	if (GetAsyncKeyState(Options.Bot_Walk) < 0 && (area[Player.coord_y + 1][Player.coord_x] == Unoccupied_area_model || area[Player.coord_y + 1][Player.coord_x] == Death_area_model) && area[Player.coord_y + 1][Player.coord_x] != "~")
	{
		Erase_player(area, Player, Inventory, Player_Bombs);
		if (area[Player.coord_y + 1][Player.coord_x] == Death_area_model)
		{
			Player.alive = false;
		}
		else
		{
			++Player.coord_y;
			Move_Player(Player);
			area[Player.coord_y][Player.coord_x] = Occupied_area_model;
		}
	}
	if (GetAsyncKeyState(Options.Left_Walk) < 0 && Player.coord_x - 3 > 0 && (area[Player.coord_y][Player.coord_x - 3] == Unoccupied_area_model || area[Player.coord_y][Player.coord_x - 3] == Death_area_model) && area[Player.coord_y][Player.coord_x - 1] != "|")
	{
		Erase_player(area, Player, Inventory, Player_Bombs);
		if (area[Player.coord_y][Player.coord_x - 3] == Death_area_model)
		{
			Player.alive = false;
		}
		else
		{
			Player.coord_x -= 3;
			Move_Player(Player);
			area[Player.coord_y][Player.coord_x] = Occupied_area_model;
		}
	}
	if (GetAsyncKeyState(Options.Right_Walk) < 0 && x_size - 2 > Player.coord_x + 2 && (area[Player.coord_y][Player.coord_x + 3] == Unoccupied_area_model || area[Player.coord_y][Player.coord_x + 3] == Death_area_model) && area[Player.coord_y][Player.coord_x + 1] != "|")
	{
		Erase_player(area, Player, Inventory, Player_Bombs);
		if (area[Player.coord_y][Player.coord_x + 3] == Death_area_model)
		{
			Player.alive = false;
		}
		else
		{
			Player.coord_x += 3;
			Move_Player(Player);
			area[Player.coord_y][Player.coord_x] = Occupied_area_model;
		}
	}
}
void Actions(std::vector<std::string>* area, Coordinate_of &Player1, Inventory &Inventory1, std::vector<Bombs_settings> &Player1_Bombs, Options &Options1, Coordinate_of &Player2, Inventory &Inventory2, std::vector<Bombs_settings> &Player2_Bombs, Options &Options2)
{
	if (_kbhit() && Player1.alive == true && Player2.alive == true)
	{
		Player_movement(area, Player1, Inventory1, Player1_Bombs, Options1);
		Player_plant_the_bomb(area, Player1, Inventory1, Options1);
		Player_movement(area, Player2, Inventory2, Player2_Bombs, Options2);
		Player_plant_the_bomb(area, Player2, Inventory2, Options2);
	}
}
void The_game(std::vector<std::string>* area, Coordinate_of &Player1, Inventory &Inventory1, std::vector<Bombs_settings> &Player1_Bombs, Options &Options1, Coordinate_of &Player2, Inventory &Inventory2, std::vector<Bombs_settings> &Player2_Bombs, Options &Options2, std::vector<Objects> &Immortal_walls, std::vector<Objects> &Destroyable_walls)
{
	Sleep(game_cicle_step_sleep);
	Actions(area, Player1, Inventory1, Player1_Bombs, Options1, Player2, Inventory2, Player2_Bombs, Options2);
	Bomb_explosion_time_check(area, Player1, Inventory1, Player1_Bombs, Options1, Player2, Inventory2, Player2_Bombs, Options2, Immortal_walls, Destroyable_walls);
}
void Create_area(std::vector<std::string>* area, Coordinate_of &Player1, Coordinate_of &Player2, std::vector<Objects> &Immortal_walls, std::vector<Objects> &Destroyable_walls, int &Destroyable_walls_counter)
{
	int Immortal_wall_number = 0; 
	for (int y = 0; y < y_size; ++y)
	{
		area[y].resize(x_size);
		int counter = 0;
		int n = 1;
		for (int x = 0; x < x_size; ++x)
		{
			if (counter == x_size - 1)
			{
				counter = 0;
				area[y][x] = '\n';
				++x;
			}
			if ((y == 0 || y == y_size - 1) && x < x_size - 1)
			{
				area[y][x] = '~';
				++counter;
			}
			if (y > 0 && y < y_size - 1)
			{
				if (x == Player1.coord_x + Player_width * Standard_generation_step_for_spawns && y == Player1.coord_y ||
					x == Player1.coord_x && y == Player1.coord_y + Standard_generation_step_for_spawns ||
					x == Player1.coord_x + Player_width * Standard_generation_step_for_spawns && y == Player2.coord_y||
					x == Player1.coord_x && y == Player2.coord_y - Standard_generation_step_for_spawns ||
					x == Player2.coord_x - Player_width*Standard_generation_step_for_spawns && y == Player1.coord_y ||
					x == Player2.coord_x && y == Player1.coord_y + Standard_generation_step_for_spawns ||
					x == Player2.coord_x - Player_width*Standard_generation_step_for_spawns && y == Player2.coord_y ||
					x == Player2.coord_x && y == Player2.coord_y - Standard_generation_step_for_spawns)
				{
					++n;
					area[y][x - 1] = '[';
					area[y][x] = Destroyable_wall;
					area[y][x + 1] = ']';
					Destroyable_walls[Destroyable_walls_counter].coord_y = y;
					Destroyable_walls[Destroyable_walls_counter].coord_x = x;
					Destroyable_walls[Destroyable_walls_counter].boon_inside = rand() % 2;
					Destroyable_walls[Destroyable_walls_counter].boon_active = true;
					Destroyable_walls[Destroyable_walls_counter].type_of_boon = (boon_class)(rand() % 3);
					++Destroyable_walls_counter;
					++x;
					++counter;
				}
				else
					if (x == 0 || x == x_size - 2)
					{
						area[y][x] = '|';
					}
					else
						if (x == 5 * n + (n - 1) && y % 2 == 0 && x + 1 < x_size && x!=0)
						{
							++n;
							area[y][x - 1] = '[';
							area[y][x] = Immortal_wall;
							area[y][x + 1] = ']';
							Immortal_walls[Immortal_wall_number].coord_y = y;
							Immortal_walls[Immortal_wall_number].coord_x = x;
							++Immortal_wall_number;
							++x;
							++counter;
						}
						else
							if (x < x_size - 1)
							{
								area[y][x] = ' ';
							}
				++counter;
			}
		}
	}
}
void Show_stats(Inventory &Inventory1, Inventory &Inventory2)
{
	gotoxy(0, y_size + 2);
	std::cout << "Stats: Player 1	Player 2\n";
	std::cout << "Range: " << Inventory1.Bomb_boom_range << "	" << Inventory2.Bomb_boom_range << '\n';
	std::cout << "Count: " << Inventory1.Bomb_counter - Inventory1.Planted_bomb_counter << "	" << Inventory2.Bomb_counter - Inventory2.Planted_bomb_counter;
}
void Fill_area_with_walls(std::vector <std::string> *area, std::vector<std::vector<int>> &gen1, std::vector<std::vector<int>> &gen2, std::vector<std::vector<int>> &gen3, std::vector<std::vector<int>>&gen4, std::vector<Objects> &Destroyable_walls, int & Destroyable_walls_counter)
{
	for (int i = 0, k = 0; i < gen1.size(); ++i)
	{
		gen1[i].resize(Gen1LineSize / Player_width);
		for (int j = 0; j < gen1[i].size(); ++j)
		{
			if (k < gen1_walls)
			{
				gen1[i][j] = rand() % 4;
				if (gen1[i][j] == 1)
				{
					area[1 + i * (y_size - 3)][j * Player_width + (2 + 2 * Player_width)] = Destroyable_wall;
					area[1 + i * (y_size - 3)][j * Player_width + (2 + 2 * Player_width) - 1] = "[";
					area[1 + i * (y_size - 3)][j * Player_width + (2 + 2 * Player_width) + 1] = "]";
					Destroyable_walls[Destroyable_walls_counter].coord_y = 1 + i * (y_size - 3);
					Destroyable_walls[Destroyable_walls_counter].coord_x = j * Player_width + (2 + 2* Player_width);
					Destroyable_walls[Destroyable_walls_counter].boon_inside = rand() % 2;
					Destroyable_walls[Destroyable_walls_counter].boon_active = true;
					Destroyable_walls[Destroyable_walls_counter].type_of_boon = (boon_class)(rand() % 3);
					++Destroyable_walls_counter;
					++k;
				}
			}
		}
	}
	for (int i = 0, k = 0; i < gen2.size(); ++i)
	{
		gen2[i].resize(Gen2LineSize / Player_width);
		for (int j = 0; j < gen2[i].size(); ++j)
		{
			if (k < gen2_walls)
			{
				gen2[i][j] = rand() % 4;
				if (gen2[i][j] == 1)
				{
					area[2 + i * (y_size - 4)][j * Player_width * 2 + (2 + 2 * Player_width)] = Destroyable_wall;
					area[2 + i * (y_size - 4)][j * Player_width * 2 + (2 + 2 * Player_width) - 1] = "[";
					area[2 + i * (y_size - 4)][j * Player_width * 2 + (2 + 2 * Player_width) + 1] = "]";
					Destroyable_walls[Destroyable_walls_counter].coord_y = 2 + i * (y_size - 4);
					Destroyable_walls[Destroyable_walls_counter].coord_x = j * Player_width * 2 + (2 + 2 * Player_width);
					Destroyable_walls[Destroyable_walls_counter].boon_inside = rand() % 2;
					Destroyable_walls[Destroyable_walls_counter].boon_active = true;
					Destroyable_walls[Destroyable_walls_counter].type_of_boon = (boon_class)(rand() % 3);
					++Destroyable_walls_counter;
					++k;
				}
			}
		}
	}
	for (int i = 0, k = 0; i < gen3.size(); ++i)
	{
		gen3[i].resize(Gen3LineSize / Player_width);
		for (int j = 0; j < gen3[i].size(); ++j)
		{
			if (k < gen3_walls)
			{
				gen3[i][j] = rand() % 3;
				if (gen3[i][j] == 1)
				{
					area[3 + 2 * i][j * Player_width + 2] = Destroyable_wall;
					area[3 + 2 * i][j * Player_width + 1] = "[";
					area[3 + 2 * i][j * Player_width + 3] = "]";
					++k;
				}
			}
		}
	}
	for (int i = 0, k = 0; i < gen4.size(); ++i)
	{
		gen4[i].resize(Gen4LineSize / Player_width);
		for (int j = 0; j < gen4[i].size(); ++j)
		{
			if (k < gen4_walls)
			{
				gen4[i][j] = rand() % 3;
				if (gen4[i][j] == 1)
				{
					area[4 + i * 2][2 * j * Player_width + 2] = Destroyable_wall;
					area[4 + i * 2][2 * j * Player_width + 1] = "[";
					area[4 + i * 2][2 * j * Player_width + 3] = "]";
					Destroyable_walls[Destroyable_walls_counter].coord_y = 4 + i * 2;
					Destroyable_walls[Destroyable_walls_counter].coord_x = 2 * j * Player_width + 2;
					Destroyable_walls[Destroyable_walls_counter].boon_inside = rand() % 2;
					Destroyable_walls[Destroyable_walls_counter].boon_active = true;
					Destroyable_walls[Destroyable_walls_counter].type_of_boon = (boon_class)(rand() % 3);
					++Destroyable_walls_counter;
					++k;
				}
			}
		}
	}
}
void Game_results(Coordinate_of Player1, Coordinate_of Player2)
{
	int Result;
	if (!(Player1.alive && Player2.alive))
	{
		Result = Tie;
	}
	if (Player1.alive && Player2.alive == false)
	{
		Result = Player_1_won;
	}
	if (Player1.alive == false && Player2.alive)
	{
		Result = Player_2_won;
	}
	switch (Result)
	{
	case Tie:
		SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
		std::cout << "It is a draw...\n";
		break;
	case Player_1_won:
		SetConsoleTextAttribute(handle, FOREGROUND_RED);
		std::cout << "First player won!\n";
		break;
	case Player_2_won:
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
		std::cout << "Second player won!\n";
		break;
	}
	ResetColor();
}

int main()
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	int key;
	time_t Aftergame_pause;
	do
	{

		std::vector<std::string> area[y_size];
		std::vector<std::vector<int>> walls_generation1, walls_generation2, walls_generation3, walls_generation4;
		walls_generation1.resize(Gen1_standard_size);
		walls_generation2.resize(Gen2_standard_size);
		int Destroyable_walls_counter = 0;

		int k = 0, j = 0;
		for (int i = 3; i < y_size - 3; i += 2)
		{
			++k;
		}
		for (int i = 4; i < y_size - 3; i += 2)
		{
			++j;
		}
		walls_generation3.resize(k);
		walls_generation4.resize(j);

		std::vector<Objects> Immortal_walls;
		Immortal_walls.resize(Number_of_immortal_walls);

		std::vector<Objects> Destroyable_walls;
		Destroyable_walls.resize(Number_of_destroyable_walls);

		Coordinate_of Player1;
		Player1.identification_number = 1;
		Player1.coord_x = 2;
		Player1.coord_y = 1;
		std::vector<Bombs_settings> Player1_Bombs;
		Options Options1;
		Options1.Left_Walk = 0x25; // Left arrow key code 
		Options1.Right_Walk = 0x27;// Right ....
		Options1.Top_Walk = 0x26;// Up
		Options1.Bot_Walk = 0x28;// Down
		Options1.Plant_Bomb = 0x4B; // K-key code
		Inventory Inventory1;
		Inventory1.Bomb_boom_range = 1;
		Inventory1.Bomb_counter = 1;

		Coordinate_of Player2;
		Player2.identification_number = 2;
		Player2.coord_x = x_size - 4;
		Player2.coord_y = y_size - 2;
		std::vector<Bombs_settings> Player2_Bombs;
		Options Options2;
		Options2.Left_Walk = 0x41; // A-key code
		Options2.Right_Walk = 0x44;// D-key 
		Options2.Top_Walk = 0x57;// W-key
		Options2.Bot_Walk = 0x53;// S-key
		Options2.Plant_Bomb = 0x46; // F-key code

		Inventory Inventory2;
		Inventory2.Bomb_boom_range = 1;
		Inventory2.Bomb_counter = 1;

		srand(time(0));


		Create_area(area, Player1, Player2, Immortal_walls, Destroyable_walls, Destroyable_walls_counter);
		Fill_area_with_walls(area, walls_generation1, walls_generation2, walls_generation3, walls_generation4, Destroyable_walls, Destroyable_walls_counter);
		Refresh_game_screen(area);
		Player1_Player2_started_pos(area, Player1, Player2);
		do
		{
			Boon_PickUp(Player1, Inventory1, Destroyable_walls);
			Boon_PickUp(Player2, Inventory2, Destroyable_walls);
			Player1_Bombs.resize(Inventory1.Bomb_counter);
			Player2_Bombs.resize(Inventory2.Bomb_counter);
			Show_stats(Inventory1, Inventory2);
			The_game(area, Player1, Inventory1, Player1_Bombs, Options1, Player2, Inventory2, Player2_Bombs, Options2, Immortal_walls, Destroyable_walls);
		} while (Player1.alive && Player2.alive);
		system("cls");
		Game_results(Player1, Player2);
		Aftergame_pause = time(0) + System_wait;
		std::cout << "Do you want to play again?\n	(ESC = No/Any key = Yes)";
		do
		{
			key = _getch();
		} while (Aftergame_pause > time(0));
	} while (key != ESC_BUTTON);
	return 0;
}