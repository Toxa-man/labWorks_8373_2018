#include "pch.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	setlocale(0, "rus");
	float left, right, result;
	char sign;
	cout << "Введите первое число:"; cin >> left;
	cout << "Введите второе число:"; cin >> right;
	cout << "Введите знак операции:"; cin >> sign;
	switch (sign)
	{
	case '+':
		result = left + right;
		cout << result;
		break;
	case '-':
		result = left - right;
		cout << result;
		break;
	case '*':
		result = left * right;
		cout << result;
		break;
	case '/':
		if (right == 0)
			cout << "На ноль делить нельзя";
		else
			result = left / right;
			cout << result;
		break;
	default:
		cout << "Ошибка! Проверьте правильность введенных данных!";
	}
	return 0;
}