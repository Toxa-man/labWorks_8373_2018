#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	setlocale(0, "");
	float first, second, result;
	char sign;
	cout << "Введите первое число ";
	cin >> first;
	cout << "Введите второе число ";
	cin >> second;
	cout << "Введите знак ";
	cin >> sign;
	while (!(sign == '+' || sign == '-' || sign == '*' || sign == '/'))
	{
		cout << "Введен неверный знак, введите правильный знак ";
		cin >> sign;
	}
		switch (sign)
		{
		case '+': result = first + second;
			break;
		case '-': result = first - second;
			break;
		case '*': result = first * second;
			break;
		case '/':
			if (second == 0)
			{
				while (second == 0)
				{
					cout << "На ноль делить нельзя, введите другой знаменатель ";
					cin >> second;
				}
			}
			result = first / second;
			break;
		}
	cout << first << " " << sign << " " << second << " = " << result;
	_getch();
    return 0;	
}