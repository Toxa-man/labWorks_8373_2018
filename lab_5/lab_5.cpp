#include <iostream> 
#include <conio.h>
#include <iomanip>
const int cont = 10;
using namespace std;

void  sum(int *matr1, int *matr2, int *otv, int str, int st)
{
	
	for (int j = 0; j < str; j++)
	{
		for (int i = 0; i < st; i++)
		{
			*(otv+j*cont+i)= *(matr1 + j*cont + i) + *(matr2 + j*cont + i);
		}
	}
	
}
void  min(int *matr1, int *matr2, int *otv, int str, int st)
{
	
	for (int j = 0; j < str; j++)
	{
		for (int i = 0; i < st; i++)
		{
			*(otv + j*cont + i) = *(matr1 + j*cont + i) - *(matr2 + j*cont + i);
		}
	}
}
void pr(int*matr1,int *matr2,int *otv, int str1)
{
	for (int i = 0; i < cont; i++)
	{
		for (int j = 0; j < cont; j++)
		{
			*(otv + (cont*i) + j) = 0;
			for (int k = 0; k < str1; k++) {
				*(otv + cont*i + j) += *(matr1 + (cont*i) + k)**(matr2 + (cont*k) + j);
			}
			

		}
	}
}

int main()
{
	int str1, st1, str2, st2;
	int matr1[cont][cont];
	int matr2[cont][cont];
	int otv[cont][cont];
	char key;
	cout << "size  row 1st matrix :";
	cin >> str1;
	cout << endl;
	cout << " size  column  1st matrix   :";
	cin >> st1;
	cout << endl;
	cout << "size  row 2nd matrix :";
	cin >> str2;
	cout << endl;
	cout << " size  column  2nd matrix   :";
	cin >> st2;
	cout << endl;

	cout << "enter the values of the first matrix  :   ";
	for (int i = 0; i < str1; i++)
	{
		for (int j = 0; j < st1; j++)
		{
			cin >> matr1[i][j];
		}
	}
	cout << endl;
	cout << "enter the values of the second matrix  :   ";
	for (int i = 0; i < str2; i++)
	{
		for (int j = 0; j < st2; j++)
		{
			cin >> matr2[i][j];
		}
	}
	cout << endl;
	cout << "enter 1 if the multiplication , 2 if the Subtract ,3 if the sum(Press Esc for finish)" << endl;
	do {
		key = _getch();
		switch (key)
		{
		case'1':
			if (str1 == st2)
		{
			pr(*matr1, *matr2, *otv, str1);
			cout << "Matrix multiplication  \n";
			for (int i = 0; i < str1; i++)
			{
				for (int j = 0; j < st2; j++)
				{
					cout << otv[i][j] << "\t";
				}
				cout << endl;
			}
		}
				else
				{
					cout << "Error! different number of row 1st and column 2nd" << endl;
				}

				break;
			
		case '2':
			if (str1 == str2 && st1 == st2)
		{
			min(*matr1, *matr2, *otv, str1, st1);
			cout << "Matrix Subtract  \n";
			for (int i = 0; i < str1; i++)
			{
				for (int j = 0; j < st2; j++)
				{
					cout << otv[i][j] << "\t";
				}
				cout << endl;
			}
		}
				else
				{
					cout << "Error! different number of row or columns" << endl;
				}

				break;
		case '3':
			if (str1 == str2 && st1 == st2)
			{
				sum(*matr1, *matr2, *otv, str1, st1);
				cout << "Matrix sum  \n";
				for (int i = 0; i < str1; i++)
				{
					for (int j = 0; j < st2; j++)
					{
						cout << otv[i][j] << "\t";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "Error! different number of row or columns" << endl;
			}
			break; 
		}
	} while (key != 27);
		key = _getch();
		return 0;
 }
