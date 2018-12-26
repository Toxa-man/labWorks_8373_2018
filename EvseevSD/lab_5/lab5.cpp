#include<iostream>
#include<conio.h>
using namespace std;

const int maxsize = 10;

void my_nul(int *mat, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			*(mat + i * n + j) = 0;
		}
	}
}
void my_cout(int *mat, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << *(mat + i*n + j);
			cout << ' ';
		}
		cout << endl;
	}
}
void my_cin(int *mat, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> *(mat + i * n + j);
		}
	}
}

void my_sum(int *mat1, int *mat2, int *mat3,int m,int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			*(mat3 + i*n + j) = *(mat1 + i*n + j) + *(mat2 + i*n + j);
		}
	}
}

void my_dif(int *mat1, int *mat2, int *mat3, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			*(mat3 + i*n + j) = *(mat1 + i*n + j) - *(mat2 + i*n + j);
		}
	}
}
void my_mult(int *mat1, int *mat2, int *mat3, int m, int n2, int n1) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n2; j++) {
			for (int k = 0; k < n1; k++) {
				*(mat3+i*n2+j) += *(mat1+i*n1+k) * *(mat2+k*n2+j);
			}
		}
	}
}

int main() {
	int mat1[maxsize][maxsize], mat2[maxsize][maxsize], mat3[maxsize][maxsize];
	int m1, n1, m2, n2;
	char esc = 'q';
	do {
		cout << "Enter the number of lines of first matrix" << endl;
		cin >> m1;
		cout << "Enter the number of columns of first matrix" << endl;
		cin >> n1;
		cout << "Enter the number of lines of second matrix."<<endl;
		cin >> m2;
		cout << "Enter the number of columns of first matrix." << endl;
		cin >> n2;
		cout << "Enter first matrix:" << endl;
		my_cin(*mat1, m1, n1);
		cout << "Enter second matrix:" << endl;
		my_cin(*mat2, m2, n2);
		char sign;
		if (m1 == m2 && n1==n2 && m1 == n2){
			cout <<"Choose the operation:" << endl <<"Press + to sum" << endl << "Press - to diference" << endl <<"Press * to multiplication"  << endl;
			my_nul(*mat3, m1, n1);
			cin >> sign;
			switch (sign) {
				case '+': my_sum(*mat1, *mat2, *mat3, m1, n1);
					break;
				case '-': my_dif(*mat1, *mat2, *mat3, m1, n1);
					break;
				case '*': my_mult(*mat1, *mat2, *mat3, m1, n2, n1);
					break;
				default: cout << "Mistake. You entered wrong operation." << endl;
					break;
			}
			my_cout(*mat3, m1, n1);
		}
		if (m1 == m2 && n1 == n2 && m1 != n1) {
			cout << " Choose the operation:" << endl << " Press + to sum" << "Press - to diference" << endl;
			my_nul(*mat3, m1, n1);
			cin >> sign;
			switch (sign) {
				case '+': my_sum(*mat1, *mat2, *mat3, m1, n1);
					break;
				case '-': my_dif(*mat1, *mat2, *mat3, m1, n1);
					break;
				default: cout << "Mistake. You entered wrong operation." << endl;
					break;
				}
			my_cout(*mat3, m1, n1);
			}
		if (n1 == m2 && (n1 != n2 || m1 != m2)) {
			cout << " Choose the operation:" << endl << " Press * to multiplication" << endl;
			my_nul(*mat3, m1, n2);
			cin >> sign;
			switch (sign) {
			case '*': my_mult(*mat1, *mat2, *mat3, m1, n2, n1);
				break;
			default: cout << "Mistake. You entered wrong operation." << endl;
				break;
			}
			my_cout(*mat3, m1, n2);
		}
		cout << endl << "Press any key to continue or press Esc to close the program" << endl;
		esc = _getch();
	}while ( esc != 27);
	return 0;
}