#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
	setlocale(0, "");
	float first, second, result;
	char sign;
	cout << "Введите первое число  ";
	cin >> first;
	cout << "Введите второе число  ";
	cin >> second;
	cout << "Введите знак  ";
	cin >> sign;

	switch (sign)
	{
	case '+': result = first + second;
		break;
	case '-': result = first - second;
		break;
	case '*': result = first*second;
		break;
	case '/': result = first / second;

		if (second == 0 && sign == '/')
		{
			cout << "Ошибка: на ноль делить нельзя, введите другой знаменатель ";
			cin >> second;
		}
		result = first / second;
		break;
		_getch();
		

	default: cout << "Ошибка: неправильный знак ";
		_getch();
		return 0;
	}
	cout << first << " " << sign << " " << second << " = " << result;
	_getch();
	return 0;
