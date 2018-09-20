#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(0, "");
	float first, second, result;
	char sign;
	cout << "Ââåäèòå ïåðâîå ÷èñëî";
	cin >> first;
	cout << "Ââåäèòå âòîðîå ÷èñëî";
	cin >> second;
	cout << "Ââåäèòå çíàê";
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
			cout << "Îøèáêà: íà íîëü äåëèòü íåëüçÿ";
			_getch();
		}
		break;
	default: cout << "Îøèáêà: íåèçâåñòíûé çíàê";
		_getch();
	}
	cout << first << " " << sign << " " << second << " = " << result;
	_getch();
	return 0;
}
