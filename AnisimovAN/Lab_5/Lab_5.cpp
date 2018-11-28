#include "stdafx.h"
#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

void matrix_sum(int* matrix1, int* matrix2, int* result, int n, int m)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			*(result + i * 20 + j) = *(matrix1 + i * 20 + j) + *(matrix2 + i * 20 + j);
}

void matrix_difference(int* matrix1, int* matrix2, int* result, int n, int m)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			*(result + i * 20 + j) = *(matrix1 + i * 20 + j) - *(matrix2 + i * 20 + j);
}

void matrix_mult(int* matrix1, int* matrix2, int* result, int N, int M, int S)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < S; j++)
		{
			for (int z = 0; z < M; z++)
			{
				*(result + i * 20 + j) += (*(matrix1 + i * 20 + z))*(*(matrix2 + z * 20 + j));
			}
		}
	}
}

int main()
{
	cout << "Welcome to the matrix calculator. Press any button to continue. \n" << endl;

	while ((_kbhit() == 0) && (_getch() != 27))
	{

		setlocale(LC_ALL, "RUS");

		int i, j, N, M, S, K, mat_A[20][20], mat_B[20][20], mat_C[20][20] = {0};

		char sign;

		cout << "Write a number of strings in matrix A (less then 21): ";
		cin >> N;
		cout << endl;

		if (N > 20) {
			do {
				cout << "Error! Number of strings is too big, please write another one: " << endl;
				cin >> N;
			} while (N > 20);
		}

		cout << "Write a number of columns in matrix A (less then 21): ";
		cin >> M;
		cout << endl;

		if (M > 20) {
			do {
				cout << "Error! Number of columns is too big, please write another one: " << endl;
				cin >> M;
			} while (M > 20);
		}

		cout << "Write elements of matrix A: \n";
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				cin >> mat_A[i][j];
			}
		}
		cout << endl;

		cout << "Matrix A \n";
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				cout << mat_A[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;

		cout << "Write a number of strings in matrix B (less then 21): ";
		cin >> S;
		cout << endl;

		if (S > 20) {
			do {
				cout << "Error! Number of strings is too big, please write another one: " << endl;
				cin >> S;
			} while (S > 20);
		}

		cout << "Write a number of columns in matrix B (less then 21): ";
		cin >> K;
		cout << endl;

		if (K > 20) {
			do {
				cout << "Error! Number of columns is too big, please write another one: " << endl;
				cin >> K;
			} while (K > 20);
		}

		cout << "Write elements of matrix B: \n";
		for (i = 0; i < S; i++)
		{
			for (j = 0; j < K; j++)
			{
				cin >> mat_B[i][j];
			}
		}
		cout << endl;

		cout << "Matrix B \n";
		for (i = 0; i < S; i++)
		{
			for (j = 0; j < K; j++)
			{
				cout << mat_B[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;

		cout << "Write a sign of operation (sum ' + ', dif ' - ', mult ' * ') : ";
		cin >> sign;
		cout << endl;

		if (sign != '+' && sign != '-' && sign != '*') {
			do {
				cout << "Error! Wrong sign, please write another one: " << endl;
				cin >> sign;
			} while (sign != '+' && sign != '-' && sign != '*');
		}
		switch (sign)
		{
		case '+': if (N == S && M == K)
		{
			matrix_sum(*mat_A, *mat_B, *mat_C, N, M);
			cout << "Matrix C \n";
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < M; j++)
				{
					cout << mat_C[i][j] << "\t";
				}
				cout << endl;
			}
		}
				  else
		{
			cout << "Error: different number of strings or columns." << endl;
		}

				  break;

		case '-': if (N == S && M == K)
		{
			matrix_difference(*mat_A, *mat_B, *mat_C, N, M);
			cout << "Matrix C \n";
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < M; j++)
				{
					cout << mat_C[i][j] << "\t";
				}
				cout << endl;
			}
		}
				  else
		{
			cout << "Error: different number of strings or columns." << endl;
		}
				  break;

		case '*': if (N == K)
		{
			matrix_mult(*mat_A, *mat_B, *mat_C, N, M, S);
			cout << "Matrix C \n";
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < M; j++)
				{
					cout << mat_C[i][j] << "\t";
				}
				cout << endl;
			}
		}
				  else
		{
			cout << "Error: number of strings in 1'st Matrix is not the same as number of columns in 2'nd Matrix." << endl;
		}

				  break;
		}
		cout << endl;
		cout << "--------------------------------END--------------------------------" << endl;
		cout << endl;

		cout << "Are you sure you want to quit this great program? (Press 'ESC' button to leave or another to continue)" << endl;

		system("pause");
		return 0;
	}
}

