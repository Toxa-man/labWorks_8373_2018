#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
//#include<conio.h>
const int m0 = 2;
const int n0 = 2;
const int m1 = 2;
const int  n1 = 2;
const int  m2 = 2;
const int  n2 = 2;

using namespace std;

int matscan(int *a, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> *(a + i * m + j);
		}

	}
	return 0;
}

int matprint(int *a, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
		    cout << *(a + i * m + j)<<" ";
		}
		cout<<endl;
	}
	return 0;
}

int summat(int *a, int *b, int *sum, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			*(sum + i * m + j) = *(a + i * m + j) + *(b + i * m + j);
		}
	}
	return 0;
}


int prmat(int *a, int *b, int *pr, int m, int n, int l)
{
	int i, j, k, c;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < l; j++)
		{
			for (k = 0; k < m; k++)
			{
				*(pr + i * m + j) += *((a + i * n + k))*(*(b + j * l + k)); 

			}
		}
	}
	return 0;
}


int matrazn(int *a, int*b, int*razn, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			*(b + i * m + j) *= -1;
		}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				*(razn + i * m + j) = *(a + i * m + j) + *(b + i * m + j);
			}
		}

	}
	return 0;
}

int main()
{
	int  a[m0][n0], b[m1][n1], c[m2][n2];
	int i, j;
	char s;
	do
	{
		cin >> s;
		switch (s)
		{

		case '+':
			matscan(&a[0][0], m0, n0);
			matscan(&b[0][0], m0, n0);
			summat(&a[0][0], &b[0][0], &c[0][0], m0, n0);
			matprint(&c[0][0], m0, n0);
			break;

		case'-':
			matscan(&a[0][0], m0, n0);
			matscan(&b[0][0], m1, n1);
			matrazn(&a[0][0], &b[0][0], &c[0][0], m0, n0);
			matprint(&c[0][0], m0, n0);

		case'*':
			matscan(&a[0][0], m0, n0);
			matscan(&b[0][0], m0, n0);
			if (m0 != n1)
			{
				cout << "strs of matrix isn't = ";
			}
			prmat(&a[0][0], &b[0][0], &c[0][0], m0, n0, n1);
			matprint(&c[0][0], m0, n0);
			break;
		default:
			cout << "wrong act ";
			break;

		}

		cout << endl;
	} while (getchar() != 'x');
	return 0;
}

