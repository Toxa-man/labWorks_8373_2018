#include "stdafx.h"
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <windows.h>
#include <vector>
#include <string>
#undef main

enum bonus_type { statt, motion, crush, bonus };
enum checker_type { exitt, in_menu, in_game, in_settings };
const short right = 1, no_motion = 0, left = -1,
first_platform_index = 7,
second_platform_index = 8,
horisontal_speed = 7,
volume = 3,
upper_border = 150,
lower_border = 900;
const float increace = 1.5;

struct settings
{
	int type;
	int width;
	int direction;
};

void move_LEFT(SDL_Renderer* render, SDL_Texture* texture, SDL_Rect &destrect, int offset = horisontal_speed)
{
	destrect.x -= offset;
	SDL_RenderClear(render);
	SDL_RenderCopy(render, texture, NULL, &destrect);
}
void move_RIGHT(SDL_Renderer* render, SDL_Texture* texture, SDL_Rect &destrect, int offset = horisontal_speed)
{
	destrect.x += offset;
	SDL_RenderClear(render);
	SDL_RenderCopy(render, texture, NULL, &destrect);
}

void add_clone(SDL_Renderer* render, SDL_Rect player_RECT, SDL_Texture *player, SDL_Rect wall_RECT1, SDL_Rect wall_RECT2)
{
	if (player_RECT.x < wall_RECT1.w)
		player_RECT.x += wall_RECT2.x - wall_RECT1.w;
	else if ((player_RECT.x + player_RECT.w) > wall_RECT2.x)
		player_RECT.x -= wall_RECT2.x - wall_RECT1.w;
	SDL_RenderCopy(render, player, NULL, &player_RECT);
}

void render_add_walls(SDL_Renderer* render, SDL_Rect wall_RECT1, SDL_Rect wall_RECT2, SDL_Texture *wall)
{
	SDL_RenderCopy(render, wall, NULL, &wall_RECT1);
	SDL_RenderCopy(render, wall, NULL, &wall_RECT2);
}

void render_UPDATE(SDL_Renderer* render, std::vector<SDL_Texture*> &ARRAY_textures, std::vector<SDL_Rect*> &ARRAY_rect, std::vector<int> &ARRAY_texturesState)
{
	SDL_RenderClear(render);
	if (ARRAY_texturesState[0]) SDL_RenderCopy(render, ARRAY_textures[0], NULL, ARRAY_rect[0]);
	for (int i = 2; i < ARRAY_rect.size(); i++)
		if (ARRAY_texturesState[i]) SDL_RenderCopy(render, ARRAY_textures[i], NULL, ARRAY_rect[i]);
	if (ARRAY_texturesState[1]) SDL_RenderCopy(render, ARRAY_textures[1], NULL, ARRAY_rect[1]);
}

void render_UPDATE(SDL_Renderer* render, std::vector<SDL_Texture*> &ARRAY_textures, std::vector<SDL_Rect*> &ARRAY_rect, std::vector<int> &ARRAY_texturesState, int checker, SDL_Rect wall_RECT1, SDL_Rect wall_RECT2, SDL_Texture *wall, bool clone)
{
	SDL_RenderClear(render);
	if (ARRAY_texturesState[0]) SDL_RenderCopy(render, ARRAY_textures[0], NULL, ARRAY_rect[0]);
	for (int i = 2; i < ARRAY_rect.size(); i++)
	if (ARRAY_texturesState[i]) SDL_RenderCopy(render, ARRAY_textures[i], NULL, ARRAY_rect[i]);
	if (ARRAY_texturesState[1]) SDL_RenderCopy(render, ARRAY_textures[1], NULL, ARRAY_rect[1]);
	if (clone)
	add_clone(render, *ARRAY_rect[1], ARRAY_textures[1], wall_RECT1, wall_RECT2);
	if (checker == in_game)
	render_add_walls(render, wall_RECT1, wall_RECT2, wall);
}

void new_game(std::vector<SDL_Rect> &platform_RECT, SDL_Texture *platform[], int width, int height, int height_plat, SDL_Rect &player, SDL_Renderer *ren, std::vector<SDL_Texture*> &ARRAY_textures, std::vector<SDL_Rect*> &ARRAY_rect, std::vector<int> &ARRAY_texturesState, std::vector<settings> &platform_settings, SDL_Texture* background)
{
	srand(time(0));
	int first_plat_width;
	for (int n = 0; n < platform_RECT.size(); ++n)
	{
		platform_settings[n].width = 200 + rand() % 200;
		platform_settings[n].direction = no_motion;
		int random = rand() % 1000;
		if (random < 100)
			platform_settings[n].type = bonus;
		else
			if (random < 250)
				platform_settings[n].type = crush;
			else
				if (random < 500)
				{
					platform_settings[n].type = motion;
					if (rand() % 100 < 50)
						platform_settings[n].direction = right;
					else
						platform_settings[n].direction = left;
				}
				else
					platform_settings[n].type = statt;
		if (n == 0)
			platform_settings[n].type = statt;
		platform_RECT[n].x = width * 3 / 10 + rand() % (width * 2 / 5 - platform_settings[n].width);
		platform_RECT[n].y = height - 200 * (n + 1) - rand() % 100;
		platform_RECT[n].w = platform_settings[n].width;
		platform_RECT[n].h = height_plat;
		if (n == 0)
			SDL_RenderCopy(ren, background, NULL, &platform_RECT[n]);
		else
			SDL_RenderCopy(ren, platform[platform_settings[n].type], NULL, &platform_RECT[n]);
		ARRAY_textures.push_back(platform[platform_settings[n].type]);
		ARRAY_rect.push_back(&platform_RECT[n]);
		ARRAY_texturesState.push_back(1);
	}
	player.x = platform_RECT[0].x + (platform_settings[0].width - player.w) / 2;
	player.y = platform_RECT[0].y - player.h;	
}

void new_platform(std::vector<SDL_Rect> &platform_RECT, SDL_Texture *platform[], int width, int height, int height_plat, SDL_Renderer *ren, std::vector<SDL_Texture*> &ARRAY_textures, std::vector<SDL_Rect*> &ARRAY_rect, std::vector<int> &ARRAY_texturesState, std::vector<settings> &platform_settings)
{
	platform_RECT.resize(platform_RECT.size() + 1);
	platform_settings.resize(platform_settings.size() + 1);
	platform_settings[platform_settings.size() - 1].width = 200 + rand() % 200;
	platform_settings[platform_settings.size() - 1].direction = no_motion;
	int random = rand() % 1000;
	if (random < 100)
		platform_settings[platform_RECT.size() - 1].type = bonus;
	else
		if (random < 250)
			platform_settings[platform_RECT.size() - 1].type = crush;
		else
			if (random < 500)
			{
				platform_settings[platform_RECT.size() - 1].type = motion;
				if (rand() % 100 < 50)
					platform_settings[platform_RECT.size() - 1].direction = right;
				else
					platform_settings[platform_RECT.size() - 1].direction = left;
			}
			else
				platform_settings[platform_RECT.size() - 1].type = statt;
	platform_RECT[platform_RECT.size() - 1].x = width * 3 / 10 + rand() % (width * 2 / 5 - platform_settings[platform_settings.size() - 1].width);
	platform_RECT[platform_RECT.size() - 1].y = -height_plat;
	platform_RECT[platform_RECT.size() - 1].w = platform_settings[platform_settings.size() - 1].width;
	platform_RECT[platform_RECT.size() - 1].h = height_plat;
	SDL_RenderCopy(ren, platform[platform_settings[platform_RECT.size() - 1].type], NULL, &platform_RECT[platform_RECT.size() - 1]);
	ARRAY_textures.push_back(platform[platform_settings[platform_RECT.size() - 1].type]);
	for (int i = 0; i < (platform_RECT.size()-1); ++i)
	{
		ARRAY_rect[i + first_platform_index] = &platform_RECT[i];
	}
	ARRAY_rect.push_back(&(platform_RECT[platform_RECT.size() - 1]));
	ARRAY_texturesState.push_back(1);
}

void platform_delete(std::vector<SDL_Rect> &platform_RECT, std::vector<SDL_Texture*> &ARRAY_textures, std::vector<SDL_Rect*> &ARRAY_rect, std::vector<int> &ARRAY_texturesState, std::vector<settings> &platform_settings, int place)
{
	platform_settings.erase(platform_settings.begin() + place);
	platform_RECT.erase(platform_RECT.begin() + place);
	for (int i = place; i < (platform_RECT.size()); ++i)
	{
	ARRAY_textures[i + first_platform_index] = ARRAY_textures[i + second_platform_index];
	ARRAY_texturesState[i + first_platform_index] = ARRAY_texturesState[i + second_platform_index];
	ARRAY_rect[i + first_platform_index] = &platform_RECT[i];
	}
	ARRAY_textures.erase(ARRAY_textures.end() - 1);
	ARRAY_rect.erase(ARRAY_rect.end() - 1);
	ARRAY_texturesState.erase(ARRAY_texturesState.end() - 1);
}

void game_settings(std::vector<int> &ARRAY_texturesState, SDL_Renderer *ren, int menu_differ, int width, int height, std::vector<SDL_Texture*> &ARRAY_textures, std::vector<SDL_Rect*> &ARRAY_rect, Mix_Music *gMusic)
{
	SDL_Texture *backgrounds[5] = { IMG_LoadTexture(ren, "background1.png"), IMG_LoadTexture(ren, "background2.png"), IMG_LoadTexture(ren, "background3.png"), IMG_LoadTexture(ren, "background4.png"), IMG_LoadTexture(ren, "background5.png"), };
	SDL_Texture *players[5] = { IMG_LoadTexture(ren, "player.bmp"), IMG_LoadTexture(ren, "11.png"), IMG_LoadTexture(ren, "mario.png"), IMG_LoadTexture(ren, "haski.png"), IMG_LoadTexture(ren, "pepe.png"), };
	Mix_Music *gMusics[5] = { Mix_LoadMUS("bensound-summer.mp3"), Mix_LoadMUS("bensound-dubstep.mp3"), Mix_LoadMUS("bensound-endlessmotion.mp3"), Mix_LoadMUS("bensound-erf.mp3"), Mix_LoadMUS("bensound-house.mp3") };
	ARRAY_texturesState = { 1,1,0,1,1,1,1 };

	menu_differ = height * 0.1;
	SDL_Rect* player_RECT = ARRAY_rect[1];
	SDL_Rect* menu_play_RECT = ARRAY_rect[3];
	SDL_Rect* menu_settings_RECT = ARRAY_rect[4];
	SDL_Rect* menu_exit_RECT = ARRAY_rect[5];
	SDL_Rect* choose_RECT = ARRAY_rect[6];
	SDL_Texture* choose = ARRAY_textures[6];

	menu_play_RECT->w = 600;
	menu_play_RECT->h = 100;
	menu_play_RECT->x = (width - menu_play_RECT->w) / 2;
	menu_play_RECT->y = height * 0.4;

	menu_settings_RECT->w = menu_play_RECT->w;
	menu_settings_RECT->h = menu_play_RECT->h;
	menu_settings_RECT->x = menu_play_RECT->x;
	menu_settings_RECT->y = menu_play_RECT->y + menu_differ;

	menu_exit_RECT->w = menu_play_RECT->w;
	menu_exit_RECT->h = menu_play_RECT->h;
	menu_exit_RECT->x = menu_play_RECT->x;
	menu_exit_RECT->y = menu_settings_RECT->y + menu_differ;

	choose_RECT->w = 40;
	choose_RECT->h = 40;
	choose_RECT->x = menu_play_RECT->x - choose_RECT->w - 20;
	choose_RECT->y = menu_play_RECT->y + (menu_play_RECT->h - choose_RECT->h) / 2;
	
	player_RECT->w = 200;
	player_RECT->h = 200;
	player_RECT->x = (width - player_RECT->w)/2;
	player_RECT->y = menu_play_RECT->y - 300;

	ARRAY_textures[3] = IMG_LoadTexture(ren, "change_background.png");
	ARRAY_textures[4] = IMG_LoadTexture(ren, "change_player.png");
	ARRAY_textures[5] = IMG_LoadTexture(ren, "change_music.png");

	bool quit = false;
	SDL_Event event;
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	int menu_state = 0;
	int i = 0, j = 0, k = 0;

	while (!quit)
	{
		int sleep = false;
		while (SDL_PollEvent(&event))
		{
			SDL_PumpEvents(); // обработчик событий.
		}
		if ((keyboardState[SDL_SCANCODE_UP]) || (keyboardState[SDL_SCANCODE_W]))
		{
			menu_state = (menu_state + 2) % 3;
			sleep = true;
		}
		else if ((keyboardState[SDL_SCANCODE_DOWN]) || (keyboardState[SDL_SCANCODE_S]))
		{
			menu_state = (menu_state + 1) % 3;
			sleep = true;
		}
		choose_RECT->y = menu_play_RECT->y + (menu_play_RECT->h - choose_RECT->h) / 2 + menu_differ*menu_state;
		SDL_RenderClear(ren);
		if (keyboardState[SDL_SCANCODE_RETURN])
			switch (menu_state)
			{
			case 0:
				i = (i + 1) % 5;
				ARRAY_textures[0] = backgrounds[i];
				sleep = true;
				break;
			case 1:
				j = (j + 1) % 5;
				ARRAY_textures[1] = players[j];
				sleep = true;
				break;
			case 2:
				k = (k + 1) % 5;
				Mix_HaltMusic();
				gMusic = gMusics[k];
				Mix_PlayMusic(gMusic, -1);
				Sleep(200);
				break;
			}
		render_UPDATE(ren, ARRAY_textures, ARRAY_rect, ARRAY_texturesState); //Написанная нами функция обновления рендера
		
		SDL_Rect warning_RECT;
		warning_RECT.w = 600;
		warning_RECT.h = 200;
		warning_RECT.x = (width - warning_RECT.w) / 2;
		warning_RECT.y = menu_exit_RECT->y - 250;
		SDL_Texture* warning = IMG_LoadTexture(ren, "warning.png");

		SDL_RenderCopy(ren, warning, NULL, &warning_RECT);
		SDL_RenderPresent(ren);
		if (keyboardState[SDL_SCANCODE_ESCAPE])
			return;
		if (sleep) Sleep(200);
	}
}

void game(SDL_Event &event, SDL_Renderer* ren, std::vector<SDL_Rect> &platform_RECT, SDL_Texture *platform[], SDL_Rect &player_RECT, std::vector<SDL_Texture*> &ARRAY_textures, std::vector<SDL_Rect*> &ARRAY_rect, std::vector<int> &ARRAY_texturesState, int &checker, SDL_Rect wall_RECT1, SDL_Rect wall_RECT2, SDL_Texture *wall, std::vector<settings> &platform_settings, int &up, int &plat_place, float &player_speed, float &player_acceleration, const int height_plat, SDL_Texture* player, int &sleep_time, int player_acceleration_const, int &jump_height, int &speed, SDL_DisplayMode displayMode, Mix_Chunk *gJump, const Uint8 *keyboardState = SDL_GetKeyboardState(NULL))
{
	bool clone = false;
	while (SDL_PollEvent(&event))
	{
		SDL_PumpEvents(); // обработчик событий.
	}
	if (event.type == SDL_QUIT)
		checker = 0;

	int decr = true;
	for (int i = 0; i < platform_RECT.size(); i++)
		if (((platform_RECT[i].y - player_RECT.h) == player_RECT.y) && ((platform_RECT[i].x - player_RECT.w) <= player_RECT.x) && ((platform_RECT[i].x + platform_settings[i].width) >= player_RECT.x) && !up)
		{
			decr = false;
			plat_place = i;
			break;
		}

	if (decr && !up)
	{
		bool check = true;
		for (int i = 0; i < platform_RECT.size(); i++)
			if (((platform_RECT[i].y - player_RECT.h) < (player_RECT.y + player_speed)) && (platform_RECT[i].y >= player_RECT.y + player_RECT.h) && ((platform_RECT[i].x - player_RECT.w) <= player_RECT.x) && ((platform_RECT[i].x + platform_settings[i].width) >= player_RECT.x))
			{
				player_RECT.y = platform_RECT[i].y - player_RECT.h;
				check = false;
				break;
			}
		if (check)
		{
			player_RECT.y += player_speed;
			player_speed++;
		}
	}

	if (up >= 1)
	{
		up--;
		if (player_RECT.y >= upper_border)
		{
			if (plat_place)
				player_RECT.y -= player_speed * (player_RECT.y - upper_border) / (lower_border - upper_border);
			else
				player_RECT.y -= player_speed;
			player_speed -= player_acceleration;
		}
	}

	if (!decr && !up && !sleep_time)
	{
		player_acceleration = player_acceleration_const;
		up = sqrt(jump_height * 2 / player_acceleration);
		player_speed = up * player_acceleration;
		if (plat_place >= 0)
			if (platform_settings[plat_place].type == bonus)
			{
				player_speed *= increace;
				player_acceleration *= increace;
				plat_place = -1;
			}
		player_RECT.y -= player_speed;
		if (plat_place >= 0)
			if (platform_settings[plat_place].type == crush)
			{
				platform_delete(platform_RECT, ARRAY_textures, ARRAY_rect, ARRAY_texturesState, platform_settings, plat_place);
				plat_place = -1;
			}
		Mix_PlayChannelTimed(-1, gJump, 0, -1);
	}

	if (((keyboardState[SDL_SCANCODE_RIGHT]) || (keyboardState[SDL_SCANCODE_D])) && !sleep_time)
		move_RIGHT(ren, player, player_RECT);

	if (((keyboardState[SDL_SCANCODE_LEFT]) || (keyboardState[SDL_SCANCODE_A])) && !sleep_time)
		move_LEFT(ren, player, player_RECT);

	if (keyboardState[SDL_SCANCODE_ESCAPE])
		checker = 1;

	if (!sleep_time && up && (((player_RECT.y <= lower_border) && plat_place) || (player_RECT.y <= (upper_border + jump_height))))
		for (int i = 0; i < platform_RECT.size(); ++i)
		{
			platform_RECT[i].y += player_speed*(lower_border - player_RECT.y) / (lower_border - upper_border);
		}

	for (int i = 0; i < platform_settings.size(); ++i)
	{
		if ((((platform_RECT[i].x + platform_settings[i].width) > displayMode.w*0.7) || (platform_RECT[i].x < displayMode.w * 0.3)) && (platform_settings[i].type == motion))
			platform_settings[i].direction *= -1;
		if (platform_settings[i].type == motion)
		{
			platform_RECT[i].x += speed*platform_settings[i].direction;
		}
	}
	if (platform_RECT[0].y > displayMode.h)
		platform_delete(platform_RECT, ARRAY_textures, ARRAY_rect, ARRAY_texturesState, platform_settings, 0);
	int rand_height = 100 + rand() % 100;
	rand_height += rand() % 100;
	if (platform_RECT[platform_RECT.size() - 1].y > rand_height)
		new_platform(platform_RECT, platform, displayMode.w, displayMode.h, height_plat, ren, ARRAY_textures, ARRAY_rect, ARRAY_texturesState, platform_settings);
	if ((player_RECT.x + player_RECT.w - 1) <= wall_RECT1.w)
		player_RECT.x += wall_RECT2.x - wall_RECT1.w;
	else if (player_RECT.x >= wall_RECT2.x)
		player_RECT.x -= wall_RECT2.x - wall_RECT1.w;
	if ((player_RECT.x < wall_RECT1.w) || ((player_RECT.x + player_RECT.w) > wall_RECT2.x))
		clone = true;

	if (player_RECT.y >= displayMode.h)
		checker = in_menu;

	render_UPDATE(ren, ARRAY_textures, ARRAY_rect, ARRAY_texturesState, checker, wall_RECT1, wall_RECT2, wall, clone);
	SDL_RenderPresent(ren);
	if (sleep_time)
		sleep_time--;
}

int main()
{
	SDL_DisplayMode displayMode;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	int request = SDL_GetDesktopDisplayMode(0, &displayMode);
	SDL_Window *win = SDL_CreateWindow("Boodle Jump", 0, 0, displayMode.w, displayMode.h, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Rect player_RECT;
	player_RECT.x = 0;   //Смещение полотна по Х
	player_RECT.y = 0;   //Смещение полотна по Y
	player_RECT.w = 70; //Ширина полотна
	player_RECT.h = 70; //Высота полотна

	SDL_Rect background_RECT;
	background_RECT.x = 0;
	background_RECT.y = 0;
	background_RECT.w = displayMode.w;
	background_RECT.h = displayMode.h;

	SDL_Rect logo_RECT;
	logo_RECT.w = 800;
	logo_RECT.h = 300;
	logo_RECT.x = (displayMode.w - logo_RECT.w) / 2;
	logo_RECT.y = displayMode.h * 0.2;

	int menu_differ = displayMode.h * 0.1;

	SDL_Rect menu_play_RECT;
	menu_play_RECT.w = 600;
	menu_play_RECT.h = 50;
	menu_play_RECT.x = (displayMode.w - menu_play_RECT.w) / 2;
	menu_play_RECT.y = displayMode.h * 0.6;

	SDL_Rect menu_settings_RECT;
	menu_settings_RECT.w = menu_play_RECT.w;
	menu_settings_RECT.h = menu_play_RECT.h;
	menu_settings_RECT.x = menu_play_RECT.x;
	menu_settings_RECT.y = menu_play_RECT.y + menu_differ;

	SDL_Rect menu_exit_RECT;
	menu_exit_RECT.w = menu_play_RECT.w;
	menu_exit_RECT.h = menu_play_RECT.h;
	menu_exit_RECT.x = menu_play_RECT.x;
	menu_exit_RECT.y = menu_settings_RECT.y + menu_differ;

	SDL_Rect choose_RECT;
	choose_RECT.w = 40;
	choose_RECT.h = 40;
	choose_RECT.x = menu_play_RECT.x - choose_RECT.w - 20;
	choose_RECT.y = menu_play_RECT.y + (menu_play_RECT.h - choose_RECT.h) / 2;

	SDL_Rect wall_RECT1;
	wall_RECT1.h = displayMode.h;
	wall_RECT1.w = displayMode.w*0.28;
	wall_RECT1.x = 0;
	wall_RECT1.y = 0;

	SDL_Rect wall_RECT2;
	wall_RECT2.h = displayMode.h;
	wall_RECT2.w = displayMode.w*0.28;
	wall_RECT2.x = displayMode.w*0.72;
	wall_RECT2.y = 0;

	std::vector<SDL_Rect> platform_RECT;

	SDL_Texture *player = IMG_LoadTexture(ren, "player.bmp");
	SDL_Texture *background = IMG_LoadTexture(ren, "background1.png");
	SDL_Texture *logo = IMG_LoadTexture(ren, "logo.png");
	SDL_Texture *menu_play = IMG_LoadTexture(ren, "new_game.png");
	SDL_Texture *menu_settings = IMG_LoadTexture(ren, "settings.png");
	SDL_Texture *menu_exit = IMG_LoadTexture(ren, "exit.png");
	SDL_Texture *choose = IMG_LoadTexture(ren, "check.png");
	SDL_Texture *wall = IMG_LoadTexture(ren, "wall.bmp");
	SDL_Texture *platform[4] = { IMG_LoadTexture(ren, "11.png"), IMG_LoadTexture(ren, "platform_motion.png"), IMG_LoadTexture(ren, "crush.png"), IMG_LoadTexture(ren, "platform_bonus.png") };

	SDL_RenderClear(ren); //Очистка рендера
	SDL_RenderCopy(ren, background, NULL, &background_RECT); //Копируем в рендер фон
	SDL_RenderCopy(ren, logo, NULL, &logo_RECT);
	SDL_RenderCopy(ren, menu_play, NULL, &menu_play_RECT);
	SDL_RenderCopy(ren, menu_settings, NULL, &menu_settings_RECT);
	SDL_RenderCopy(ren, menu_exit, NULL, &menu_exit_RECT);
	SDL_RenderCopy(ren, choose, NULL, &choose_RECT);
	SDL_RenderPresent(ren); //Погнали!!

	//Музыка громче, глаза закрыты

	Mix_Music *gMusic = NULL;
	Mix_Chunk *gJump = NULL;
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return 1;
	}
	gMusic = Mix_LoadMUS("bensound-summer.mp3");
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		return 223;
	}
	gJump = Mix_LoadWAV("jump.wav");
	if (gJump == NULL)
	{
		printf("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		return 223;
	}
	Mix_VolumeMusic(volume);
	Mix_VolumeChunk(gJump, volume*20);
	Mix_PlayMusic(gMusic, -1);

	//Старт изменений

	const int height_plat = 20;
	int speed = 1;
	SDL_Event event;
	bool sleep = false;
	int checker = in_menu;
	std::vector<SDL_Texture*> ARRAY_textures;
	std::vector<SDL_Rect*> ARRAY_rect;
	std::vector<int> ARRAY_texturesState;
	std::vector<settings> platform_settings(displayMode.h / 200);
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	int menu_state = exitt;
	ARRAY_textures = { background, player, logo, menu_play, menu_settings, menu_exit, choose };
	ARRAY_rect = { &background_RECT, &player_RECT, &logo_RECT, &menu_play_RECT, &menu_settings_RECT, &menu_exit_RECT, &choose_RECT };

	while (checker)
	{
		platform_RECT.resize(displayMode.h / 200);
		platform_settings.resize(displayMode.h / 200);
		ARRAY_textures.resize(7);
		ARRAY_rect.resize(7);
		ARRAY_texturesState = { 1,0,1,1,1,1,1 };
		menu_play_RECT.w = 600;
		menu_play_RECT.h = 50;
		menu_play_RECT.x = (displayMode.w - menu_play_RECT.w) / 2;
		menu_play_RECT.y = displayMode.h * 0.6;

		menu_settings_RECT.w = menu_play_RECT.w;
		menu_settings_RECT.h = menu_play_RECT.h;
		menu_settings_RECT.x = menu_play_RECT.x;
		menu_settings_RECT.y = menu_play_RECT.y + menu_differ;

		menu_exit_RECT.w = menu_play_RECT.w;
		menu_exit_RECT.h = menu_play_RECT.h;
		menu_exit_RECT.x = menu_play_RECT.x;
		menu_exit_RECT.y = menu_settings_RECT.y + menu_differ;

		choose_RECT.w = 40;
		choose_RECT.h = 40;
		choose_RECT.x = menu_play_RECT.x - choose_RECT.w - 20;
		choose_RECT.y = menu_play_RECT.y + (menu_play_RECT.h - choose_RECT.h) / 2;

		player_RECT.w = 70;
		player_RECT.h = 70;

		ARRAY_textures[2] = IMG_LoadTexture(ren, "logo.png");
		ARRAY_textures[3] = IMG_LoadTexture(ren, "new_game.png");
		ARRAY_textures[4] = IMG_LoadTexture(ren, "settings.png");
		ARRAY_textures[5] = IMG_LoadTexture(ren, "exit.png");
		while (checker == in_menu)
		{
			sleep = false;
			while (SDL_PollEvent(&event))
			{
				SDL_PumpEvents(); // обработчик событий.
			}
			if ((keyboardState[SDL_SCANCODE_UP]) || (keyboardState[SDL_SCANCODE_W]))
			{
				menu_state = (menu_state + 2) % 3;
				sleep = true;
			}
			else if ((keyboardState[SDL_SCANCODE_DOWN]) || (keyboardState[SDL_SCANCODE_S]))
			{
				menu_state = (menu_state + 1) % 3;
				sleep = true;
			}
			choose_RECT.y = menu_play_RECT.y + (menu_play_RECT.h - choose_RECT.h) / 2 + menu_differ*menu_state;
			SDL_RenderClear(ren);
			SDL_RenderCopy(ren, choose, NULL, &choose_RECT);
			if (keyboardState[SDL_SCANCODE_RETURN])
				checker = (2 + menu_state) % 4;
			render_UPDATE(ren, ARRAY_textures, ARRAY_rect, ARRAY_texturesState, 1, wall_RECT1, wall_RECT2, wall, 0);
			SDL_RenderPresent(ren);
			if (sleep) Sleep(200);
		}
		if (!checker) break;
		if (checker == in_settings)
		{
			game_settings(ARRAY_texturesState, ren, menu_differ, displayMode.w, displayMode.h, ARRAY_textures, ARRAY_rect, gMusic);
			checker = in_menu;
		}
		if (checker == in_game)
		ARRAY_texturesState[1] = 1;
		for (int i = 2; i < first_platform_index; i++)
			ARRAY_texturesState[i] = 0;
		new_game(platform_RECT, platform, displayMode.w, displayMode.h, height_plat, player_RECT, ren, ARRAY_textures, ARRAY_rect, ARRAY_texturesState, platform_settings, background);
		int up = 0;
		int sleep = 0;
		int plat_place = -1;
		int player_speed_const = 5;
		float player_speed = player_speed_const;
		int jump_height = 300;
		int player_acceleration_const = 1;
		float player_acceleration = player_acceleration_const;
		int sleep_time = 100;
		while (checker == in_game)
			game(event, ren, platform_RECT, platform, player_RECT, ARRAY_textures, ARRAY_rect, ARRAY_texturesState, checker, wall_RECT1, wall_RECT2, wall, platform_settings, up, plat_place, player_speed, player_acceleration, height_plat, player, sleep_time, player_acceleration_const, jump_height, speed, displayMode, gJump);
	}
	Mix_FreeMusic(gMusic);
	Mix_FreeChunk(gJump);
	gMusic = NULL;
	SDL_DestroyTexture(player);
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(logo);
	SDL_DestroyTexture(menu_play);
	SDL_DestroyTexture(menu_settings);
	SDL_DestroyTexture(menu_exit);
	SDL_DestroyTexture(choose);
	SDL_DestroyTexture(wall);
	SDL_DestroyTexture(background);
	for (int i = 0; i < 4; ++i)
		SDL_DestroyTexture(platform[i]);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
	return 1;
}