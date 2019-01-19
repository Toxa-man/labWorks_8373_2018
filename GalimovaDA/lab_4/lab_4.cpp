#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

void exponent(int number, int number_exponent)
{
	float result = 1;
	if (number_exponent == 0)
	{
		result = 1;
	}
	if (number_exponent > 0)
	{
		for (int i = 0; i <= number_exponent; i++)
		{
			result = result * number;
		}
		cout << number << "^" << number_exponent << " = " << result;
	}
	if (number_exponent < 0)
	{
		number_exponent = number_exponent * (-1);
		for (int i = 0; i <= number_exponent; i++)
			{
				result = result * number;
			}
		result = 1 / result;
		cout << number << "^" << number_exponent << " = " << result;
	}
	
}

void factorial(int number)
{
	int result = 1;
	for (int i = 1; i <= number; i++)
	{
		result *= i;
	}
	cout << number << "! = " << result;
}

void square_root(float number)
{
	if (number < 0)
	{
		cout << "Error";
	}
	else {
		float temp;
		float result = number / 2;
		do {
			temp = result;
			result = (temp + (number / temp)) / 2;
		} while ((temp - result) != 0);
		cout << "Square root of " << number << " = " << result;
	}
}

void prime(int number)
{
	bool check = true;
	if (number == 1)
	{
		check = false;
	}
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			check = false;
		}
	}
	if (check = true)
	{
		cout << number << " is a prime number";
	}
	else {
		cout << number << " is not a prime number";
	}
}

int main()
{
	int number;
	int number_exponent;
	float number_for_root;
	
	cout << "EXPONENTIATION" << endl;
	cout << "Enter number: ";
	cin >> number;
	cout << "Enter number of exponent: ";
	cin >> number_exponent;
	exponent(number, number_exponent);
	cout << endl << endl;

	cout << "FACTORIAL" << endl;
	cout << "Enter number: ";
	cin >> number;
	factorial(number);
	cout << endl << endl;

	cout << "SQUARE ROOT" << endl;
	cout << "Enter number: ";
	cin >> number_for_root;
	square_root(number_for_root);
	cout << endl << endl;

	cout << "PRIME OR NOT?" << endl;
	cout << "Enter number: ";
	cin >> number;
	prime(number);
	cout << endl << endl;

	system("pause");
	return 0;
}
