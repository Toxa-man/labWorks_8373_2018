#include <iostream>
#include <conio.h> 
using namespace std;

float stepen(float a, int b)
{
	float result=1;
	if (!a)
	{
		result = 0;
	}
	else if (b > 0)
	{
		for (int i = 0; i < b; i++)
		{
			result = result*a;
		}
	}
	else if (b < 0)
	{
		for (int i = 0; i > b; i--)
		{
			result = result*a;
		}
		result = 1 / result;
	}
	return result;
}
unsigned int factorial(unsigned int a)
{
	unsigned int factorial = 1;
	while (a > 0)
	{
		factorial *= a;
		--a;
	}
	return factorial;
}
bool prost(unsigned int t)
{
	bool result = false;
	for (int i = 2; i < t; i++)
	{
		if (t%i == 0)
		{
			result = true;
			break;
		}
	}
	return result;
}
float coren(float a)
{
	int count = 0;
	while (float(int(a))!=a)
	{
		a = a * 100;
			++count;
	}
	int st1, st2;
	float coren;
	for (int i = 1; i <= a; i++)
	{
		st1 = stepen(i, 2);
		st2 = stepen(i + 1, 2);
		if (st2 > a)
		{
			coren = i;
			break;
		}
	}
	coren = 0.5*(coren + a / coren);
	coren = 0.5*(coren + a / coren);
	coren = 0.5*(coren + a / coren);
	coren = coren / stepen(10, count);
	return coren;
}
int main()
{
	setlocale(0, "");
	float number1;
	int step;
	cout << "Введите для возведения в степень: ";
	cin >> number1;
	cout << "Введите степень: ";
	cin >> step;
	cout << "Результат: ";
	if (number1 || step)
	{
		cout << stepen(number1, step) << endl;
	}
	else 
	{
		cout << "Неопределенность" << endl;
	}
	unsigned int number2;
	cout << "Введите число для нахождения факториала и проверки на простоту: ";
	cin >> number2;
	cout << "Факториал: " << factorial(number2) << endl;
	if (prost(number2))
	{
		cout << "Число не является простым" << endl;
	}
	else
	{
		cout << "Простое число" << endl;
	}
	float number3;
	cout << "Введите число для поиска квадратного корня: ";
	cin >> number3;
	cout << "Результат: " << coren(number3) << endl;
	_getch();
	return 0;
}