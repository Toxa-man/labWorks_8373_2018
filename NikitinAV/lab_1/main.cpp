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
	bool check;
	check = true;
	switch (sign)
	{
	case'+': result = left + right;
		break;
	case'-': result = left - right;
		break;
	case'*':result = left * right;
		break;
	case'/': if (right == 0) {
		check = false;
		cout << "Невозможно выполнить операцию";
		break;
	}
			 else {
		result = left / right;
		break;
	}
	default:
		cout << "Знак был введен неверно";
		check = false;
		break;
	}
			 if (check == true) {
				 cout << "Результат:" << result;
			 }
			 _getch();
	}
