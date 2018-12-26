#include <iostream>
#include <conio.h> 
#include <Windows.h> 
#include <time.h> 
#include <stdlib.h>
#include <vector>
using namespace std;

struct koord_zmei 
{
	int x;
	int y;
};

void sleep(int time)
{
	while (time)
	{
		--time;
		sleep(time);
	}
}

bool exitt()
{
	char exit = _getch();
	if (exit == 13)
	{
		return true;
	}
	else if (exit == 27)
	{
		return false;
	}
	else
	{
		return exitt();
	}
}

void dvizhenie(std::vector<koord_zmei>& zmei, int size, char napravlenie)
{
	for (int i = size-1; i > 0; --i)
	{
		zmei[i].x= zmei[i - 1].x;
		zmei[i].y =zmei[i - 1].y;
	}
	switch (napravlenie)
	{
	case('d'):zmei[0].x += 1;
		break;
	case('u'):zmei[0].x -= 1;
		break;
	case('r'):zmei[0].y += 1;
		break;
	case('l'):zmei[0].y -= 1;
	}
}

void go_xy(int x, int y, char *mas, char cimvol, int size)
{
	COORD xy;
	xy.X = 2 * y;
	xy.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
	*(mas + x*size +y)  = cimvol;
}
void hide_cursor() {
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}
int main()
{
	hide_cursor();
	char kvadrat = 254;
	char pole = 255;
	bool exit = true;
	const int size = 12;
	int wait = 24;
	int counter_for_x=0;
	while (exit)
	{
		char mas[size][size];
		for (int i = 0; i < size; ++i)
		{
			mas[i][0] = mas[i][size - 1] = kvadrat;
			for (int g = 1; g < (size - 1); ++g)
			{
				mas[i][g] = pole;
				mas[0][g] = mas[size - 1][g] = kvadrat;
			}
		}
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				cout << mas[i][j] << " ";
			}
			cout << endl;
		}
		srand(time(0));
		int a = rand() % (size - 2) + 1;
		int b = rand() % (size - 2) + 1;
		go_xy(a, b, &mas[0][0], 'o', size);
		cout << mas[a][b];
		int l=0, m=0;
		vector <koord_zmei> znei(3);
		for (int g = 0; g < znei.size(); ++g)
		{
			znei[g].x = 1;
			znei[g].y = znei.size() - g;
			go_xy(znei[g].x, znei[g].y, &mas[0][0], kvadrat, size);
			cout << mas[znei[g].x][znei[g].y];
		}
		int result = 0;
		bool game = true;
		char napravlenie = 'r';
		while (game)
		{
			koord_zmei xvost;
			xvost.x = znei[znei.size() - 1].x;
			xvost.y = znei[znei.size() - 1].y;
			if (GetAsyncKeyState(VK_UP))
			{
				napravlenie = 'u';
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				napravlenie = 'd';
			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{
				napravlenie = 'r';
			}
			else if (GetAsyncKeyState(VK_LEFT))
			{
				napravlenie = 'l';
			}
			dvizhenie(znei, znei.size(), napravlenie);
			if (mas[znei[0].x][znei[0].y] == pole)
			{
				go_xy(xvost.x, xvost.y, &mas[0][0], pole, size);
				cout << mas[xvost.x][xvost.y];
				go_xy(znei[0].x, znei[0].y, &mas[0][0], kvadrat, size);
				cout << mas[znei[0].x][znei[0].y];
			}
			else if (mas[znei[0].x][znei[0].y] == kvadrat)
			{
				game = false;
				break;
			}
			else if (mas[znei[0].x][znei[0].y] == 'o')
			{
				znei.resize(znei.size() + 1);
				znei[znei.size() - 1].x = xvost.x;
				znei[znei.size() - 1].y = xvost.y;
				go_xy(znei[0].x, znei[0].y, &mas[0][0], kvadrat, size);
				cout << mas[znei[0].x][znei[0].y];
				a = rand() % (size - 2) + 1;
				b = rand() % (size - 2) + 1;
				while ((mas[a][b] == kvadrat)||(mas[a][b] == 'x'))
				{
					a = rand() % (size - 2) + 1;
					b = rand() % (size - 2) + 1;
				}
				go_xy(a, b, &mas[0][0], 'o', size);
				cout << mas[a][b];
				++result;
				if (result%5 == 0)
				{
					l = rand() % (size - 2) + 1;
					m = rand() % (size - 2) + 1;
					while ((mas[l][m] == kvadrat) || (mas[l][m] == 'o'))
					{
						l = rand() % (size - 2) + 1;
						m = rand() % (size - 2) + 1;
					}
					go_xy(l, m, &mas[0][0], 'x', size);
					cout << mas[l][m];
					++counter_for_x;
				}
				if (result%10 == 0)
				{
					--wait;
				}
			}
			else if (mas[znei[0].x][znei[0].y] == 'x')
			{
				go_xy(xvost.x, xvost.y, &mas[0][0], pole, size);
				cout << mas[xvost.x][xvost.y];
				go_xy(znei[znei.size() - 1].x, znei[znei.size() - 1].y, &mas[0][0], pole, size);
				cout << mas[znei[znei.size() - 1].x][znei[znei.size() - 1].y];
				go_xy(znei[0].x, znei[0].y, &mas[0][0], kvadrat, size);
				cout << mas[znei[0].x][znei[0].y];
				znei.resize(znei.size() - 1);
				counter_for_x = 0;
			}
			if (counter_for_x != 0)
			{
				counter_for_x = counter_for_x + 1;
				if (counter_for_x == 20)
				{
					go_xy(l, m, &mas[0][0], pole, size);
					cout << mas[l][m];
					counter_for_x = 0;
				}
			}
			sleep(wait);
		}
		go_xy(5, 2, &mas[0][0], pole, size);
		cout << "Game over";
		go_xy(6, 2, &mas[0][0], pole, size);
		cout << "Result: " << znei.size()-3;
		exit = exitt();
		wait = 24;
		system("cls");
	}
	return 0;
}