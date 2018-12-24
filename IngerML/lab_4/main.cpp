#include<iostream>
using namespace std;

double Step(double st, double nam)
{
	double A = nam;
	if (st == 0) 
	{
		return 1;
	}
	else 
	{
		if (st == 1) 
		{
			return A;
		}
		else 
		{
			if (st > 0) 
			{
				double a;
				a = A;
				while (st > 1)
				{
					A = A * a;
					st = st - 1;
				}
				return A;
			}
		}
	}
}


int Fact(int nam) 
{
	long int F = nam;
	for (int f = F - 1; f > 0; f--)
	{
		F = F * f;
	}
	return F;
}

float Coren (double nam) 
{
	double x1, x, C;
	x1 = 0;
	x = nam / 2;
	C = nam;
	const double EPS = 0.001;
	while (fabs(C - x * x) > EPS ) 
	{
		x = (nam + x1) / 2;
		if (x*x > C)
		{
			nam = x;
		}
		else
		{
			x1 = x;
		}
	}
	return x;
}

bool proverca(int nam)
{
	
	for (int i = 2; i < nam - 1; i++)
	{
		nam = (int)nam;
		if (nam%i == 0)
		{
			return false;
		} 
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите число: ";
	double nam;
	cin >> nam; 
	cout << "Введите степень: ";
	int st;
	cin >> st;
	cout << nam << "^" << st << "=" << Step(st, nam) << endl;
	cout <<"Факториал (если число дробное  факториал береться только целой части ):"<< Fact(nam) << endl;
	cout <<"Проверка (0 - не простое, 1 - простое):" << proverca(nam) << endl; 
	cout <<"Корень:" << Coren(nam) << endl;
	system("pause");
	return 0;	
}
