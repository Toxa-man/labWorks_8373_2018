#include <iostream>
#include <conio.h>

using namespace std;

const int max_size = 10;

struct Matrix {
	int row_num;
	int col_num;
	double matrix[max_size][max_size] = { 0 };
};

void num_input(int &a, char* str) {
	bool incorrect_size = false;
	do {
		cout << str << endl;
		incorrect_size = false;
		cin >> a;
		cin.clear();
		cin.ignore(1000, '\n');
		if (a < 1) {
			cout << "Error: the number should be positive" << endl;
			incorrect_size = true;
		}
		if (a > max_size) {
			cout << "Error: the number can't exceed " << max_size << endl;
			incorrect_size = true;
		}
	} while (incorrect_size);
}

void mat_input(Matrix &m, char* name) {
	cout << endl << "Enter " << name << " matrix " << '[' << m.row_num << "x" << m.col_num << "]" << endl;
	for (int i = 0; i < m.row_num; i++) {
		for (int j = 0; j < m.col_num; j++) {
			cin >> m.matrix[i][j];
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}
}

Matrix sum_matrix(const Matrix& A, const Matrix& B) {
	Matrix C;
	C.row_num = A.row_num;
	C.col_num = A.col_num;
	for (int i = 0; i < C.row_num; i++) {
		for (int j = 0; j < C.col_num; j++) {
			C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
		}
	}
	return C;
}

Matrix diff_matrix(const Matrix& A, const Matrix& B) {
	Matrix C;
	C.row_num = A.row_num;
	C.col_num = A.col_num;
	for (int i = 0; i < C.row_num; i++) {
		for (int j = 0; j < C.col_num; j++) {
			C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
		}
	}
	return C;
}

Matrix mult_matrix(const Matrix& A, const Matrix& B) {
	Matrix C;
	C.row_num = A.row_num;
	C.col_num = B.col_num;
	for (int i = 0; i < C.row_num; i++) {
		for (int j = 0; j < C.col_num; j++) {
			for (int p = 0; p < A.col_num; p++) {
				C.matrix[i][j] += A.matrix[i][p] * B.matrix[p][j];
			}
		}
	}
	return C;
}

void print_matrix(const Matrix& A) {
	for (int i = 0; i < A.row_num; i++) {
		for (int j = 0; j < A.col_num; j++) {
			cout << A.matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	Matrix A, B;
	bool repeat = true;

	while (repeat) {
		num_input(A.row_num, "Enter the number of rows of first matrix");
		num_input(A.col_num, "Enter the number of columns of first matrix");
		num_input(B.row_num, "Enter the number of rows of second matrix");
		num_input(B.col_num, "Enter the number of columns second matrix");

		bool ApB = A.row_num == B.row_num && A.col_num == B.col_num;
		bool AxB = A.col_num == B.row_num;
		bool no_op = false;
		if (ApB || AxB) {
			mat_input(A, "the first");
			mat_input(B, "the second");
			cout << "Type:" << endl;
			if (ApB) {
				cout << "'+' for addition" << endl;
				cout << "'-' for substraction" << endl;
			}
			if (AxB) {
				cout << "'*' for multiplication" << endl;
			}
		}
		else {
			cout << "No operations avaliable for matrices of chosen sizes" << endl << endl;
			no_op = true;
		}

		if (!no_op) {
			char operation;
			cin >> operation;
			cin.clear();
			cin.ignore(1000, '\n');
			bool wrong_char = false;
			switch (operation) {
			case '+':
				if (ApB) {
					cout << "Result matrix:" << endl;
					print_matrix(sum_matrix(A, B));
					break;
				}
				else {
					wrong_char = true;
					break;
				}
			case '-':
				if (ApB) {
					cout << "Result matrix:" << endl;
					print_matrix(diff_matrix(A, B));
					break;
				}
				else {
					wrong_char = true;
					break;
				}
			case '*':
				if (AxB) {
					cout << "Result matrix:" << endl;
					print_matrix(mult_matrix(A, B));
					break;
				}
				else {
					wrong_char = true;
					break;
				}
			default:
				wrong_char = true;
				break;
			}

			if (wrong_char) {
				cout << "Wrong operation symbol";
			}
		}
		cout << "Press Esc to exit the programm or any other button to continue" << endl;
		char exit = _getch();
		if (exit == 27) {
			repeat = false;
		}
		cout << endl;
	}
}