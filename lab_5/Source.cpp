#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int const m_size = 2;
int i, j, k;
int matrA[m_size][m_size] = { {1,3},{5,7} };
int matrB[m_size][m_size] = { {2,4},{6,8} };
int matrC[m_size][m_size];

void Multiplication()
{
	for (i = 0; i < m_size; i++) {
		for (j = 0; j < m_size; j++) {
			matrC[i][j] =0;
			for (k = 0; k < m_size; k++) {
				matrC[i][j] += matrA[i][k] * matrB[k][j];
			}
		}
	}

}

void Addition()
{
	for (i = 0; i < m_size; i++) {
		for (j = 0; j < m_size; j++) {
			matrC[i][j] = matrA[i][j] + matrB[i][j];
		}
	}
}

void Subtraction()
{
	for (i = 0; i < m_size; i++) {
		for (j = 0; j < m_size; j++) {
			matrC[i][j] = matrA[i][j] - matrB[i][j];
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choose;
	bool quit=false;
	char input=0;

	cout << "Матрица А:" << endl;
	for (i = 0; i < m_size; i++) {
		for (j = 0; j < m_size; j++) {
			cout << matrA[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;

	cout << "Матрица B:" << endl;
	for (i = 0; i < m_size; i++) {
		for (j = 0; j < m_size; j++) {
			cout << matrB[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;

	do {
		cout << "Выберете какую операцию провести с матрицами A и B." << endl;
		cout << "1 - Перемножение." << endl;
		cout << "2 - Сложение." << endl;
		cout << "3 - Вычитание." << endl << "Ваш выбор: ";
		cin >> choose;
		cout << endl;

		cout << "Матрица C ";
		switch (choose) {
		case 1:
			Multiplication();
			cout << "(равная произведению матриц A и B):";
			break;

		case 2:
			Addition();
			cout << "(равная сумме матриц A и B):";
			break;

		case 3:
			Subtraction();
			cout << "(равная вычитанию матриц A и B):";
			break;
		default:
			cout << "Ошибка: неправильный выбор операции." << endl;
			system("pause");
			return 0;
		}
		cout << endl;

		for (i = 0; i < m_size; i++) {
			for (j = 0; j < m_size; j++) {
				cout << matrC[i][j] << '\t';
			}
			cout << endl;
		}
		cout << endl;

		cout << "Чтобы выполнить еще одну операцию нажмите любую клавишу. Чтобы выйти из программы нажмите <<Esc>>." << endl;
		input = _getch();
		cout << endl;
	} while (input != 27);

	return 0;
}