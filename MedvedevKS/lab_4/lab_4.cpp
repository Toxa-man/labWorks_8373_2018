#include "stdafx.h"
#include <conio.h>
#include <iostream>
using namespace std;

double intPower(double number, int n)
{
	double result = 1;
	for (int i = 0; i < abs(n); i++)
	{
		result *= number;
	}
	if (n < 0)
	{
		result = 1 / result;
	}
	return result;
}

int factorial(int number)
{
	if (number < 0)
	{
		return 0;
	}
	if (number > 12)
	{
		return -1;
	}
	int result = 1;
	for (int i = 2; i <= number; i++)
	{
		result *= i;
	}
	return result;
}

double SquareRoot(double number)
{
	if (number < 0)
	{
		return -2;
	}
	double result = 0;
	for (int i = 0; i < 10000; i++)
	{
		result = 1 + (number - 1) / (result + 1);
	}
	return result;
}

bool PrimeCheck(int number)
{
	if (number <= 1)
	{
		return false;
	}
	for (int i = 2; i <= SquareRoot(number); i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	double number;
	int n;
	cout << "Enter a number: ";
	cin >> number;
	cout << "Enter a power: ";
	cin >> n;
	cout << "******************************CHECK******************************\n";
	cout <<"\'" << n <<"\' power of \'" << number << "\' is " << intPower(number, n) << endl;
	switch (factorial(number))
	{
	case(0):
		cout << "Factorial of \'" << number << "\' doesnt exist" << endl;
		break;
	case(-1):
		cout << "Factorial of \'" << number << "\' is more than 2 billion" << endl;
		break;
	default:
		cout << "Factorial of \'" << int(number) << "\' is " << factorial(number) << endl;
	}
	if (SquareRoot(number) == -2)
	{
		cout << "SqureRoot: there is no square root in the field of real numbers\n";
	}
	else
	{
		cout << "Squre root of \'" << number << "\' is " << SquareRoot(number) << endl;
	}
	if (PrimeCheck(number))
	{
		cout << "\'" << number << "\' is a prime number" << endl;
	}
	else
	{
		cout << "\'" << number << "\' is not a prime number" << endl;
	}
	cout << "*******************************DONE******************************";
	_getch();
    return 0;
}
