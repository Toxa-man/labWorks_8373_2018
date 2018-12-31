#include "pch.h"
#include "Console.h"

int x = 10; //Your real position
int y = 20;
int x2;     //Your future position
int y2;     
int score = 0;
int hp = 3;
int heal = 10;


char map[map_size_height][map_size_width] = {
	"#####################",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#                   #",
	"#         ^         #" };

Console::Console()
{
}


Console::~Console()
{
}

void positionx(int y, int x)
{
	if (map[y - 1][x] == 'W')
	{
		map[y - 1][x] = ' ';
		hp--;
	}

	if (map[y - 1][x] == '+')
	{
		if (hp < 3)
		{
			hp++;
		}
		map[y - 1][x] = ' ';
	}

	if (map[y - 1][x] == '*')
	{
		map[y - 1][x] = ' ';
		score++;
	}
}


void Console::move(int V, int H)
{
	//int y2 = y + V;
	int x2 = x + H;
	


	if ((map[y][x2] == ' ') || (map[y][x2] == '*') || (map[y][x2]=='W') || (map[y][x2] == '+'))
	{
		map[y][x] = ' ';
		x += H;
		map[y][x] = '^';

		positionx(y, x);
	}		
}