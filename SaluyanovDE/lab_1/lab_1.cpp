#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	setlocale(0, "");
	char Sign;
	float Val1, Val2, Result, a;
	a = 0;


	cout << "Enter the first number: ";
	cin >> Val1;
	cout << "Enter the operation: ";
	cin >> Sign;
	cout << "Enter the second number: ";
	cin >> Val2;


	switch (Sign) {
	case '*': Result = Val1*Val2;
		break;
	case '/': if (Val2 != 0) 
				{
					Result = Val1 / Val2;
					break;
				}		  
			  else 
				{
					cout << "Error: division by zero";
					a++;
					break;
				}
			  break;
	case '+':  Result = Val1 + Val2;
		break;
	case '-': Result = Val1 - Val2;
		break;
	default: cout << "Error: wrong sign";
		a++;
		break;
	}
	if (a == 0) 
	{
		cout << Val1 << " " << Sign << " " << Val2 << " " << "=" << " " << Result;
		_getch();
	}
	else 
	{
		_getch();
	}
}