#include <iostream>
#include <conio.h>

using namespace std;

double power(double number_stepen, int stepen)
{
	double rez = 1;
	
		if (stepen > 0) {
			for (int i = 0; i < stepen; i++)
			{
				rez *=  number_stepen;
			}
		}
		else
		{
			for (int i =0; i < (-1) * stepen; i++)
			{
				rez = rez * number_stepen;
			}
			rez = 1 / rez;
		}

	return rez;
}

int fact (int number_fact)
{
	int rez = 1;

for (int i=1;  i <= number_fact; i++)
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

bool simple(int number_simple)
{
	bool simple = true;
	for (int i = 2; i < number_simple; i++)
	{
		if (number_simple%i == 0)
		{
			simple = false;
		}
	}
	return simple;
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
	cout << number_fact << "! = " << fact(number_fact) << endl;
	cout << endl;

	cout << "Third" << endl;
	int number_sqrt;
	cout << "Write a number: ";
	cin >> number_sqrt;
	cout << "Sqrt from " << number_sqrt << " = " << sqrt(number_sqrt) << endl;
	cout << endl;

	cout << "Fourth" << endl;
	int number_simple;
	cout << "Write a number to get checked: ";
	cin >> number_simple;
	if (simple(number_simple) == 1)
	{
		cout << "Number " << number_simple << " is a " << "simple number" << endl;
	}
	else
	{
		cout << "Number " << number_simple << " is a " << "simple number" << endl;
	}

	cout << endl; //Is it ok to use this string in the end, to make finalconcole more attractive?

	system("pause");
}