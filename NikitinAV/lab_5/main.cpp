#include <iostream>
#include <conio.h>
using namespace std;
const int s= 10;
// ************* SUM **************
void matsum(int &result_matrix_columns,int &result_matrix_lines,int *result,int matrix1_lines, int matrix2_lines, int matrix1_columns, int matrix2_columns, int* matrix1, int* matrix2)
{ 
	if (matrix1_lines == matrix2_lines && matrix1_columns == matrix2_columns) {
		result_matrix_columns = matrix1_columns;
		result_matrix_lines = matrix1_lines;
		for (int i = 0; i < result_matrix_lines; i++) {
			for (int j = 0; j < result_matrix_columns; j++	) {
				*(result+(i*s)+j) = *(matrix1+j+(i*s)) + *(matrix2+j+(i*s));
			}
		}
	}
}
// ********** SUB ************
void matsub(int &result_matrix_columns, int &result_matrix_lines, int *result, int matrix1_lines, int matrix2_lines, int matrix1_columns, int matrix2_columns, int* matrix1, int* matrix2) {
	if (matrix1_lines == matrix2_lines && matrix1_columns == matrix2_columns) {
		result_matrix_columns = matrix1_columns;
		result_matrix_lines = matrix1_lines;
		for (int i = 0; i < result_matrix_lines; i++) {
			for (int j = 0; j < result_matrix_columns; j++) {
				*(result + i*s + j) = *(matrix1 + j + i*s) - *(matrix2 + j + i*s);
			}
		}
	}
}
// ********** MULTI ************
void matmulti(int &result_matrix_columns, int &result_matrix_lines, int *result, int matrix1_lines, int matrix2_lines, int matrix1_columns, int matrix2_columns, int* matrix1, int* matrix2) {
	if (matrix1_columns == matrix2_lines)
	{
		result_matrix_lines = matrix1_lines;
		result_matrix_columns = matrix2_columns;
		for (int i = 0; i < result_matrix_lines; i++) {
			for (int j = 0; j < result_matrix_columns; j++) {
				*(result + j + i * s) = 0;
				for (int z = 0; z < matrix1_columns; z++) {
					*(result + j + i * s) += *(matrix1 + z + i * s)* *(matrix2 + j + z * s);
				}

			}
		}
	}
}
int main() {
	int i, j;
	int matrix1_lines, matrix2_lines, matrix1_columns, matrix2_columns;
	int result[s][s];
	int result_matrix_lines;
	int result_matrix_columns;
	int matrix2[s][s];
	int matrix1[s][s];
	char k; // sign
	char key;// exit check
	do {
		cout << "type needed number of lines of ur first matrix\n";
		cin >> matrix1_lines;
		cout << "type needed number of columns of ur first matrix\n";
		cin >> matrix1_columns;
		cout << "type elements of ur first matrix\n";
		for (int i = 0; i < matrix1_lines; i++) {
			for (int j = 0; j < matrix1_columns; j++) {
				cin >> matrix1[i][j];
			}
		}
		cout << "type needed number of lines of ur second matrix\n";
		cin >> matrix2_lines;
		cout << "type needed number of columns of ur second matrix\n";
		cin >> matrix2_columns;
		cout << "type elements of ur second matrix\n";
		for (int i = 0; i < matrix2_lines; i++) {
			for (int j = 0; j < matrix2_columns; j++) {
				cin >> matrix2[i][j];
			}
		}
		do {
			if (matrix1_lines == matrix2_lines && matrix1_columns == matrix2_columns&&matrix1_columns==matrix2_lines) {
				cout << "Its possible to fold,subtract and multiply ur matrix\n";
			}
			else {
				if (matrix1_columns == matrix2_lines) {
					cout << "Its only possible to multiply ur matrixes\n";
				}
				else {
					if (matrix1_lines == matrix2_lines && matrix1_columns == matrix2_columns) {
						cout << "Its only possible to fold or subtract ur matrixes\n";
					}
				}
			}
			i = 0;
			j = 0;
			cout << "Type + for sum, - for subtract and * for mulitplication\n";
			cin >> k;
			while (!(k == '+' || k == '-' || k == '*')) {
				cout << "wrong sign, try it again\n";
				cin >> k;
			}
			switch (k) {
			case '+':
				if (!(matrix1_lines == matrix2_lines && matrix1_columns == matrix2_columns)) {
					cout << "Its impossible to fold ur matrixes\n";
				}

				else {
					matsum(result_matrix_columns, result_matrix_lines, *result, matrix1_lines, matrix2_lines, matrix1_columns, matrix2_columns, *matrix1, *matrix2);
					for (int i = 0; i < matrix1_lines; i++) {
						for (int j = 0; j < matrix1_columns; j++) {
							cout << result[i][j] << " ";
							if (j == result_matrix_columns - 1) {
								cout << endl;
							}
						}
					}
				}
				break;
			case '-':
				if (!(matrix1_lines == matrix2_lines && matrix1_columns == matrix2_columns)) {
					cout << "Its impossible to subtract ur matrixes\n";
				}

				else {
					matsub(result_matrix_columns, result_matrix_lines, *result, matrix1_lines, matrix2_lines, matrix1_columns, matrix2_columns, *matrix1, *matrix2);
					for (int i = 0; i < matrix1_lines; i++) {
						for (int j = 0; j < matrix1_columns; j++) {
							cout << result[i][j] << " ";
							if (j == result_matrix_columns - 1) {
								cout << endl;
							}
						}
					}
				}
				break;
			case'*':
				if (!(matrix1_columns == matrix2_lines)) {
					cout << "Its impossible to multiplicate ur matrixes\n";
				}
				else {
					matmulti(result_matrix_columns, result_matrix_lines, *result, matrix1_lines, matrix2_lines, matrix1_columns, matrix2_columns, *matrix1, *matrix2);
					for (int i = 0; i < result_matrix_lines; i++) {
						for (int j = 0; j < result_matrix_columns; j++) {
							cout << result[i][j] << " ";
							if (j == result_matrix_columns -1) {
								cout << endl;
							}
						}
					}

				}
			}
			if (!(matrix1_columns == matrix2_lines || (matrix1_lines == matrix2_lines && matrix1_columns == matrix2_columns))) {
				cout << "Theres nothing u can do with these matrixes,bud\n Press ESC to exit from this programm or press any other button to enter other matrixes\n";
 }
			else {
				cout <<"\nPress ESC if u wanna exit from this programm or press F if u wanna continue with these matrixes or press any other button to enter new matrixes\n";
			}
			key = _getch();
		} while (key == 'f');
	} while (key != 27);
	return 0;
}
