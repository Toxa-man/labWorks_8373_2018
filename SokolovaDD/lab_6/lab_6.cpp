#include<iostream>
#include <windows.h>
#include<conio.h>
using namespace std;
const int siz = 9;
void cleanner(char num[siz])
{
	for (int i = 0; i < siz; i++)
	{
		num[i] = '-';
	}
}
void board(char num[siz])
{
	cout << endl << "Game board" << endl;
	cout << "\t -" << num[6] << "-|-" << num[7] << "-|-" << num[8] << "-" << endl;
	cout << "\t -" << num[3] << "-|-" << num[4] << "-|-" << num[5] << "-" << endl;
	cout << "\t -" << num[0] << "-|-" << num[1] << "-|-" << num[2] << "-" << endl;
}
void help_board()
{
	cout << "Help Board" << endl;
	cout << " \t -7-|-8-|-9-" << endl;
	cout << " \t -4-|-5-|-6-" << endl;
	cout << " \t -1-|-2-|-3-" << endl;
	cout << endl;
}
double normal_cin(int n)
{
		if (cin.fail()) // если предыдущее извлечение оказалось провальным
		{
			cin.clear(); // возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Oops, that input is invalid.  Please try again."<<endl;
		}
		else
		{
		    cin.ignore(32767, '\n');
			return n;
		}
}
int Contol_InPut_Value(char num[siz],int i)
{
	help_board();
	board(num);
	int n;
	if (i % 2==0) 
	{
		cout << "Step plaeyr X :  ";
		cin >> n;
		normal_cin(n);
		while ((n > 9) || (n < 1) || (num[n - 1] != '-'))
		{
			cout << "Incorrect value" << endl;
			cin >> n;
			normal_cin(n);
		}
	}
	else
	{
		cout << "Step player 0 :  ";
		cin >> n;
		normal_cin(n);
		while ((n > 9) || (n < 1) || (num[n - 1] != '-'))
		{
			cout << "Incorrect value"<<endl;
			cin >> n;
			normal_cin(n);
		}
	}
	return n;
}

bool win(char num[siz])
{
	if ((num[0] == 'X' && num[1] == 'X' &&  num[2] == 'X') ||
	 (num[3] == 'X' && num[4] == 'X' && num[5] == 'X') ||
	 (num[6] == 'X' && num[7] == 'X' &&  num[8] == 'X') ||
	 (num[0] == 'X' && num[3] == 'X' && num[6] == 'X') ||
	(num[1] == 'X' && num[4] == 'X' && num[7] == 'X') ||
	(num[2] == 'X' && num[5] == 'X' && num[8] == 'X') ||
	(num[0] == 'X' && num[4] == 'X' && num[8] == 'X') ||
	 (num[2] == 'X' && num[4] == 'X' && num[6] == 'X') )
	{
		cout << "Win player X" << endl;
		return 1;
	}
	if ((num[0] == 'O' && num[1] == 'O' &&  num[2] == 'O') ||
	 (num[3] == 'O' && num[4] == 'O' && num[5] == 'O') ||
	 (num[6] == 'O' && num[7] == 'O' &&  num[8] == 'O') ||
	(num[0] == 'O' && num[3] == 'O' && num[6] == 'O') ||
	 (num[1] == 'O' && num[4] == 'O' && num[7] == 'O') ||
	 (num[2] == 'O' && num[5] == 'O' && num[8] == 'O') ||
	 (num[0] == 'O' && num[4] == 'O' && num[8] == 'O') ||
	 (num[2] == 'O' && num[4] == 'O' && num[6] == 'O'))
	{
		cout << "Win player 0" << endl;
		return 1;
	}
	return 0;
}

void game(char num[siz])
{
	cleanner(num);
	for (int i = 0; i < siz; i++)
	{
		system("cls");
		int number = Contol_InPut_Value(num,i);
		if (i % 2 == 0)
		{
			num[number - 1] = 'X';
		}
		else
		{
			num[number - 1] = 'O';
		}
		if (win(num) == 1)
		{
			system("cls");
			win(num);
			cout << "Game over." << endl;
			board(num);
			_getch();
			break;
		}
		if (i == 8)
		{
			system("cls");
			if (win(num) == 0)
			{
				cout << "No winner" << endl << "Game over." << endl;
				board(num);
				_getch();
				break;
			}
		}
	}
}

int main()

{
	char n[siz];
	system("mode con cols=30 lines=15");
	system("color F0");
	game(n);
	return 0;
}
