#include "stdafx.h"
#include <iostream>

enum class result { ERROR, PRIME, NOT_PRIME };

double MyPower(double number, int grade)
{
	double Out = 1.0;
	double N = number;
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
			Out *= N;
		}
		return 1.0 / Out;
	}
	return Out;
}
double MySqrt(int number)
{
	if (number == 0)
	{
		return 0;
	}
	if (number == 1)
	{
		return 1;
	}
	if (number > 1)
	{
		double x;
		double SqrtN = number / 2;
		do
		{
			x = SqrtN;
			SqrtN = (x + (number / x)) / 2;
		} while ((x - SqrtN) != 0);
		return SqrtN;
	}
}

int F(int number)
{
	if (number == 0)
	{
		return 1;
	}
	int Out = 1;
	if (number > 0)
	{
		int step = number;
		if (step != 0)
		{
			for (int i = 2; i <= step; ++i)
			{
				Out *= i;
			}
		}
		return Out;
	}
}
result PrimeOrNot(int number)
{
	int counter = 0;
	if (number == 1)
	{
		return result::ERROR;
	}
	for (int i = 2; i <= MySqrt(number); ++i)
	{
		if (number % i == 0)
		{
			++counter;
		}
	}
	if (counter == 0)
	{
		return result::PRIME;
	}
	else
	{
		return result::NOT_PRIME;
	}
}
int main()
{
	std::cout << "Factorial of 4 is: " << F(4) << std::endl;
	std::cout << "Factorial of 0 is: " << F(0) << std::endl;
	std::cout << "4^-1 equal: " << MyPower(4, -1) << std::endl;
	std::cout << "4^0 equal: " << MyPower(4, 0) << std::endl;
	std::cout << "0^4 equal: " << MyPower(0, 4) << std::endl;
	std::cout << "4^3 equal: " << MyPower(4, 3) << std::endl;
	std::cout << "2.3^4 equal: " << MyPower(2.3, 4) << std::endl;
	std::cout << "square root of 4 equal: " << MySqrt(4) << std::endl;
	std::cout << "square root of 13 equal: " << MySqrt(13) << std::endl;
	std::cout << "square root of 2 equal: " << MySqrt(2) << std::endl;
	std::cout << "square root of 0 equal: " << MySqrt(0) << std::endl;
	std::cout << "number 1 is(0-error, 1-prime, 2-not prime): " << (int)PrimeOrNot(1) << std::endl;
	std::cout << "number 2 is(0-error, 1-prime, 2-not prime): " << (int)PrimeOrNot(2) << std::endl;
	std::cout << "number 4 is(0-error, 1-prime, 2-not prime): " << (int)PrimeOrNot(4) << std::endl;
	std::cout << "number 13 is(0-error, 1-prime, 2-not prime): " << (int)PrimeOrNot(13) << std::endl;
	std::cout << "number 412421 is(0-error, 1-prime, 2-not prime): " << (int)PrimeOrNot(412421) << std::endl;
	std::cout << "number 25 is(0-error, 1-prime, 2-not prime): " << (int)PrimeOrNot(25) << std::endl;
	std::cout << "number 199 is(0-error, 1-prime, 2-not prime): " << (int)PrimeOrNot(199) << std::endl;
	system("pause");
	return 0;
}
