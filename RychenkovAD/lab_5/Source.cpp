#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

void del(int** mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] mas[i];
	}
	delete[] mas;
}

void input_matrix(int** &mas, int n, int m)
{
	mas = new int*[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mas[i][j] = rand() % 15;
		}
	}
}

void output_matrix(int** &mas, int n, int m)
{
	cout << "=========================================" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
}

void matrix_mult(int** &mas1, int** &mas2, int** &resault, int n1, int n2, int m1, int m2)
{
		resault = new int*[n1];
		for (int i = 0; i < n1; i++)
		{
			resault[i] = new int[m2];
			for (int j = 0; j < m2; j++)
			{
				resault[i][j] = 0;
				for (int k = 0; k < m1; k++)
				{
					resault[i][j] += mas1[i][k] * mas2[k][j];
				}
			}
		}
		output_matrix(resault, n1, m2);
		del(resault, n1);
}

void matrix_sum(int** &mas1, int** &mas2, int** &resault, int n1, int m1, int n2, int m2)
{
		resault = new int*[n1];
		for (int i = 0; i < n1; i++)
		{
			resault[i] = new int[m1];
			for (int j = 0; j < m1; j++)
			{
				resault[i][j] = mas1[i][j] + mas2[i][j];
			}
		}
		output_matrix(resault, n1, m1);
		del(resault, n1);
}
void matrix_sub(int** &mas1, int** &mas2, int** &resault, int n1, int m1, int n2, int m2)
{
		resault = new int*[n1];
		for (int i = 0; i < n1; i++)
		{
			resault[i] = new int[m1];
			for (int j = 0; j < m1; j++)
			{
				resault[i][j] = mas1[i][j] - mas2[i][j];
			}
		}
		output_matrix(resault, n1, m1);
		del(resault, n1);
}


int main()
{
	setlocale(0, "rus");
	srand(time(NULL));
	int n1, m1, n2, m2;

	cout << "Введите размер первой матрицы: " << endl;
	cin >> n1 >> m1;
	int matrix1;
	int* pMatrix1 = &matrix1;
	int** ppMatrix1 = &pMatrix1;

	cout << "Введите размер второй матрицы: " << endl;
	cin >> n2 >> m2;
	int matrix2;
	int* pMatrix2 = &matrix2;
	int** ppMatrix2 = &pMatrix2;

	input_matrix(ppMatrix1, n1, m1);
	output_matrix(ppMatrix1, n1, m1);
	input_matrix(ppMatrix2, n2, m2);
	output_matrix(ppMatrix2, n2, m2);
	cout << "=========================================\n";

	int matrix3;
	int* pMatrix3 = &matrix3;
	int** ppMatrix3 = &pMatrix3;

	char ex;
	do
	{
		cout << "Выберите номер операции" << endl;
		cout << "1)A*B\n2)A+B\n3)A-B\n";
		int select;
		cin >> select;
		switch (select)
		{
		case(1):
		{
			if (m1 != n2)
			{
				cout << "=========================================\n" << "error: Количество столбцов первой матрицы не равно количеству количеству строк второй" << endl;
			}
			else
			{
				cout << "A*B= " << endl;
				matrix_mult(ppMatrix1, ppMatrix2, ppMatrix3, n1, n2, m1, m2);
			}
			break;
		}
		case(2):
		{
			if ((n1 != n2) || (m1 != m2))
			{
				cout << "=========================================\n" << "eror: Матрицы разного размера нельзя сложить" << endl;
			}
			else
			{
				cout << "A+B= " << endl;
				matrix_sum(ppMatrix1, ppMatrix2, ppMatrix3, n1, n2, m1, m2);
			}
			break;
		}
		case(3):
		{
			if ((n1 != n2) || (m1 != m2))
			{
				cout << "=========================================\n" << "error: Нельзя вычислить разность матриц разного размера" << endl;
			}
			else
			{
				cout << "A-B= " << endl;
				matrix_sub(ppMatrix1, ppMatrix2, ppMatrix3, n1, n2, m1, m2);
			}
			break;
		}
		default:
		{
			cout << "Введен некоректный номер операции\n";
		}
		}

		cout << "=========================================\n" << "Нажмите \"esc\" для завершения или любую другую кнопку для выбора операции" << endl;
		ex = _getch();
	} while (ex != 27);

	del(ppMatrix1, n1);
	del(ppMatrix2, n2);
	_getch();
}