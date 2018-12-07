#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

double Stepen(float number, int stepen)
{
	float  p, d;
	p = number;
	d = number;
	if (number == 0)
		return 0;
	if (stepen > 0)
	{
		for (int i = 1; i < stepen; i++)
		{
			number = d * p;
			d = number;
		}
	}
	else if (stepen < 0)
	{
		number = 1;
		for (int i = 0; i > stepen; i--)
		{
			number = number / p;
		}
	}
	else if (stepen == 0)
	{
		number = 1;
	}
	return number;
}

int Fact(int c)
{
	if (c < 0)
		return 0;
	int f = 1;
	for (int i = 1; i < c + 1; i++)
	{
		f *= i;
	}
	return f;
}

double Koren(double n)
{
	float sqrt = 0;
	if (n <= 0)
		cout << "Negative number" << endl;
	else
	{
		for (int i = 0; i < 10000; i++)
		{
			sqrt = 1 + (n - 1) / (sqrt + 1);
		}
	}
	return sqrt;
}


int Simple(int m)
{

	if ((m != 2) && (m != 3) && (m != 5))
	{
		if ((m % 2 != 0) && (m % 3 != 0) && (m % 5 != 0))
			cout << "Simple" << endl;
		else
			cout << "Not simple" << endl;
	}
	else
	{
		cout << "Simple";
	}
	return 0;
}

int main()
{
	float a, b, h, g, f;
	cout << "Enter a number: ";
	cin >> a;
	cout << "Enter stepen: ";
	cin >> b;
	cout << "Result: " << Stepen(a, b) << "\n";


	cout << "Enter a number to find factorial: ";
	cin >> h;
	cout << "Factorial: " << Fact(h) << endl;

	cout << "Enter a number to extract the square root: ";
	cin >> g;
	cout << Koren(g) << endl;

	cout << "Enter a number to determine its simplicity: ";
	cin >> f;
	Simple(f);
	system("pause");
}