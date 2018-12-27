#include "stdafx.h"
#include <iostream>
#include <conio.h>


using namespace std;

double chislo(double number_stepen, int stepen)
{
	double rezult = 1;

	if (stepen > 0) {
		for (int i = 0; i < stepen; i++)
		{
			rezult *= number_stepen;
		}
	}
	else
	{
		for (int i = 0; i < (-1) * stepen; i++)
		{
			rezult  *=  number_stepen;
		}
		rezult = 1 / rezult;
	}

	return rezult;
}

int factorial(int number_factorial)
{
	int rezult = 1;

	for (int i = 1; i <= number_factorial; i++)
	{
		rezult *= i;
	}

	return rezult;
}

double sqrt(int number_sqrt)
{
	double k;
	double rezult = number_sqrt / 2;
	do {
		k = rezult;
		rezult = (k + (number_sqrt / k)) / 2;
	} while ((k - rezult) != 0);
	return rezult;
}

bool prime(int number_prime)
{
	bool rezult = false;

	for (int i = 2; i < number_prime; i++)
	{
		if (number_prime%i == 0)
		{
			rezult = true;
		}
	}

	return rezult;
}

int main()
{
	int number_stepen, stepen;
	cout << "Write number for stepen: ";
	cin >> number_stepen;
	cout << "Write stepen: ";
	cin >> stepen;
	cout << number_stepen << " ^ " << stepen << " = " << chislo(number_stepen, stepen) << endl;
	cout << endl;

	int number_fact;
	cout << "Write a nummber for factorial: ";
	cin >> number_fact;
	if (number_fact < 0)
	{
		cout << "Error: impossible to take Fact. from this number: " << number_fact << endl;
	}
	else
	{
		if (number_fact == 0)
		{
			cout << "0! = 1" << endl;

		}
		else
		{
			cout << number_fact << "! = " << factorial(number_fact) << endl;
		}
	}
	cout << endl;

	int number_sqrt;
	cout << "Write a number for sqrt: ";
	cin >> number_sqrt;
	if (number_sqrt < 0)
	{
		cout << "It is impossible to find sqrt from this number: " << number_sqrt << endl;

	}
	else
	{
		cout << "Sqrt from " << number_sqrt << " = " << sqrt(number_sqrt) << endl;

	}
	cout << endl;
	int number_prime;
	cout << "Write a number to get checked: ";
	cin >> number_prime;

	if (number_prime <= 1)
	{
		cout << "Number " << number_prime << " is not a prime number" << endl;
	}
	else
	{
		if (prime(number_prime) == false)
		{
			cout << "Number " << number_prime << " is a prime number" << endl;
		}
		else
		{
			cout << "Number " << number_prime << " is not a prime number" << endl;
		}
	}

	cout << endl;

	system("pause");
}




















