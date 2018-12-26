#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main()
{
	float left, right;
	int x;
	x = 0;
	cout << "Enter left value" << "\n";
	while (!(cin >> left))
	{
		cin.clear();
		while (cin.get() != '\n') continue;
		cout << "Enter correct number " << "\n";
	}
	cout << "Enter right value" << "\n";
	while (!(cin >> right))
	{
		cin.clear();
		while (cin.get() != '\n') continue;
		cout << "Enter correct number " << "\n";
	}
	char sign;
	cout << "Enter sign" << "\n";
	cin >> sign;
	float result;
	switch (sign)
	{
	case'+':result = left + right;
		break;
	case'-':result = left - right;
		break;
	case'*':result = left * right;
		break;
	case'/':result = left / right;
		if (right == 0)
		{
			cout << "division by 0 is impossible" << "\n";
		}
		break;
	}
	cout << result << "\n";
	_getch();
	return 0;
}
