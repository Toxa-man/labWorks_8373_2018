#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

bool gameover;
const int width = 30;
const int height =15;
int x, y, pointx, pointy, score;
int tailx[100], taily[100];
int longtail;
enum edit { stop = 0, lefti, righti, up, down };
edit ewq;
void Setup() {
	gameover = false;
	ewq = stop;
	x = width / 2 - 1;
	y = height / 2 - 1;
	pointx = rand() % width;
	pointy = rand() % height;
	score = 0;
}

void Draw() {
	system("cls");
	for (int i = 0; i < width + 1; i++)
		cout << "H";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
				cout << "H";
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
		cout << "H";
	cout << endl;
	cout << "score:" << score << endl;
	
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
	if (x >= width || x < 0 || y >= height || y < 0)
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
	srand(time(0));
	Setup();
	while (!gameover) {
		Draw();
		Input();
		Logic();
	}
	return 0;
}