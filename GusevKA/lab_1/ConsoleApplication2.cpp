#include "pch.h"
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(0, "");
	char act;
	float first, second, result;
	cout << "Write first number ";
	cin >> first;
	cout << "Input second number ";
	cin >> second;
	cout << "Write action ";
	cin >> act;

	switch (act)
	{
	case '/':
		if (second != 0)
		{
			result = first / second;
			cout << result;
			break;
		}
		else
		{
			cout << "You cann't / by zero";
			break;
		}
	case '+':
		result = first + second;
		cout << result;
		break;
	case '-':
		result = first - second;
		cout << result;
	case '*':
		result = first * second;
		cout << result;

	default:
		cout << "unknown sign";
	}
	cout << endl;

	_getch();

	return 0;
}
