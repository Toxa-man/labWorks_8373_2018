#include <iostream>
#include <conio.h>

using namespace std;

const int SIZE = 100;

void sum_matrix(int* matrix1, int* matrix2, int* matrix_result)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			*(matrix_result + i*SIZE + j) = *(matrix1 + i*SIZE + j) + *(matrix2 + i*SIZE + j);
		}
	}
}

void dif_matrix(int* matrix1, int* matrix2, int* matrix_result)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			*(matrix_result + i*SIZE + j) = *(matrix1 + i*SIZE + j) - *(matrix2 + i*SIZE + j);
		}
	}
}

void mult_matrix(int* matrix1, int* matrix2, int* matrix_result, int column)
{
	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			*(matrix_result + i*SIZE + j) = 0;
			for (int p = 0; p < column; p++)
			{
				*(matrix_result + i*SIZE + j) += (*(matrix1 + i*SIZE + p) * *(matrix2 + p*SIZE + j));
			}
		}
	}
}

void outpoot(int* matrix, int row, int column)
{
	cout << endl << "Result matrix is: " << endl << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << *(matrix + i*SIZE + j) << " ";
		} 
		cout << endl;
	}
}

int main()
{
	char exit;
	do
	{
		system("cls");
		int row1, column1, row2, column2, matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], matrix_result[SIZE][SIZE];

		cout << "Enter the number of rows and columns of first matrix: " << endl
			<< "Rows: ";
		cin >> row1;
		cout << "Columns: ";
		cin >> column1;
		cout << endl;

		cout << "Write a matrix number 1: " << endl << endl;
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < column1; j++)
			{
				cin >> matrix1[i][j];
			}
		}
		cout << endl;

		cout << "Enter the number of rows and columns of second matrix: " << endl
			<< "Rows: ";
		cin >> row2;
		cout << "Columns: ";
		cin >> column2;
		cout << endl;

		cout << "Write a matrix number 2: " << endl << endl;
		for (int i = 0; i < row2; i++)
		{
			for (int j = 0; j < column2; j++)
			{
				cin >> matrix2[i][j];
			}
		}
		cout << endl;
		do
		{
			if (column1 == row2 && row1 != column2)
			{
				cout << endl << "I can only multiplicate this matrixes..." << endl
					<< "So... ";
				mult_matrix(*matrix1, *matrix2, *matrix_result, column1);
				outpoot(*matrix_result, row1, column2);
			}
			if (row1 == row2 && column1 == column2)
			{
				char sign;
				cout << "Please choose the sign. What you want to do with that matrixes?" << endl
					<< "Enter ('+' - to sum matrixes, '-' - to difference matrixes, '*' - to multilicate matrixes)" << endl
					<< "Sign: ";
				cin >> sign;

				while (!(sign == '+' || sign == '-' || sign == '*'))
				{
					cout << "I don't know this. Please enter correct sign" << endl
						<< "Sign: ";
					cin >> sign;
				}
				switch (sign)
				{
				case '+':
					sum_matrix(*matrix1, *matrix2, *matrix_result);
					outpoot(*matrix_result, row1, column1);
					break;
				case '-':
					dif_matrix(*matrix1, *matrix2, *matrix_result);
					outpoot(*matrix_result, row1, column1);
					break;
				case '*':
					mult_matrix(*matrix1, *matrix2, *matrix_result, column1);
					outpoot(*matrix_result, row1, column2);
					break;
				}
			}
			if (!(row1 == row2 && column1 == column2) || !(row1 == row2 && column1 == column2))
			{
				cout << endl << "It's impossible to do something with this matrixes..." << endl << endl
				<< "Press the 'ESC' to exit this program," << endl
			    << "or other button to enter the new matrixes." << endl << endl;
			}
			else
			{
				cout << endl << "Press the 'ENTER', if you want to do another action with matrixes," << endl
				<< "'ESC' to exit this program," << endl
				<< "or other button to enter the new matrixes." << endl << endl;
			}
			exit = _getch();

		} while (exit == 13);
			
	} while (exit != 27);

	return 0;
}