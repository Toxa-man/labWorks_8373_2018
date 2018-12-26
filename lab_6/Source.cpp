#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

bool GameOver, Quit;
const int WIDTH = 40;
const int HEIGHT = 20;
int head_x, head_y, fruit_x, fruit_y, score, snake_size;
int snake_x[100], snake_y[100];
enum movements {STOP, LEFT, RIGHT, UP, DOWN};
movements way;

void StartScreen()
{
	system("cls");
	cout << endl << "МЕНЮ ИГРЫ ЗМЕЙКА";
	cout << endl << endl << "Нажмите 's' чтобы <<Начать игру>>";
	cout << endl << endl << "В игре нажмите 'x' чтобы <<Вернуться в меню>>";
	cout << endl << endl << "Нажмите 'q' чтобы <<Выйти из игры>>";
	cout << endl << endl << "Счет прошлой игры: " << score << endl << endl;
}

void FruitSpawn()
{
	fruit_x = rand() % WIDTH;
	fruit_y = rand() % HEIGHT;
}

void StartGame()
{
	GameOver = false;
	Quit = false;
	way = UP;
	head_x = WIDTH / 2;
	head_y = HEIGHT / 2;
	FruitSpawn();
	score = 0;
	snake_size = 3;
}

void Draw()
{
	system("cls");
	for (int i = 0; i < WIDTH + 2; i++) {
		cout << " ";
	}
	cout << endl;

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0)
				cout << "|";

			if (i == head_y && j == head_x) {
				if (way==LEFT)
					cout << "<";
				else if (way == RIGHT)
					cout << ">";
				else if (way == UP)
					cout << "A";
				else 
					cout << "V";
			}

			else if (i == fruit_y && j == fruit_x)
				cout << "6";

			else {
				bool print_check = false;
				for (int k = 0; k < snake_size; k++) {
					if (snake_x[k] == j && snake_y[k] == i) {
						cout << "o";
						print_check = true;
					}
				}
				if (!print_check)
					cout << " ";
			}

			if (j == WIDTH - 1)
				cout << "|";
		}
		cout << endl;
	}

	for (int i = 0; i < WIDTH + 2; i++) {
		cout << " ";
	}
	cout << endl;
	cout << "Счет: " << score << endl;
}

void Input()
{
	if (_kbhit()) {
		switch (_getch())
		{
		case 'a':
			if (way != RIGHT) way = LEFT;
			break;
		case 'w':
			if (way != DOWN) way = UP;
			break;
		case 's':
			if (way != UP) way = DOWN;
			break;
		case 'd':
			if (way != LEFT) way = RIGHT;
			break;
		case 'x':
			GameOver = true;
			break;
		}
	}
}

void Logic()
{
	int previous_x = snake_x[0];
	int previous_y = snake_y[0];
	int temp_x, temp_y;
	snake_x[0] = head_x;
	snake_y[0] = head_y;

	for (int i = 1; i < snake_size; i++) {
		temp_x = snake_x[i];
		temp_y = snake_y[i];
		snake_x[i] = previous_x;
		snake_y[i] = previous_y;
		previous_x = temp_x;
		previous_y = temp_y;

	}

	switch (way)
	{
	case LEFT:
		head_x--;
		break;
	case RIGHT:
		head_x++;
		break;
	case UP:
		head_y--;
		break;
	case DOWN:
		head_y++;
		break;
	}

	if (head_x > WIDTH || head_x < 0) {
		GameOver = true;
		StartScreen();
	}
	if (head_y < 0) head_y +=HEIGHT;
	if (head_y >= HEIGHT) head_y -= HEIGHT;
	
	for (int i = 0; i < snake_size; i++) {
		if (snake_x[i] == head_x && snake_y[i] == head_y)
			GameOver = true;
	}

	if (head_x == fruit_x && head_y == fruit_y) {
		score++;
		snake_size++;
		FruitSpawn();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	do {
		StartScreen();
		string input;
		cin >> input;
		if (input == "s")
		{
			StartGame();
			while (!GameOver)
			{
				Draw();
				Input();
				Logic();
				Sleep(75);
			}
		}
		else if (input == "q")
			Quit = true;
	} while (Quit == false);
}