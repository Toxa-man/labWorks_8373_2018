#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <time.h>
const int dlina = 75;
const int visota = 20;
enum Napravlenie { start = 0, up, down, left1, right1 } Direction;
using namespace std;
// main stuff
void mainstuff(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// controll stuff
void controllmain(int xsnake[], int ysnake[], int i) {
	switch (Direction) {
	case up: ysnake[0]--;
		break;
	case down: ysnake[0]++;
		break;
	case right1: xsnake[0]++;
		break;
	case left1: xsnake[0]--;
		break;
	}
}
void controllkey(char key) {
		switch (key) {
		case'w': if (Direction != down)  Direction = up; 
			break;
		case 's':if (Direction != up)  Direction = down; 
			break;
		case 'a':if (Direction != right1)  Direction = left1; 
			break;
		case 'd': if (Direction != left1)  Direction = right1; 
			break;
		default:
			if (key == 27) {
				exit(0);
				break;
			}
		}
}
//=====  map starting options  ======
void map(int x1, int y1){
	system("cls");
	int x;
	mainstuff(x1 - 1, y1 - 1);
	cout << char(218);
	for (x = 0; x < dlina; x++){
		cout << char(196);
	}
	cout << char(191);

	for (x = 0; x < visota; x++){
		mainstuff(x1 - 1, x + 2);
		cout << char(179);
		mainstuff(x1 + dlina, x + 2);
		cout << char(179);
	}
	mainstuff(x1 - 1, y1 + visota);
	cout << char(192);
	for (x = 0; x < dlina; x++){
		cout << char(196);
	}
	cout << char(217);
	mainstuff(5, 23);
	cout << "SCORE";
	mainstuff(5,0);
	cout << "PRESS SPACE TO RESET UR SCORE";
	mainstuff(55, 0);
	cout << "PRESS ESC TO CLOSE THE GAME";
}
// map reset
void reset(int x1, int y1)
{
	mainstuff(x1, y1);
	for (int j = y1; j < visota + y1; j++) {
		mainstuff(x1, j);
		for (int k = x1; k < dlina + x1; k++) {
			cout << " ";
		}
	}
	// cleanup pro tips
	mainstuff(28, 23);
	for (int j = 23; j < 29; j++)
	{
		mainstuff(28, j);
		for (int k = 22; k < 65; k++)
		{
			cout << " ";
		}
	}
}
// GAME OPTIONS
void gamescore(int score) {
	mainstuff(12, 23);
	cout << score *10;
}
void game(int x1, int y1,int velocity) {
	int size;
	int i;
	int xsnake[100], ysnake[100];
	bool end = false, play = true;
	int xfrukt, yfrukt, score = 0;
	int forfeit;
	int snakevelocity;
	Direction = start;
	xsnake[0] = 43;
	ysnake[0] = 11;
	while (!(end))
	{
		if (play){
		snakevelocity = velocity;
		reset(x1, y1);
		size = 2;
		gamescore(score);
		Direction = start;
		xsnake[0] = 43;	
		ysnake[0] = 11;
		for (i = 0; i < size; i++){
			xsnake[i]= xsnake[0] -i;
			ysnake[i] = ysnake[0];
			mainstuff(xsnake[i], ysnake[i]);
			cout << "o";
			if (i == 0){
				mainstuff(xsnake[i], ysnake[i]);
				cout << "O";
				}
			}

			int fruktspawn = 1;
			while (fruktspawn){
	
				xfrukt = (x1 + (rand() % dlina));
	
				yfrukt = (y1 + (rand() % visota));
				for (i = 0; i < size; i++){
				if (xfrukt == xsnake[i] && yfrukt == ysnake[i]){
						fruktspawn = 0;
					}
				}

			if (fruktspawn){
				mainstuff(xfrukt, yfrukt);
				cout << "X";
				break;
				}
			}
			play = false;
		}
		while (!_kbhit() && !play){
			if (Direction != start){
				if (xsnake[0] == xfrukt && ysnake[0] == yfrukt){
					size++;
					score++;
					gamescore(score);
					int fruktspawn = 0;
					while (!(fruktspawn)){
		xfrukt = (x1 + (rand() % dlina));
		yfrukt = (y1 + (rand() % visota));
		for (i = 0; i < size; i++){
		if (xfrukt == xsnake[i] && yfrukt == ysnake[i]){
		fruktspawn = 1;
						}
						}
						if (!(fruktspawn)){
							mainstuff(xfrukt, yfrukt);
							cout << "X";
							break;
						}
					}
				}
				mainstuff(xsnake[size], ysnake[size]);
				for (i = size; i > 0; i--){
					xsnake[i] = xsnake[i - 1];
					ysnake[i] = ysnake[i - 1];
				}
				controllmain(xsnake, ysnake, i);
				bool forfeit = false;
				for (i = 1; i < size; i++){
					if (xsnake[i] == xsnake[0] && ysnake[i] == ysnake[0]){
						mainstuff(34, 23);
						cout << "CHILL! CONTROLL UR HUNGER!";
						mainstuff(34, 24);
						cout << "U've just eaten urself alive!";
						forfeit= true;
						break;
					}
				}
				if (xsnake[0] > x1 + dlina - 1 || xsnake[0] < x1 || ysnake[0]>y1 + visota - 1 || ysnake[0] < y1){
					mainstuff(40, 23);
					cout << "PRO TIP:";
					mainstuff(34, 24);
					cout << "TRY TO NOT HIT WALLS!";
					forfeit = true;
				}
				if (forfeit){
					mainstuff(xsnake[1], ysnake[1]);
					cout << "O";
					 for (i = 2; i < size + 1; i++){
					 mainstuff(xsnake[i], ysnake[i]);
					cout << "o";
					}
					play = true;
					mainstuff(33, 11);
					cout << "BETTER LUCK NEXT TIME";
					_getch();
				}
				else{
					mainstuff(xsnake[size], ysnake[size]);
					cout << " ";
					mainstuff(xsnake[0], ysnake[0]);
					cout << "O";
					mainstuff(xsnake[1], ysnake[1]);
					cout << "o";
				}
				Sleep(snakevelocity);
			}
		}
		char key = _getch();
		controllkey(key);
		if (key == 32)
			end = true;
	}
}
int main() {
	int velocity = 90;
	char exit1;
	system("color D");
	char key;
	int x1 = 6, y1 = 2;
	bool gameover = false;
	do {
		system("cls");
		cout << setw(25) << "_$$$$__$$__$$__$$$$__$$__$$_$$$$$\n$$_____$$$_$$_$$__$$_$$_$$__$$\n_$$$$__$$_$$$_$$$$$$_$$$$___$$$$\n____$$_$$__$$_$$__$$_$$_$$__$$\n_$$$$__$$__$$_$$__$$_$$__$$_$$$$$\n" << setw(35) << "The game\n\n" << setw(21) << "NEW  GAME\n" << setw(19) << "GUIDE\n" << setw(17) << "EXIT";
		cout << "\n\n\n\n" << "1=Start" << setw(15) << "2=HOW TO PLAY" << setw(10) << "ESC=exit";

		switch (key = _getch()) {
		case'1':
			system("cls");
			cout << "\n\n\n\n\n";
			cout << setw(70);
			cout << "Press any button to start";
			_getch();
			while (gameover != true) {
				map(x1,y1);
				game(x1, y1,velocity);
			}
			break;
		case'2':
			system("cls");
			cout << "X is a fruit. Eat it and grow ur snake!\nO is ur snake. Use controll buttons W,A,S,D to move it\n\n~~~~~Good Luck!~~~~~\n\n\n\npress ESC to exit from the game or press any other button to exit to the main menu\n";
			break;

		case 27:
			exit(0);
			break;
		}
		exit1 = _getch();
	} while (exit1 != 27);
	return 0;
}

