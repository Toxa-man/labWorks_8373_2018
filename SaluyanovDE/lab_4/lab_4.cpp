#include "stdafx.h"
#include <iostream>

enum class result {ERROR, PRIME, NOT_PRIME};

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
	int step1 = 0, step2 = 0;
	bool PrimeExclusive = false;
	bool PrimeCheck = false;
	bool answer = false;
	int n = 1;
	int check = MySqrt(number);
	if (number == 1)
	{
		return result::ERROR;
	}
	if (number == 2 || number == 3)
	{
		return result::PRIME;
	}
	if (number % 2 != 0 && number % 3 != 0 )
	{
		for (int i = 1; i < check; ++i)
		{
			step1 = 6 * n + 1;
			step2 = 6 * n - 1;
			++n;
			if (number%step1 == 0 && number == step1 || number%step2 == 0 && number == step2)
			{
				PrimeCheck = true;
				PrimeExclusive = true;
			}
			if (((number%step1 == 0 && number != step1) || (number%step2 == 0 && number != step2))&& PrimeExclusive == false)
			{
				PrimeCheck = false;
			}
		}
	}
	if (PrimeCheck)
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
	std::cout << F(4) << std::endl;
	std::cout << F(0) << std::endl;
	std::cout << MyPower(4, -1) << std::endl;
	std::cout << MyPower(4, 0) << std::endl;
	std::cout << MyPower(0, 4) << std::endl;
	std::cout << MyPower(4, 3) << std::endl;
	std::cout << MyPower(2.3, 4) << std::endl;
	std::cout << MySqrt(4) << std::endl;
	std::cout << MySqrt(13) << std::endl;
	std::cout << MySqrt(2) << std::endl;
	std::cout << MySqrt(0) << std::endl;
	std::cout << (int)PrimeOrNot(1) << std::endl;
	std::cout << (int)PrimeOrNot(2) << std::endl;
	std::cout << (int)PrimeOrNot(4) << std::endl;
	std::cout << (int)PrimeOrNot(13) << std::endl;
	std::cout << (int)PrimeOrNot(412421) << std::endl;
	system("pause");
	return 0;
}
