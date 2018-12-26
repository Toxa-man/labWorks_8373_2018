#include <iostream>
#include <conio.h>

using namespace std;

bool Game_Over;
const int width = 30;
const int height = 20;
int x, y, fruit_x, fruit_y, score;
int tailx[100], taily[100];
int tailN;
enum moovments { STOP = 0, LEFT, RIGHT, UP, DOWN };
moovments poop;


void presets() {
	Game_Over = false;
	poop = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	fruit_x = rand() % width - 1;
	fruit_y = rand() % height;
	score = 0;
}

void draw() {
	system("cls"); // очищает консоль
	for (int i = 0; i < width + 1; i++)
		cout << "-";
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)
				cout << "|";
			if (i == y && j == x)
				cout << "0";
			else if (i == fruit_y && j == fruit_x)
				cout << "F";
			else {
				bool pr = false;
				for (int k = 0; k < tailN; k++) {
					if (tailx[k] == j && taily[k] == i) {
						pr = true;
						cout << "o";
					}
				}
				if (!pr)
					cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width + 1; i++)
		cout << "-";
	cout << endl;
	cout << "Score: " << score << endl;
}

void input() {
	if (_kbhit()) { // проверяет нажатия клавиш 
		switch (_getch())
		{
		case 'a':
			poop = LEFT;
			break;
		case 'd':
			poop = RIGHT;
			break;
		case 'w':
			poop = UP;
			break;
		case 's':
			poop = DOWN;
			break;
		case 'x':
			Game_Over = true;
			break;
		}
	}
}

void dvizh() {
	int prev_x = tailx[0];
	int prev_y = taily[0];
	int prev2x, prev2y;
	tailx[0] = x;
	taily[0] = y;
	for (int i = 1; i < tailN; i++) {
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prev_x;
		taily[i] = prev_y;
		prev_x = prev2x;
		prev_y = prev2y;
	}
	switch (poop)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (x >= width - 1)
		x = 0;
	else if (x < 0)
		x = width - 2;
	if (y >= height)
		y = 0;
	else if (y < 0)
		y = height - 1;


	for (int i = 0; i < tailN; i++) {
		if (tailx[i] == x && taily[i] == y)
			Game_Over = true;
	}
	if (x == fruit_x && y == fruit_y) {
		score += 10;
		fruit_x = rand() % width - 1;
		fruit_y = rand() % height;
		tailN++;
	}
}

int main()
{
	presets();
	while (!Game_Over) {
		draw();
		input();
		dvizh();
	}

	system("cls");

	cout << "Game Over" << endl;
	cout << "Score: " << score << endl;
	system("pause");
	return 0;
}