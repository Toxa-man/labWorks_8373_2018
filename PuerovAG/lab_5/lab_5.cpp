#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
//#include<conio.h>
const int size = 4;
//const int n0 = 2;
//const int m1 = 2;
//const int  n1 = 2;
//const int  m2 = 2;
//const int  n2 = 2;

using namespace std;

//  /*
int matscan(int *a, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
	    for (j = 0;( j < n); j++)
		{
			cin >> *(a + i * m + j);
		}

	}
	return 0;
} 



void  matprint(int *a, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
	    for (j = 0; j < n ; j++)
		{
		    cout << *(a + i * m + j)<<" ";
		}
		cout<<endl;
	}
	
}

void summat(int *a, int *b, int *sum, int m, int n)
{
	int i, j;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			*(sum + i * m + j) = *(a + i * m + j) + *(b + i * m + j);
		}
	}
	
}


void prmat(int *a, int *b, int *pr, int m, int n, int l)
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
	
}


void matrazn(int *a, int*b, int*razn, int m, int n)
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
	
}

int main()
{
	int  a[size][size], b[size][size], c[size][size];
	int i, j,str1,stolb1,str2,stolb2;
	char s;
	do
	{
		cin >> s;
		cin>>str1>>stolb1>>str2>>stolb2;
		switch (s)
		{

		case '+':
			matscan(&a[0][0], str1, stolb1);
			matscan(&b[0][0], str2, stolb2);
			summat(&a[0][0], &b[0][0], &c[0][0], str1, stolb1);
			matprint(&c[0][0], str1, stolb1);
			break;

		case'-':
			matscan(&a[0][0], str1, stolb1);
			matscan(&b[0][0], str2, stolb2);
			matrazn(&a[0][0], &b[0][0], &c[0][0], str1, stolb1);
			matprint(&c[0][0], str1, stolb1);

		case'*':
			matscan(&a[0][0], str1, stolb1);
			matscan(&b[0][0], str2, stolb2);
			if (str1 != stolb2)
			{
			    cout << "strs of matrix isn't = "<<endl;
			}
			prmat(&a[0][0], &b[0][0], &c[0][0], str1, stolb1, stolb1);
			matprint(&c[0][0], str1, stolb1);
			break;
		default:
			cout << "wrong act ";
			break;

		}

		cout << endl;
	} while (getchar() != 'x');
	return 0;
}

