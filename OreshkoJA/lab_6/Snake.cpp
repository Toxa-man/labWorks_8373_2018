#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
const int cons = 600, clean = 60;
const int coord_x = 40, coord_y = 15;
const char _point = 253, snake = 219, ESC = 27;
const int x = 20, y = 8;
const int sleep = 100, sleep1 = 130, sleepESC = 2000, sleep_GO = 1000;
const int for_words_x = 7, for_words_y = 6;
const int for_words_WS_GO_x = 15;
using namespace std;
struct cord
{
	int x;
	int y;
	char snake; 
};
void gotoxy(int x, int y) 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void removeCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void point(int &a, int &b, struct cord *snak)
{ 
	int error = 0;
	while (error == 0)
	{
		a = (rand() % coord_x);
	    b = (rand() % coord_y);
		for (int i = 0; i < cons; i++)
			if (snak[i].x != a && snak[i].y != b)
				error = 1;
			else
			{
				error = 0;
				break;
			}
	}
	gotoxy(a, b);
	cout << _point;
}
void proverka(int &error, int con, struct cord *snak)
{
	for (int i = 1; i <= con - 1; i++)
		if (snak[0].x == snak[i].x && snak[0].y == snak[i].y)
		{
			error = 1;
			break;
		}
}
void prov_point(int &con, struct cord *snak)
{
	++con;
	snak[con] = snak[con - 1];
	snak[con - 1].snake = snak[con - 2].snake;
	gotoxy(snak[con - 1].x, snak[con - 1].y);
	Sleep(sleep);
	cout << snak[con - 1].snake;
}
void cickle(struct cord *snak, int con)
{
	for (int i = con; i >= 1; i--)
	{
		snak[i].y = snak[i - 1].y;
		snak[i].x = snak[i - 1].x;
		gotoxy(snak[i].x, snak[i].y);
		cout << snak[i].snake;
	}
}
void sleep_and_press(char &c)
{
	if (c == 'w' || c == 's')
		Sleep(sleep1);
	else
		Sleep(sleep);
	if (_kbhit())
		c = _getch();
}
int main()
{
	system("mode con cols=40 lines=15");
	system("color E0");
	int error = 0, con = 1, help = 0, a = 0, b = 0, help1 = 0;
	cord snak[cons];
	removeCursor();
	srand(time(0));
	char c=0;
	while (c != ESC)
	{
		snak[0].x = x;
		snak[0].y = y;
		snak[0].snake = snake;
		gotoxy(x, y);
		cout << snak[0].snake;
		gotoxy(for_words_x, for_words_y);
		cout << "Press w, s, a or d to start";
		gotoxy(for_words_x, for_words_y+1);
		cout << "ESC - to exit";
		c = _getch();
		{
			switch (c)
			{
			case ('w'):
				snak[1].x = x;
				snak[1].y = y+1;
				break;
			case ('s'):
				snak[1].x = x;
				snak[1].y = y-1;
				break;
			case ('a'):
				snak[1].x = x+1;
				snak[1].y = y;
				break;
			case ('d'):
				snak[1].x = x-1;
				snak[1].y = y;
				break;
			}
			snak[1].snake = ' ';
			gotoxy(for_words_x, for_words_y);
			for (int i = 0; i < clean; i++)
				cout << " ";
			point(a, b, snak);
			while (con != cons && error == 0 && help1==0)
			{
				switch (c)
				{
				case ('w'):
				{
					help = 0;
					while (help != 1 && con != cons)
					{
						if (snak[0].y - 1 < 0)
						{
							error = 1;
							break;
						}
						proverka(error, con, snak);
						if (error == 1)
							break;
						gotoxy(snak[0].x, snak[0].y - 1);
						cout << snak[0].snake;
						cickle(snak, con);
						snak[0].y = snak[0].y - 1;
						if (snak[0].x == a && snak[0].y == b)
						{
							prov_point(con, snak);
							snak[con].y += 1;
							point(a, b, snak);
						}
						sleep_and_press(c);
							if (c == 'a' || c == 'd')
								help = 1;
							if (c == ESC)
								break;
					}
					break;
				}
				case ('s'):
				{
					help = 0;
					while (help != 1 && con != cons)
					{
						if (snak[0].y + 1 >= 15)
						{
							error = 1;
							break;
						}
						proverka(error, con, snak);
						if (error == 1)
							break;
						gotoxy(snak[0].x, snak[0].y + 1);
						cout << snak[0].snake;
						cickle(snak, con);
						snak[0].y = snak[0].y + 1;
						if (snak[0].x == a && snak[0].y == b)
						{
							prov_point(con, snak);
							snak[con].y -= 1;
							point (a, b, snak);
						}
						sleep_and_press(c);
						if (c == 'a' || c == 'd')
								help = 1;
						if (c == ESC)
								break;
					}
					break;
				}
				case ('a'):
				{
					help = 0;
					while (help != 1 && con != cons)
					{
						if (snak[0].x - 1 < 0)
						{
							error = 1;
							break;
						}
						proverka(error, con, snak);
						if (error == 1)
							break;
						gotoxy(snak[0].x - 1, snak[0].y);
						cout << snak[0].snake;
						cickle(snak, con);
						snak[0].x = snak[0].x - 1;
						if (snak[0].x == a && snak[0].y == b)
						{
							prov_point(con, snak);
							snak[con].x += 1;
							point(a, b, snak);
						}
						sleep_and_press(c);
							if (c == 'w' || c == 's')
								help = 1;
							if (c == ESC)
								break;
					}
					break;
				}
				case ('d'):
				{
					help = 0;
					while (help != 1 && con!=cons)
					{
						if (snak[0].x + 1 >= 40)
						{
							error = 1;
							break;
						}
						proverka(error, con, snak);
						if (error == 1)
							break;
						gotoxy(snak[0].x + 1, snak[0].y);
						cout << snak[0].snake;
						cickle(snak, con);
						snak[0].x = snak[0].x + 1;
						if (snak[0].x == a && snak[0].y == b)
						{
							prov_point(con, snak);
							snak[con].x -= 1;
							point(a, b, snak);
						}
						sleep_and_press(c);
							if (c == 'w' || c == 's')
								help = 1;
							if (c == ESC)
								break;
					}
					break;
				}
				default:
					if (c != ESC)
					{
						gotoxy(for_words_x, y-1);
						cout << " Wrong sign. Try again";
						help1 = 1;
						Sleep(sleepESC);
					}
				}
				if (c == ESC)
					break;
			}
		}
		for (int i = 0; i < cons; i++)
			cout << " ";
		if (error == 1)
		{
			gotoxy(for_words_WS_GO_x, y-1);
			cout << "Game over:(";
			gotoxy(for_words_WS_GO_x, y);
			cout << "Score: " << con - 1;
		}
		if (con == cons)
		{
			gotoxy(for_words_x, y-1);
			cout << "Congratulations! You are the winner!";
		}
		if (c == ESC)
		{
			for (int i = 0; i < cons; i++)
				cout << " ";
			gotoxy(for_words_x+1, y-1);
			cout << "Thank you for a game!"<< endl;
		}
		Sleep(sleep_GO);
		error = 0;
		help = 0;
		con = 1;
		help1 = 0;
		for (int i = 0; i < cons; i++)
			cout << " ";
	}
}