#include "stdafx.h"
#include <iostream>
#include <iomanip>  
#include <conio.h>

using namespace std;

void my_add(int* arr1, int* arr2, int* arr3, int array1_height, int array1_weight, int &array3_height, int &array3_weight, const int N)
{
	array3_height = array1_height;
	array3_weight = array1_weight;
	for (int i = 0; i < array3_height; i++)
	{
		for (int j = 0; j < array3_weight; j++)
			*(arr3 + (i*N) + j) = *(arr1 + (i*N) + j) + *(arr2 + (i*N) + j);
	}
}

void my_sub(int* arr1, int* arr2, int* arr3, int array1_height, int array1_weight, int &array3_height, int &array3_weight, const int N)
{
	array3_height = array1_height;
	array3_weight = array1_weight;
	for (int i = 0; i < array3_height; i++)
	{
		for (int j = 0; j < array3_weight; j++)
			*(arr3 + (i*N) + j) = *(arr1 + (i*N) + j) - *(arr2 + (i*N) + j);
	}
}

void my_mult(int* arr1, int* arr2, int* arr3, int &array1_height, int &array1_weight, int &array2_height, int &array2_weight, int &array3_height, int &array3_weight, char actmult, const int N)
{
	if (actmult == '2')
	{
		swap(array1_height, array2_height);
		swap(array1_weight, array2_weight);
		swap(arr1, arr2);
	}
	array3_height = array1_height;
	array3_weight = array2_weight;
	for (int i = 0; i < array3_height; i++)
	{
		for (int j = 0; j < array3_weight; j++)
		{
			int sum = 0;
			for (int p = 0; p < array2_height; p++)
				sum += *(arr1 + (i*N) + p)**(arr2 + (p*N) + j);
			*(arr3 + (i*N) + j) = sum;
		}
	}
}

int main()
{
	const int N = 10;
	int array1_height, array2_height, array1_weight, array2_weight, array3_height, array3_weight;
	char act, actmult;
	setlocale(0, "");
	int arr1[N][N], arr2[N][N], arr3[N][N];
	cout << "ДЛЯ КОРРЕКТНОЙ РАБОТЫ ПРОГРАММЫ ОГРАНИЧИВАЙТЕ РАЗМЕР МАССИВОВ ДО " << N << " НА " << N << " СТРОК!" << endl << endl;
	do {
		cout << "Введите количество строк первого массива: ";
		cin >> array1_height;
		cout << "Введите количество столбцов первого массива: ";
		cin >> array1_weight;
		for (int i = 0; i < array1_height; i++)
		{
			cout << "Введите " << i + 1 << "-ую строку первого массива: ";
			for (int j = 0; j < array1_weight; j++)
				cin >> arr1[i][j];
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Введите количество строк второго массива: ";
		cin >> array2_height;
		cout << "Введите количество столбцов второго массива: ";
		cin >> array2_weight;
		for (int i = 0; i < array2_height; i++)
		{
			cout << "Введите " << i + 1 << "-ую строку первого массива: ";
			for (int j = 0; j < array2_weight; j++)
				cin >> arr2[i][j];
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << endl << "Выберите требуемое действие:" << endl << "1 - сложение матриц" << endl << "2 - вычитание матриц" << endl << "3 - умножение матриц" << endl;
		act = '0';
		act = _getch();
		switch (act)
		{
		case '1':
			if ((array1_height == array2_height) && (array1_weight == array2_weight))
				my_add(*arr1, *arr2, *arr3, array1_height, array1_weight, array3_height, array3_weight, N);
			else
				cout << "Размеры матриц не совпадают. Попробуйте еще раз.";
			break;
		case '2':
			if ((array1_height == array2_height) && (array1_weight == array2_weight))
				my_sub(*arr1, *arr2, *arr3, array1_height, array1_weight, array3_height, array3_weight, N);
			else
				cout << "Размеры матриц не совпадают. Попробуйте еще раз.";
			break;
		case '3':
			cout << endl << "Выберите тип умножения: " << endl << "1 - A*B" << endl << "2 - B*A" << endl;
			actmult = _getch();
			if (actmult == '1')
			{
				if (array2_height == array1_weight)
					my_mult(*arr1, *arr2, *arr3, array1_height, array1_weight, array2_height, array2_weight, array3_height, array3_weight, actmult, N);
				else
					cout << "Размеры матриц не позволяют выполнить умножение. Попробуйте еще раз.";
				break;
			}
			else if (actmult == '2')
			{
				if (array1_height == array2_weight)
					my_mult(*arr1, *arr2, *arr3, array1_height, array1_weight, array2_height, array2_weight, array3_height, array3_weight, actmult, N);
				else
					cout << "Размеры матриц не позволяют выполнить умножение. Попробуйте еще раз.";
				break;
			}
			else
				cout << "Неверная клавиша. Попробуйте еще раз." << endl;
			break;
		default:
			cout << "Неверная клавиша. Попробуйте еще раз." << endl;
			continue;
		}
		cout << endl << "Ваш ответ: " << endl;
		for (int i = 0; i < array3_height; i++)
		{
			for (int j = 0; j < array3_weight; j++)
				cout << setw(10) << right << arr3[i][j];
			cout << endl;
		}
		cout << "Для выхода нажмите ESC, для продолжения - любую другую клавишу" << endl << endl;
		act = _getch();
	} while (act != 27);
	return 0;
}

