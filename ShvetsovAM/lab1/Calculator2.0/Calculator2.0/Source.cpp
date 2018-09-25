#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	setlocale(0, "");
	float first, second, result;
	char sign;
	cout << "Ââåäèòå ïåðâîå ÷èñëî ";
	cin >> first;
	cout << "Ââåäèòå âòîðîå ÷èñëî ";
	cin >> second;
	cout << "Ââåäèòå çíàê ";
	cin >> sign;
		while (!(sign == '+' || sign == '-' || sign == '*' || sign == '/'))
		{
			cout << "Ââåäåí íåâåðíûé çíàê, ââåäèòå ïðàâèëüíûé çíàê ";
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
					cout << "Íà íîëü äåëèòü íåëüçÿ, ââåäèòå äðóãîé çíàìåíàòåëü ";
					cin >> second;
				}
			}
			result = first / second;
			break;
		}
	}
	cout << first << " " << sign << " " << second << " = " << result;
	_getch();
    return 0;	
}
