//как вывести результат в виде матрицы
//зациклить все
#include <iostream>
#include <conio.h>
using namespace std;
const int size = 100;
void Sum(int* matrix1 ,int* matrix2 , int* matrix3, int stolbets1, int stroka1, int stolbets2, int stroka2, int* stolbets3, int* stroka3,  int size)
{ 	
		*stolbets3 = stolbets1;
		*stroka3 = stroka1;
		for (int i = 0; i < *stroka3; i++)
		{
			for (int j = 0; j < *stolbets3; j++)
			{
				*(matrix3 + i * size + j) = *(matrix1 + i * size + j) + *(matrix2 + i * size + j);
			}
		}
	
}
void Sub(int* matrix1, int* matrix2, int* matrix3, int stolbets1, int stroka1, int stolbets2, int stroka2, int* stolbets3, int* stroka3, int size)
{
		*stroka3 = stroka1;
		*stolbets3 = stolbets1;

		for (int i = 0; i < *stroka3; i++)
		{
			for (int j = 0; j < *stolbets3; j++)
			{
				*(matrix3 + (i * size) + j) = *(matrix1 + (i * size) + j) - *(matrix2 + (i * size) + j);
			}
		}
	
}
void Mult(int* matrix1, int* matrix2, int* matrix3, int stolbets1, int stroka1, int stolbets2, int stroka2, int* stolbets3, int* stroka3, int size)
{		
			*stroka3 = stroka1;
			*stolbets3 = stolbets2;

			for (int i = 0; i < *stroka3; i++)
			{
				for (int j = 0; j < *stolbets3; j++)
				{
					*(matrix3 + i * size + j) = 0;
					for (int k = 0; k < stroka2; k++)
					{
						*(matrix3 + i * size + j) += *(matrix1 + i * size + k) * *(matrix2 + k * size + j);

					}
				}
			}
	
}
int main()
{
	const int size = 10;
	int matrix1[size][size], matrix2[size][size], matrix3[size][size];
	int stolbets1, stolbets2, stolbets3, stroka1, stroka2, stroka3, k;
	bool todo = false;
	char c;
	cout << "Enter height and width of first matrix" << endl;
	cin >> stolbets1;
	cin >> stroka1;
	cout << "Enter numbers of first matrix" << endl;
	for (int i = 0; i < stroka1; i++)
	{
		for (int j = 0; j < stolbets1; j++)
		{
			cin >> matrix1[i][j];
		}
	}
	cout << "Enter height and width of second matrix" << endl;
	cin >> stolbets2;
	cin >> stroka2;
	cout << "Enter numbers of second matrix" << endl;
	for (int i = 0; i < stroka2; i++)
	{
		for (int j = 0; j < stolbets2; j++)
		{
			cin >> matrix2[i][j];
		}
	}
	const char ESC =27;
	do {
		cout << "\nChoose an action:\n '+' for summation\n '-' for substraction\n '*' for multiplication\n ESC for exit\n" << endl;
		k = _getch();
		switch (k)
		{
		case '+':
			if (stolbets1 == stolbets2 && stroka1 == stroka2)
			{
				todo = true;
			}
			else
			{
				cout << "Operation is impossible" << endl;
				system("pause");
				return 0;
			}
			Sum(*matrix1, *matrix2, *matrix3, stolbets1, stroka1, stolbets2, stroka2, &stolbets3, &stroka3, size);
			break;
		case '-':
			if (stolbets1 == stolbets2 && stroka1 == stroka2)
			{
				todo = true;
			}
			else 
			{
				cout << "Operation is impossible" << endl;
				system("pause");
				return 0;
			}
			Sub(*matrix1, *matrix2, *matrix3, stolbets1, stroka1, stolbets2, stroka2, &stolbets3, &stroka3, size);
		  	    break;
		    
		case '*':
			if (stolbets1 == stroka2)
			{
				todo = true;
			}
			else
			{
				cout << "Operation is impossible" << endl;
				system("pause");
				return 0;
			}
		
			Mult(*matrix1, *matrix2, *matrix3, stolbets1, stroka1, stolbets2, stroka2, &stolbets3, &stroka3, size);
				break;
			
		case ESC: 
			return 0;

		default: cout << "Wrong sign. Repeat\n";
			break;
		}
		if (todo)
		{
			cout << "Result: ";
			for (int i = 0; i < stroka3; ++i)
			{
				for (int j = 0; j < stolbets3; ++j)
				{
					cout << matrix3[i][j] << ' ';

				}
			}
			cout << endl;

			todo = false;
			system("pause");
		}
		c = _getch();
	} while (c!=ESC);
	return 0;
}

