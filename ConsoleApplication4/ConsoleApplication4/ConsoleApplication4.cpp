#include "pch.h"
#include <iostream>
#include <conio.h> 
using namespace std;
int main()
{
	setlocale(0, "");
	float left, right;
	cout << "Введите левый аргумент";
	cin >> left;
	cout << "Введите правый аргумент";
	cin >> right;
	char sign;
	cout << "Введите знак";
	cin >> sign;
	switch (sign)
	{
	case'+': cout << "Результат:" << left + right;
		break;
	case'-':cout << "Результат:" << left - right;
		break;
	case'*':cout << "Результат:" << left * right;
		break;
	case'/':
		if (right == 0)
		{
			cout << "Невозможно выполнить операцию";
			break;
		}
		else
		{
			cout << "Результат:"<< left / right;
			break;
		}
	default:
		cout << "Знак был введен неверно";
	}
	_getch();
}
