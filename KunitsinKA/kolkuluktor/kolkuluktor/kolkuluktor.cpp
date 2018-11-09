#include "stdafx.h" 
#include "iostream" 
#include "conio.h" 
using namespace std;

int main()
{
	float left, right, result;
	char sign;
	setlocale(0, "");
	cout << "Введите левый операнд\n";
	cin >> left;
	cout << "Введите правый операнд\n";
	cin >> right;
	cout << "Введите знак\n";
	cin >> sign;
	while (sign != '+' && sign != '-' && sign != '/' && sign != '*')
	{
		cout << "Вы ввели неверный знак - введите новый\n";
		cin >> sign;
	}
	switch (sign)
	{
	case'+':
		result = left + right;
		break;
	case'-':
		result = left - right;
		break;
	case'*':
		result = left*right;
		break;
	case'/':
		while (right == 0)
		{
			cout << "Введите новые числа, так как на ноль делить нельзя\n";
			cin >> left;
			cin >> right;
			result = left / right;
		}			
		break;
	}
	cout << left << sign << right << "=" << result;
	_getch();
	return 0;
}
