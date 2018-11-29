#include <iostream>
#include <conio.h>

using namespace std;
enum def {error, prime, no_prime};


int negativ_number(double num)
{
	if (num < 0)
	{
		return error;
	}

}

double power(double number, int ind)
{
	
	double buf = 1;
	for (int i = 0; i < abs(ind); i++)
	{
		if (ind > 0)
		{
			buf *= number;
		}
		else if (ind < 0)
		{
			buf /= number;
		}
	}
	
	
	return buf;	
}

int fact(int num)
{
		switch (num)
		{
			case(0):
			{
				return 0;
				break;
			}

			case(1):
			{
				return 1;
				break;
			}

			default:
			{
				return num * fact(num - 1);
			}
	    }
}

double root(double x)
{ 
	if (x != 0)
	{
		double t;
		double mid = x / 2;
		do {
			t = mid;
			mid = (t + (x / t)) / 2;
		} while ((t - mid) != 0);
		return mid;
	}
	else return 0;
	
		
}


int simple(int number)
{
	if (number <= 1)
	{
		return error;
	}
	else
	{
		for (int i = 2; i <= number / 2; i++)
		{
			if (number % i == 0)
			{
				return no_prime;
			}
		}
		return prime;
	}
}



int main()
{
	setlocale(0, "rus");
	double N;
	cout << "Ведите число: ";
	cin >> N;
	int b;
	cout << "Ведите показатель степени числа: ";
	cin >> b;
	
	cout << "\n" << N << "^" << b << " = " << power(N, b) << endl;
	cout << "\n\nВведите число для взятия его факториала: ";
	int num;
	cin >> num;
	if (negativ_number(num) == error)
	{
		cout << "\nerror";		
	}
	else 
	{
		cout << "\n" << num << "!" << " = " << fact(num) << endl;
	}
	
	cout << "\n\nВведите число для извлечения его корня: ";
	cin >> N;
	if (negativ_number(N) == error)
	{
		cout << "\nerror";
	}
	else
	{
		cout << "\n" << N << "^(1/2)" << " = " << root(N) << endl;
	}

	
	cout << "\n\nВведите число для проверки на простоту: ";
	cin >> num;
	switch (simple(num))
	{
		case (error):
		{
			cout << "\nerror" << endl;
			break;
		}
		case (prime):
		{
			cout << "\nПростое" << endl;
			break;
		}
		case (no_prime):
		{
			cout << "\nСоставное" << endl;
			break;
		}
	}
	

}