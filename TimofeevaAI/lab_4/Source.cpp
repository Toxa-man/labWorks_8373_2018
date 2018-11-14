#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

double Stepen(float digit, int stepen)
{
	int  p, d;
	p = digit;
	d = digit;
	if (stepen > 0)
	{
		for (int i = 1; i < stepen; i++)
		{
			digit = d * p;
			d = digit;
		}
	}
	else if (stepen < 0)
	{
		digit = 1;
		for (int i = 0; i > stepen; i--)
		{
			digit = digit / p;
		}
	}
	else if (stepen == 0)
	{
		digit = 1;
	}
	return digit;
}

int Fact(int c)
{
	int f = 1;
	for (int i1 = 1; i1 < c + 1; i1++)
	{
		f *= i1;
	}
	return f;
}

double Koren(float z)
{
	float koren;
	if (z >= 0)
	{
		koren = sqrt(z);
		cout<<"Radical: ";
		return koren;
	}
	else 
	{
		cout << "Negative digit"<<endl;
		return 0;
	}
	
	
}

	 
int Simple(int m)
{
	if ((m >= 2) && (m % 5 != 0) && (m % 3 != 0) && (m % 2 != 0))
	{
		cout << "Simple"<<endl ;
	}
	else {
		cout << "Not simple" << endl;
	}
	return 0;
}

int main()
{
	int a, b, h, g, f;
	cout << "Enter digit: ";
	cin >> a;
	cout << "Enter stepen: ";
	cin >> b;
	cout << "Result: " << Stepen(a, b) << "\n";

	cout << "Enter second digit:";
	cin >> h;
	cout << "Factorial: " << Fact(h) << endl;

	cout << "Enter third digit:";
	cin >> g;
	cout <<Koren(g) << endl;

	cout << "Enter fourth digit: ";
	cin >> f;
	Simple(f);
	system("pause");
}