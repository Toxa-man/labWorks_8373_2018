#include "pch.h"
#include <iostream>
#include <conio.h>


using namespace std;

double power(double number_stepen, int stepen)
{
	double rez = 1;

	if (stepen > 0) {
		for (int i = 0; i < stepen; i++)
		{
			rez *= number_stepen;
		}
	}
	else
	{
		for (int i = 0; i < (-1) * stepen; i++)
		{
			rez = rez * number_stepen;
		}
		rez = 1 / rez;
	}

	return rez;
}

int fact(int number_fact)
{
	int rez = 1;

	for (int i = 1; i <= number_fact; i++)
	{
		rez *= i;
	}

	return rez;
}

double sqrt(int number_sqrt)
{
	double t;
	double rez = number_sqrt / 2;
	do {
		t = rez;
		rez = (t + (number_sqrt / t)) / 2;
	} while ((t - rez) != 0);

	return rez;
}

bool prime(int number_prime)
{
	bool rez = false;

	for (int i = 2; i < number_prime; i++)
	{
		if (number_prime%i == 0)
		{
			rez=true;
		}
	}
	
	return rez;
}

int main()
{
	cout << "First: " << endl;
	int number_stepen, stepen;
	cout << "Write number: ";
	cin >> number_stepen;
	cout << "Write stepen: ";
	cin >> stepen;
	cout << number_stepen << " ^ " << stepen << " = " << power(number_stepen, stepen) << endl;
	cout << endl;

	cout << "Second: ";
	int number_fact;
	cout << "Write a nummber: ";
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
			cout << number_fact << "! = " << fact(number_fact) << endl;
		}
	}
	cout << endl;


	cout << "Third: " << endl;
	int number_sqrt;
	cout << "Write a number: ";
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

	cout << "Fourth: " << endl;
	int number_prime;
	cout << "Write a number to get checked: ";
	cin >> number_prime;

	if (number_prime <= 1)
	{
		cout << "Number " << number_prime << " is not a prime number" << endl;
	}
	else
	{
		if (prime(number_prime)==false)
		{
			cout << "Number " << number_prime << " is a prime number" << endl;
		}
		else
		{
			cout << "Number " << number_prime << " is not a prime number" << endl;
		}
	}

	cout << endl; //Is it ok to use this string in the end, to make finalconcole more attractive?

	system("pause");
}
