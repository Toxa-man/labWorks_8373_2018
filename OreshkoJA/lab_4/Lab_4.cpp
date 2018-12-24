#include <iostream>
#include <conio.h>
using namespace std;
double deg(double fn, double dg)
{
	double help(0);
	double fn1 = fn;
	if (dg > 0)
	{
		if (dg == 1)
			return fn;
		else
		{
			while (dg - help != 1)
			{
				fn = fn*fn1;
				help++;
			}
			return fn;
		}
	}
	else
	{
		if (dg == 0)
		{
			fn = 0;
			return fn;
		}
		else 
		{
			while (dg + help != -1)
			{
				fn = fn*fn1;
				help++;
			}
			fn = 1 / fn;
			return fn;
		}
	}
}

int factor(int fact)
{
	int helper(1), final(1);
	while (helper != fact+1)
	{
		final = helper*final;
		helper++;
	}
	return final;
}
double sqrt(double sqr)
{
	double final1, final2, final3;
	double help;
	int dop(0), error(1), per1(1), k(0), con(0);
	help = sqr; 
	while (error == 1)
	{
		dop = help;
		while (dop > 0)
		{
			if (k == 0)
			{
				dop = dop - per1;
				k++;
				con++;
			}
			else
			{
				per1 = per1 + 2;
				dop = dop - per1;
				con++;
			}
		}
		error = 0;
	}
	if (dop == 0)
	{
		error = 0;
	}
	else
	{
		k = 0;
		per1 = 1;
		con = 0;
		error = 1;
	}
	while (error == 1)
	{ 
			--help;
			dop = help;
			while (dop > 0)
			{
				if (k == 0)
				{
					dop = dop - per1;
					k++;
					con++;
				}
				else
				{
					per1 = per1 + 2;
					dop = dop - per1;
					con++;
				}
			}
			if (dop == 0)
			{
				error = 0;
			}
			else
			{
				k = 0;
				per1 = 1;
				con = 0;
			}
	}
	if (sqr != 0)
	{
		final1 = (con+ sqr/con)/2;
		final2 = (final1 + sqr / final1)/2;
		final3 = (final2 + sqr / final2)/2;
		return final3;
	}
	else
	{
		return sqr;
	}
}
bool prav(int a)
{
	bool prav = true;
	for (int i = 2; i<a; i++) 
	{
		if (a%i == 0)
		{
			prav = false;
		}
	}
	return prav;
}
int main()
{
	cout << "First task." << endl;
	int fn, dg;
	cout << "Insert the number:";
	cin >> fn;
	cout << "Insert the degree:";
	cin >> dg;
	cout << fn << "^" << dg << "=" << deg(fn, dg) << endl;
	cout << "Second task." << endl;
	int fact;
	cout << "Insert the number:";
	cin >> fact;
	cout << fact << "!" << "=" << factor(fact) << endl;
	cout << "Third task." << endl;
	double sqr;
	cout << "Insert the number:";
	cin >> sqr;
	cout << "Root of" << sqr << "=" << sqrt(sqr) << endl;
	cout << "Forth task." << endl;
	int a;
	cout << "Insert the number:";
	cin >> a;
	if (prav(a) == 1)
	{
		cout << a << "-" << "Prostoe" << endl;
	}
	else
	{
		cout << a << "-" << "Ne prostoe" << endl;
	}
	system("pause");
}