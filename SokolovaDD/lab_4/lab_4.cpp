#include <conio.h> 
#include<iostream>
using namespace std;
double stepen(int  num, int stp)
{
	double D = 1.0;
	if (stp == 0)
	{
		return D;
	}
	if (stp > 0)
	{
		for (int p = 1; p <= stp; p++)
		{

			D = D*num;
		}
		return D;
	}

	if (stp < 0)
	{
		for (int p = 1; p <= -stp; ++p)
		{

			D = D*num;
		}
		return (1.0 / D);
	}
}
int fact(int m)
{
	int o=1;
	if (m == 0)
	{
		return 1;
	}
		for (int i=1; i<= m; i++)
		{
			o =i*o;
		}
		return o;
}
int factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return n*factorial(n - 1);
}
double root( double ch)
{
	if (ch == 0)
	{
		return 0;
	}
	if (ch == 1)
	{
		return 1;
	}
	if (ch < 0)
	{
		return ch;
	}
	if (ch > 0)
	{
	        double ch_2;
		double otv = ch / 2;
		do
		{
			ch_2 = otv;
			otv = (ch_2 + ch / ch_2) / 2;
		} while (ch_2 - otv != 0);
		
		return otv;
	}
}
bool pr(int p)
{
	bool pro = true;
	if (p == 1)
	{
		pro = false;
	}
	for (int i = 2; i < p; i++)
	{
		if (p%i == 0)
		{
			pro = false;
		}

	}
	return pro;
}


int main()
{
	int num, st;
	cout << " stepen   :";
	cin >> num >> st;
	cout << stepen(num, st) << endl;
	int m;
	cout << "factorial   :";
	cin >> m;
	cout << fact(m) << endl;
	double n;
	cout << "root number :";
	cin >> n;
	cout << root(n) << endl;
	int p;
	cout << "prostoe?   " << endl;
	cin >> p ;
	if (pr(p) == true) {
		cout << "Prostoe" << endl;
	}
	else
	{
		cout << "Ne prostoe" << endl;
	}
	system("pause");
	return 0;
}
