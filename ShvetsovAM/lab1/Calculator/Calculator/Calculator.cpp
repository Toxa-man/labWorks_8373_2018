#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(0, "");
	float first, second, result;
	char sign;
	cout << "¬ведите первое число";
	cin >> first;
	cout << "¬ведите второе число";
	cin >> second;
	cout << "¬ведите знак";
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

		if (second == 0)
		{
			cout << "ќшибка: на ноль делить нельз€";
			_getch();
			return 0;
		}
		break;
	default: cout << "ќшибка: неизвестный знак";
		_getch();
		return 0;
	}
	cout << first << " " << sign << " " << second << " = " << result;
	_getch();
	return 0;
}
