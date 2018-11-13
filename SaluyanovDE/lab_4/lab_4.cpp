#include "stdafx.h"
#include <iostream>
using namespace std;

double MyPower(int number, int grade)
{
	int Out = 1;
	int N = number;
	if (grade > 0)
	{
		for (int i = 1; i <= grade; ++i)
		{
			Out *= N;
		}
		return Out;
	}
	if (grade < 0)
	{
		for (int i = 1; i <= -grade; ++i)
		{
			Out *=N;
		}
		return 1.0/Out;
	}
	return Out;
}
double MySqrt(int number)
{
	if (number == 0)
	{
		return 0;
	}
	double x;
	double SqrtN = number / 2;
	do
	{
		x = SqrtN;
		SqrtN = (x + (number / x)) / 2;
	} while ((x - SqrtN) != 0);
	return SqrtN;
}

int F(int number)
{
	if (number == 0)
	{
		return 1;
	}
	int step = number;
	int Out = 1;
	if (step != 0)
	{
		for (int i = 2; i <= step; ++i)
		{
			Out *= i;
		}
	}
	return Out;
}
void PrimeOrNot(int number)
{
	int step1=0, step2=0;
	bool PrimeExclusive = false;
	bool PrimeCheck = true;
	int n = 1;
	int check = MySqrt(number);
	if (number == 2 || number == 3)
	{
		cout << number << " - PRIME";
		PrimeExclusive = true;
	}
	if (number % 2 != 0 && number % 3 != 0&&PrimeExclusive == false)
	{
		while (step1 <= check && step2 <= check)
		{
			step1 = 6 * n + 1;
			step2 = 6 * n - 1;
			++n;
			if (number%step1 == 0 || number%step2 == 0)
			{
				cout << number << " - NOT PRIME.";
				PrimeCheck = false;
				break;
			}
		}
	}
	else if(!PrimeExclusive)
	{
		cout << number << " - NOT PRIME.";
		PrimeCheck = false;
	}
	if (PrimeCheck&&!PrimeExclusive)
	{
		cout << number<<" - PRIME.";
	}
	cout << endl;
}
int main()
{
	cout << "Factorial 4 is: " << F(4) << endl;
	cout << "Factorial 0 is: " << F(0) << endl;
	cout << "4^-1 equal to " << MyPower(4, -1) << endl;
	cout << "4^0 equal to " << MyPower(4, 0) << endl;
	cout << "0^4 equal to " << MyPower(0, 4) << endl;
	cout << "4^3 equal to " << MyPower(4, 3) << endl;
	cout << "Square root of 4 is: " << MySqrt(4) << endl;
	cout << "Square root of 2 is: " << MySqrt(2) << endl;
	cout << "Square root of 0 is: " << MySqrt(0) << endl;
	PrimeOrNot(2);
	PrimeOrNot(4);
	PrimeOrNot(13);
	PrimeOrNot(412421);

	system("pause");
    return 0;
}