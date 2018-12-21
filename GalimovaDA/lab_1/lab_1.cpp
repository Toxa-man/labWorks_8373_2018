#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int main()
{
	float left, right, result;
	char sign;
	bool error = false;
	cout << "Enter first:";
	cin >> left;
	cout << "Enter sign:";
	cin >> sign;
	cout << "Enter second:";
	cin >> right;

	switch (sign)
	{
	case '+':
		result = left + right;
		break;
	case '-':
		result = left - right;
		break;
	case '*':
		result = left * right;
		break;
	case '/':
		if (right == 0)
		{
			error = true;
			cout << "Error: not available to divide by zero";
		}
		else
		{
			result = left / right;
		}
		break;
	default:
		error = true;
		cout << "Error: sign is wrong" << endl;
	}
	if (error == false)
	{
		cout << "Result: " << result << endl;
	}
	_getch();
	system("pause");
	return 0;
}