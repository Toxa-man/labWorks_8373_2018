#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

const int maxstrok=10, maxstolb=10;

void sum( int *ptrfirst, int *ptrsecond, int *ptrresult, int  i, int j)
{
	for (int M = 0; M < i; M++)
	{
		for (int L = 0; L < j; L++)
		{
			*(ptrresult + M*maxstrok + L) = *(ptrfirst + M*maxstrok + L) + *(ptrsecond + M*maxstrok + L);
		}
	}
}

void differense(int *ptrfirst, int *ptrsecond, int *ptrresult, int i, int j)
{
	for (int M = 0; M < i; M++)
	{
		for (int L = 0; L < j; L++)
		{
			*(ptrresult + M*maxstrok + L) = *(ptrfirst + M*maxstrok + L) - *(ptrsecond + M*maxstrok + L);
		}
	}
}
void umnoj(int *ptrfirst, int *ptrsecond, int *ptrresult, int p, int i, int j)
{
	for (int M = 0; M < i; M++)
	{
		for (int L = 0; L < j; L++)
		{
			for (int b = 0; b < p; b++)
			{
				*(ptrresult + M*maxstrok + L)+=*(ptrfirst + M*maxstrok + b)**(ptrsecond + b*maxstrok + L);
			}
		}
	}
}

int main()
{
	int firststroka, firststolb, secondstroka, secondstolb, resultstroka, resultstolb;
	int first[maxstrok][maxstolb];
	int second[maxstrok][maxstolb];
	int *ptrfirst = &first[0][0];
	int *ptrsecond = &second[0][0];
	char e, operation;
	do
	{
		int result[maxstrok][maxstolb] = { 0 };
		int *ptrresult = &result[0][0];
		cout << "write size of first matrix:" << endl;
		cin >> firststroka;
		cin >> firststolb;
		cout << "write size of second matrix:" << endl;
		cin >> secondstroka;
		cin >> secondstolb;

		cout << "write first matrix:" << endl;
		for (int k = 0; k < firststroka; k++)
		{
			for (int d = 0; d < firststolb; d++)
			{
				cin >> first[k][d];
			}
		}
		cout << endl;
		cout << "write second matrix:" << endl;
		for (int k = 0; k < secondstroka; k++)
		{
			for (int d = 0; d < secondstolb; d++)
			{
				cin >> second[k][d];
			}
		}
		cout << endl;
		if ((firststroka == secondstroka) && (firststolb == secondstolb) )
		{
			if (firststroka == secondstolb)
			{
				resultstroka = resultstolb = firststroka;
				cout << "write 1 for summ:" << endl << "write 2 for difference:" << endl << "write 3 dor umnojenie:" << endl;
				operation = _getch();
				switch (operation)
				{
				case('1') :
					sum(ptrfirst, ptrsecond, ptrresult, firststroka, firststolb);
					break;
				case('2') :
					differense(ptrfirst, ptrsecond, ptrresult, firststroka, firststolb);
					break;
				case('3') :
					umnoj(ptrfirst, ptrsecond, ptrresult, firststroka, firststroka, firststolb);
					break;
				}
			}
			else
			{
				resultstroka = firststroka;
				resultstolb = firststolb;
				cout << "write 1 for summ:" << endl << "write 2 for difference:" << endl;
				operation = _getch();
				switch (operation)
				{
				case('1') :
					sum(ptrfirst, ptrsecond, ptrresult, firststroka, firststolb);
					break;
				case('2') :
					differense(ptrfirst, ptrsecond, ptrresult, firststroka, firststolb);
					break;
				}
			}
		}
		else
		{
			if (firststolb == secondstroka)
			{
				if (firststroka == secondstolb)
				{
					cout << "write 1 to A*B:" << endl << "write 2 to B*A:" << endl;
					operation = _getch();
					switch (operation)
					{
					case('1') :
						resultstroka = firststroka;
						resultstolb = secondstolb;
						umnoj(ptrfirst, ptrsecond, ptrresult, firststroka, firststroka, secondstolb);
						break;
					case('2'):
						resultstroka = secondstroka;
						resultstolb = firststolb;
						umnoj(ptrsecond, ptrfirst, ptrresult, secondstroka, secondstroka, firststolb);
						break;
					}
				}
				else
				{
					cout << "A*B ";
					resultstroka = firststroka;
					resultstolb = secondstolb;
					umnoj(ptrfirst, ptrsecond, ptrresult, firststroka, firststroka, firststolb);
				}
			}
			else if (firststroka == secondstolb)
			{
				cout << "B*A ";
				resultstroka = secondstroka;
				resultstolb = firststolb;
				umnoj(ptrsecond, ptrfirst, ptrresult, firststroka, firststroka, firststolb);
			}
		}
		cout << "result:" << endl;
		for (int k = 0; k < resultstroka; k++)
		{
			for (int d = 0; d < resultstolb; d++)
			{
				cout << result[k][d] << " ";
			}
			cout << endl;
		}
		cout << "press esc to exit, if you want continue press another button:" << endl;
		e = _getch();
		cout << endl;
	}
	while (e != 27);
	system("pause");
    return 0;
}