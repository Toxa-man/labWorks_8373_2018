#include <iostream>
using namespace std;

void Sclad(int *Matrix1, int *Matrix2, int *Matrix3, int col1, int row1, int col2, int row2, const int siez)
{
	if (row1 == row2 && col1 == col2)
	{
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				*(Matrix3 + i * siez + j) = *(Matrix1 + i * siez + j) + *(Matrix2 + i * siez + j);

			cout << *(Matrix3 + i * siez + j) << "\t";
			}
			cout << endl;
		}
	}
	else { cout << "Нельзя складывать матрицы разных размеров"; }

}
void Raznost(int *Matrix1, int *Matrix2, int *Matrix3, int col1, int row1, int col2, int row2, const int siez)
{

	if (row1 == row2 && col1 == col2)
	{
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				*(Matrix3 + i * siez + j) = *(Matrix1 + i * siez + j) - *(Matrix2 + i * siez + j);

				cout << *(Matrix3 + i * siez + j) << "\t";
			}
			cout << endl;
		}
	}
}
void Umnoj(int *Matrix1, int *Matrix2, int *Matrix3, int col1, int row1, int col2, int row2, const int siez)
{
	if (col1 == row2)
	{
		int n = col1;
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				for (int k = 0; k < row2; k++)
				{
					*(Matrix3 + i * siez + j) += *(Matrix1 + i * siez + k) * *(Matrix2 + k * siez + j);
									
					if (k%2 == 1)
					{
						cout <<*(Matrix3 + i * siez + j) << "\t" ;
					}
				}
				
			}
			cout << endl;
		}
	}
	else { cout << "Для умножения матриц количество строк первой должно быть равно количеству столбцов второй"; }
}
int Func()
{

	setlocale(LC_ALL, "rus");
	const int siez = 20;
	int Matrix3[siez][siez];
	for (int i = 0; i < siez; i++)
	{
		for (int j = 0; j < siez; j++)
			Matrix3[i][j] = 0;
	}
	cout << "Число строк первой матрицы: "; //ввод количества строк 1 матрицы
	int row1; // ряды, строки, линии
	cin >> row1;
	cout << "Число столбцов первой матрицы:"; //ввод количества столбцов 1 матрицы
	int col1; // колонки, столбцы
	cin >> col1;
	cout << "Вводите матрицу A. Можно через пробел, можно через enter" << endl;
	int Matrix1 [siez][siez];
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
			cin >> Matrix1[i][j];
	}
		cout << "Вывод матрицы A \n";
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
			cout << Matrix1[i][j] << "\t";
		cout << endl;
	}
	cout << "Число строк второй матрицы: ";
	int row2;
	cin >> row2;
	cout << "Число столбцов второй матрицы:";
	int col2;
	cin >> col2;
	cout << "Вводите матрицу B. Можно через пробел, можно через enter" << endl;
	int Matrix2[siez][siez];
	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
			cin >> Matrix2[i][j];
	}
	cout << "Вывод матрицы B \n";
	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
			cout << Matrix2[i][j] << "\t";
		cout << endl;
	}
	cout << "Введите действие. '+', '-' или '*' : " << endl;
	char znac;
	cin >> znac;
	switch (znac)
	{
	case '+':
		cout << "Сумма: " << endl;
		Sclad(*Matrix1, *Matrix2, *Matrix3, col1, row1, col2, row2, siez);
		break;
	case '-':
		cout << "Разность: " << endl;
		Raznost(*Matrix1, *Matrix2, *Matrix3, col1, row1, col2, row2, siez);
		break;
	case '*':
		cout << "Произведение: " << endl;
		Umnoj(*Matrix1, *Matrix2, *Matrix3, col1, row1, col2, row2, siez);
		break;
	}
	cout << "Вы хотите повторить программу? Если да, введите '1' если нет введите '0'. Если вы введете 0, после нажмите любую клавишу 3 раза";
	int otvet;
	cin >> otvet;
	if (otvet == 1)
	{Func();}

	system("pause");
	return 0;
}
int main()
{
	Func();
	system("pause");
	return 0;
}
