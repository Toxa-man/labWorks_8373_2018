#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

void sum(int* a, int* b, int* c, int razm) {
	for (int i = 0; i < razm; i++) {
		for (int p = 0; p < razm; p++) {
			*(c + razm * i + p) = *(b + razm * i + p) + *(a + razm * i + p);
		}
	}
}

void sub(int* a, int* b, int* c, int size) {
	for (int i = 0; i < size; i++) {
		for (int p = 0; p < size; p++) {
			*(c + size * i + p) = *(a + size * i + p) - *(b + size * i + p);
		}
	}
}

void mult(int* a, int* b, int* c, int size) {
	for (int s = 0; s < size; s++) {
		for (int j = 0; j < size; j++) {
			for (int p = 0; p < size; p++) {
				*(c + s * size + j) += (*(a + s * size + p) * *(b + p * size + j));
			}
		}
	}
}

int main()
{
	const int n = 2;
	int matr1[n][n] = { {1,2},{3,4} };
	int matr2[n][n] = { {5,6},{7,8} };
	cout << "First matrix:" << endl;
	for (int i = 0; i < n; i++) {
		for (int p = 0; p < n; p++) {
			cout << matr1[i][p] << " ";
		}
		cout << endl;
	}
	cout << "Second matrix:" << endl;
	for (int i = 0; i < n; i++) {
		for (int p = 0; p < n; p++) {
			cout << matr2[i][p] << " ";
		}
		cout << endl;
	}
	char but = 1;
	char oper;
	while (but != 27) {
		int matr3[n][n] = { {0,0},{0,0} };
		bool bob = true;
		while (bob) {
			cout << "Enter operation: ";
			cin >> oper;
			switch (oper) {
			case '+': sum((int*)matr1, (int*)matr2, (int*)matr3, n);
				bob = false;
				break;
			case '-':sub((int*)matr1, (int*)matr2, (int*)matr3, n);
				bob = false;
				break;
			case '*': mult((int*)matr1, (int*)matr2, (int*)matr3, n);
				bob = false;
				break;
			default: cout << "Incorrect value" << endl;
			}
		}
		cout << "Result:" << endl;
		for (int i = 0; i < n; i++) {
			for (int p = 0; p < n; p++) {
				cout << matr3[i][p] << " ";
			}
			cout << endl;
		}
		cout << "Press 'esc' to exit or press another button to continue working" << endl;
		but = _getch();
	}
	_getch();
	return 0;
}