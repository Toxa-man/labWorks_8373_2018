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
	float result;
	switch (sign)
	{
	case'+': result = left + right;
		break;
	case'-': result = left - right;
		break;
	case'*':result = left * right;
		break;
	case'/':
		if (right == 0)
		{
			cout << "Невозможно выполнить операцию";
			_getch();
			return 0;
			break;
		}
		else
		{
			result = left / right;
			break;
		}
	default:
		cout << "Знак был введен неверно";
		_getch();
		return 0;
	}
	cout << "Результат:" << result;
	_getch();
}
