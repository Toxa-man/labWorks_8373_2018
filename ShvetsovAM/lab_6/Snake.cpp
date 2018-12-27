#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>

const int width = 75, height = 20;

using namespace std;

enum moves
{
	STOP = 0,
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
};
moves moveSnake;

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Color(ConsoleColor text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Title()
{
	Color(LightRed, Black);
	cout << "                       _______..__   __.      ___       __  ___  _______ " << endl
		<< "                      /       ||  \\ |  |     /   \\     |  |/  / |   ____|" << endl
		<< "                     |   (----`|   \\|  |    /  ^  \\    |  '  /  |  |__   " << endl
		<< "                      \\   \\    |  . `  |   /  /_\\  \\   |    <   |   __|  " << endl
		<< "                  .----)   |   |  |\\   |  /  _____  \\  |  .  \\  |  |____ " << endl
		<< "                  |_______/    |__| \\__| /__/     \\__\\ |__|\\__\\ |_______|" << endl;
}

void Menu()
{
	Color(White, Black);
	gotoxy(41, 12);
	cout << "1. START GAME";
	gotoxy(43, 14);
	cout << "2. QUIT";
	gotoxy(27, 28);
	Color(LightCyan, Black);
	cout << "Made by LETI's student Aleksandr Shvetsov";
	gotoxy(47, 2);
}

void MenuSpeed()
{
	Color(White, Black);
	gotoxy(37, 12);
	cout << "CHOOSE THE DIFFICULTY";
	gotoxy(41, 14);
	cout << "1. BEGINNER";
	gotoxy(41, 16);
	cout << "2. HARDCORE";
	gotoxy(43, 18);
	cout << "3. QUIT";
}

void Map(int shiftX, int shiftY)
{
	system("cls");
	Color(LightCyan, Black);
	int x;
	gotoxy(shiftX - 1, shiftY - 1);
	cout << char(218);
	for (x = 0; x < width; x++)
	{
		cout << char(196);
	}
	cout << char(191);

	for (x = 0; x < height; x++)
	{
		gotoxy(shiftX - 1, x + 2);
		cout << char(179);
		gotoxy(width + shiftX, x + 2);
		cout << char(179);
	}
	gotoxy(shiftX - 1, height + shiftY);
	cout << char(192);
	for (x = 0; x < width; x++)
	{
		cout << char(196);
	}
	cout << char(217);
	Color(White, Black);
	gotoxy(15, 25);
	cout << "SCORE:";
	gotoxy(62, 24);
	cout << "Press ESC to exit the game";
	gotoxy(62, 26);
	cout << "Press Space to pause";
}

void Cleanup(int shiftX, int shiftY)
{
	gotoxy(shiftX, shiftY);
	for (int j = shiftY; j < height + shiftY; j++)
	{
		gotoxy(shiftX, j);
		for (int k = shiftX; k < width + shiftX; k++)
		{
			cout << " ";
		}
	}
	gotoxy(28, 24);
	for (int j = 24; j < 28; j++)
	{
		gotoxy(28, j);
		for (int k = 23; k < 55; k++)
		{
			cout << " ";
		}
	}
}

void Motion(int SnakeX[], int SnakeY[], int i)
{
	switch (moveSnake)
	{
	case UP:
		SnakeY[0]--;
		break;
	case DOWN:
		SnakeY[0]++;
		break;
	case LEFT:
		SnakeX[0] -= 2;
		break;
	case RIGHT:
		SnakeX[0] += 2;
		break;
	}
}

void Keys(char key, int exitGame)
{
	switch (key)
	{
	case 32:
		_getch();
		break;
	default:
		if (key == 72 || key == 80 || key == 75 || key == 77)
		{
			if (key == 72 && moveSnake != DOWN)
				moveSnake = UP;
			else if (key == 80 && moveSnake != UP)
				moveSnake = DOWN;
			else if (key == 75 && moveSnake != RIGHT)
				moveSnake = LEFT;
			else if (key == 77 && moveSnake != LEFT)
				moveSnake = RIGHT;
		}
		break;
	}
}

void Score(int score)
{
	Color(White, Black);
	gotoxy(22, 25);
	cout << "     ";
	gotoxy(22, 25);
	cout << score * 10;
}

void LoseGame()
{
	Color(Red, Black);
	gotoxy(43, 25);
	cout << "YOU DIED!";
}

void Game(int shiftX, int shiftY, int speed)
{
	int sizeSnake, i;
	int score = 0;
	int SnakeX[100], SnakeY[100];
	int loseGame, restart = 1, exitGame = 0;
	srand(time(0));
	int AppleX, AppleY;
	int speedSnake;

	while (!(exitGame))
	{
		if (restart)
		{
			speedSnake = speed;
			Cleanup(shiftX, shiftY);
			sizeSnake = 4;
			score = 0;
			Score(score);
			moveSnake = STOP;
			SnakeX[0] = width - 51;
			SnakeY[0] = height / 2 + shiftY;
			Color(White, Black);
			for (i = 0; i < sizeSnake; i++)
			{
				SnakeX[i] = SnakeX[0] - i * 2;
				SnakeY[i] = SnakeY[0];
				gotoxy(SnakeX[i], SnakeY[i]);
				cout << "o";
				if (i == 0)
				{
					gotoxy(SnakeX[i], SnakeY[i]);
					cout << "O";
				}
			}

			int AppleOnSnake = 0;
			while (!(AppleOnSnake))
			{
				do
				{
					do
					{
						AppleX = (shiftX + (rand() % width));
					} while (AppleX % 2 == 1);
					AppleY = (shiftY + (rand() % height));
					for (i = 0; i < sizeSnake; i++)
					{
						if (AppleX == SnakeX[i] && AppleY == SnakeY[i])
						{
							AppleOnSnake = 1;
						}
					}
				} while (AppleOnSnake);
				if (!(AppleOnSnake))
				{
					Color(Yellow, Black);
					gotoxy(AppleX, AppleY);
					cout << "@";
					break;
				}
			}
			restart = 0;
		}

		while (!_kbhit() && !restart)
		{
			Color(White, Black);
			if (moveSnake != STOP)
			{
				if (SnakeX[0] == AppleX && SnakeY[0] == AppleY)
				{
					sizeSnake++;
					score++;
					speedSnake -= 2;
					Score(score);
					int AppleOnSnake = 0;
					while (!(AppleOnSnake))
					{
						do
						{
							do
							{
								AppleX = (shiftX + (rand() % width));
							} while (AppleX % 2 == 1);
							AppleY = (shiftY + (rand() % height));
							for (i = 0; i < sizeSnake; i++)
							{
								if (AppleX == SnakeX[i] && AppleY == SnakeY[i])
								{
									AppleOnSnake = 1;
								}
							}
						} while (AppleOnSnake);
						if (!(AppleOnSnake))
						{
							Color(Yellow, Black);
							gotoxy(AppleX, AppleY);
							cout << "@";
							break;
						}
					}
				}

				Color(White, Black);
				gotoxy(SnakeX[sizeSnake], SnakeY[sizeSnake]);
				for (i = sizeSnake; i > 0; i--)
				{
					SnakeX[i] = SnakeX[i - 1];
					SnakeY[i] = SnakeY[i - 1];
				}
				Motion(SnakeX, SnakeY, i);

				loseGame = 0;
				for (i = 1; i < sizeSnake; i++)
				{
					if (SnakeX[i] == SnakeX[0] && SnakeY[i] == SnakeY[0])
					{
						Color(Red, Black);
						gotoxy(39, 27);
						cout << "YOU EAT YOURSELF!";
						loseGame = 1;
						break;
					}
				}
				if (SnakeX[0] > shiftX + width - 1 || SnakeX[0] < shiftX || SnakeY[0]<shiftY || SnakeY[0]>shiftY + height - 1)
				{
					Color(Red, Black);
					gotoxy(39, 27);
					cout << "YOU HIT THE WALL!";
					loseGame = 1;
				}
				if (loseGame)
				{
					Color(Red, Black);
					gotoxy(SnakeX[1], SnakeY[1]);
					cout << "O";
					for (i = 2; i < sizeSnake + 1; i++)
					{
						gotoxy(SnakeX[i], SnakeY[i]);
						cout << "o";
					}
					restart = 1;
					LoseGame();
					_getch();
				}
				else
				{
					gotoxy(SnakeX[sizeSnake], SnakeY[sizeSnake]);
					cout << " ";
					gotoxy(SnakeX[0], SnakeY[0]);
					cout << "O";
					gotoxy(SnakeX[1], SnakeY[1]);
					cout << "o";
				}
				Sleep(speedSnake);
			}
		}
		char key = _getch();
		Keys(key, exitGame);
		if (key == 27)
			exitGame = 1;
	}
}

int main()
{
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);

	int speed;
	char keyMenu, keySpeedMenu;
	int shiftX = 11, shiftY = 2;
	system("mode con lines=30 cols=97");
	system("title Snake Game");
	Title();
	do
	{
		Menu();
		keyMenu = _getch();
	} while (!(keyMenu == '1' || keyMenu == '2'));
	system("cls");

	if (keyMenu == '2')
	{
		return 0;
	}
	do
	{
		Title();
		MenuSpeed();
		keySpeedMenu = _getch();
	} while (!(keySpeedMenu == '1' || keySpeedMenu == '2' || keySpeedMenu == '3'));
	if (keySpeedMenu == '1')
	{
		speed = 200;
	}
	if (keySpeedMenu == '2')
	{
		speed = 100;
	}
	if (keySpeedMenu == '3')
	{
		return 0;
	}
	Map(shiftX, shiftY);
	Game(shiftX, shiftY, speed);
}