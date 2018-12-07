#include<iostream>
using namespace std;
//int a, error, st, nam; // namber число, error для проверки ошибки, step степень
//double cor, rez; //rez это результат. cor корень
double Step(double st, double nam)
{
	double A = nam;
	if (st == 0) //если степень равна 0
	{
		return 1;
	}
	else // если степень не равна 0
	{
		if (st == 1) // если степень равна 1
		{
			return A;
		}
		else // если степень не равна 1 но и не равна 0
		{
			if (st > 0) // если степень > 0
			{
				int a;
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


int Fact(int nam) //факториал находится лишь для целой части
{
	long int F = nam;
	for (int f = F - 1; f > 0; f--)
	{
		F = F * f;
	}
	return F;
}

float Coren (double nam) // методом половиного деления
{

	double x1, x, C;
	x1 = 0;
	x = nam / 2;
	C = nam;

	while (x*x < C - 0.5 || x*x > C)//(x*x > C - 1 && x*x < C + 1) //(x*x != C ) //(x*x != C- 0,9 && x*x != C + 0,9 )//(x*x > C-1 && x*x < C+1)
	{// коментарий рядом с while это то как я пробовала задать интервал. Иногда работает но находит корень не правильно. 
		
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

int proverca(int nam)
{
	bool P = true;
	for (int i = 2; i < nam - 1; i++)
	{
		nam = (int)nam;
		if (nam%i == 0)
		{P = false;	} // ne prostoe
	}
	return P;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите число: ";
	double nam;
	cin >> nam; //if (namber = 0) {	cout << "Error" << endl;	} error = 1;
	cout << "Введите степень: ";
	int st;
	cin >> st;
	cout << nam << "^" << st << "=" << Step(st, nam) << endl;
	cout <<"Факториал (только целой части, если число дробное):"<< Fact(nam) << endl;
	cout <<"Корень:" << Coren(nam) << endl;
	cout <<"Проверка (0 - не простое, 1 - простое):" << proverca(nam) << endl; 
	system("pause");
	return 0;	
}
