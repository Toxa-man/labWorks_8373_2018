#include <iostream>
#include <conio.h>

using namespace std;

double Power(double ch, int st)
{
	double result = 1;
	for (int i = 0; i < st; i++)
	{
		result *= ch;
	}
	if (st < 0)
	{
		for (int i = st; i < 0; i++)
		{
			result /= ch;
		}
	}
	return result;
}

int Fact(int ch)
{
	int result = 1;
	for (int i = ch; i > 0; i--)
	{
		result *= i;
	}
	if (ch < 0)
	{
		return 0;
	}
	return result;
}

double Sqrt(double ch)
{
	double t;
	double result = ch / 2;

	do
	{
		t = result;
		result = (t + (ch / t)) / 2;

	} 
	while ((t - result) != 0);

	return result;
}

bool Prime(int ch)
{
	if (ch <= 1)
	{
		return false;
	}
	for (int i = 2; i <= Sqrt(ch); i++)
	{
		if (ch % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	double ch;
	int st;
	
	char sign;
	double result;
	cout << "Write a number: " << endl;
	cin >> ch;
	cout << "Write a power(for a power): " << endl;
	cin >> st;

	cout << "What do you want to do with a number? Write a sign. (Power - '^', Factorial - '!', Square - '$', Prime - '@')" << endl;
	cin >> sign;

	while (!(sign == '^' || sign == '!' || sign == '$' || sign == '@'))
	{
		cout << "This sign doesn't exist" << endl;
		cout << "Write a correct sign ";
		cin >> sign;
	}
	switch (sign)
	{
	case '^': 
		cout << ch << "^" << st << " = ";
		result = Power(ch, st);
		cout << result;
		break;
	case '!':
		if (ch < 0)
		{
			while (ch < 0)
			{
				cout << "The factorial of a negative number doesn't exist" << endl;
				cout << "Write a positive number: " << endl;
				cin >> ch;
			}
		}
		cout << "Factorial of " << ch << " is: ";
		result = Fact(ch);
		cout << result;
		break;
	case '$':
		if (ch < 0)
		{
			while (ch < 0)
			{
				cout << "The square of a negative number doesn't exist" << endl;
				cout << "Write a positive number: " << endl;
				cin >> ch;
			}
		}
		cout << "Square of " << ch << " is: ";
		result = Sqrt(ch);
		cout << result;
		break;
	case '@': 
		if (Prime(ch))
		{
			cout << ch << " is a prime number.";
		}
		if (!Prime(ch))
		{
			cout << ch << " is not a prime number.";
		}
		break;
	}
	_getch();
	return 0;
}