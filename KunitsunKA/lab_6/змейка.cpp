#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h> 
using namespace std;

bool gameover;
const int width = 40;
const int height = 20;
int x, y, pointx, pointy, score;
int tailx[100], taily[100];
int longtail;
enum edit { stop = 0, lefti, righti, up, down };
edit ewq;
void setcur(int x, int y) 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Setup() 
{
	gameover = false;
	ewq = stop;
	x = width / 2 - 1;
	y = height / 2 - 1;
	pointx = rand() % width;
	pointy = rand() % height;
	score = 0;
}
void Draw()
{
	setcur(0, 0);
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			else if (i == pointy && j == pointx)
				cout << "+";
			else
			{
				bool print = false;
				for (int k = 0; k < longtail; k++)
				{
					if (tailx[k] == j && taily[k] == i)
					{
						print = true;
						cout << "o";
					}
				}
				if (!print)
					cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width + 1; i++)
		cout << "#";
	cout << endl;
	cout << "score:" << score << endl;
	cout << "Нажмите пробел, если хотите закончить игру" << endl;
}
void Input() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			ewq = up;
			break;
		case 's':
			ewq = down;
			break;
		case 'a':
			ewq = lefti;
			break;
		case'd':
			ewq = righti;
			break;
		case' ':
			gameover = true;
			break;
		}
	}
}
void Logic() {
	int prevx = tailx[0];
	int prevy = taily[0];
	int prev2x, prev2y;
	tailx[0] = x;
	taily[0] = y;
	for (int i = 1; i < longtail; i++)
	{
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	switch (ewq)
	{
	case lefti:
		x--;
		break;
	case righti:
		x++;
		break;
	case up:
		y--;
		break;
	case down:
		y++;
		break;
	}
	if (x >= width-1 || x < 0 || y >= height || y < 0)
		gameover = true;
	for (int i = 0; i < longtail; i++)
	{
		if (tailx[i] == x && taily[i] == y)
			gameover = true;
	}
	if (x == pointx && y == pointy)
	{
		score += 1;
		pointx = rand() % width;
		pointy = rand() % height;
		longtail++;
	}
}
int main()
{
	setlocale(0, "");
	srand(time(0));
	Setup();
	while (!gameover) {
		Draw();
		Input();
		Logic();
		Sleep(75);
	}
	return 0;
}