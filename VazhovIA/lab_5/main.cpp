#include <iostream>

using namespace std;
const int arrSize = 4;


void multiply(int *arr1Ptr, int *arr2Ptr, int *arrRPtr) {
//строка 1 матрицы на столбец 2 матрицы
	for (int i(0);i<arrSize;i++) {
		for (int k(0);k<arrSize;k++) {
			int elem(0);
			for (int j(0);j<arrSize;j++)//const i in 1st, const k in 2nd
			{
				elem += *(arr1Ptr + i*arrSize + k) * *(arr2Ptr+i + i*arrSize +k);
			}
			*(arrRPtr + i*arrSize + k) = elem;
		}
	}
}

void sum(bool sum, int *arr1Ptr, int *arr2Ptr, int *arrRPtr) {

	for (int i(0);i<arrSize;i++) {
		for (int k(0);k<arrSize;k++) {
			if (sum){
				*(arrRPtr+i*arrSize+k) = *(arr1Ptr+i*arrSize+k) + *(arr2Ptr+i*arrSize+k);
			} else {
				*(arrRPtr+i*arrSize+k) = *(arr1Ptr+i*arrSize+k) - *(arr2Ptr+i*arrSize+k);
			}
		}
	}
}


void app() {
	int matrix1[arrSize][arrSize], matrix2[arrSize][arrSize], matrixRes[arrSize][arrSize];
	char act;
	cout << "Enter first matrix with arrSize" << arrSize << endl;

	for (int i(0);i<arrSize;i++) {
		for (int k(0);k<arrSize;k++) {
			cin >> matrix1[i][k];
		}

		cout << endl;
	}
	cout << "Enter second matrix with arrSize" << arrSize << endl;
	for (int i(0);i<arrSize;i++) {
		for (int k(0);k<arrSize;k++) {
			cin >> matrix2[i][k];
		}
		cout << endl;
	}
	cout << "Enter action: +, -, *" << endl;
	cin >> act;

	switch (act) {

		case '+':
			sum(true, *matrix1, *matrix2, *matrixRes);
			break;
		case '-':
			sum(false, *matrix1, *matrix2, *matrixRes);
			break;
		case '*':
			multiply(*matrix1, *matrix2, *matrixRes);
			break;
		default:
			cout << "Wrong action!" << endl;
			break;
		}

	for (int i(0);i<arrSize;i++) {
		for (int k(0);k<arrSize;k++)
			cout << matrixRes[i][k] << " ";
		cout << endl;
	}

}

bool replay()
{
	char ans;
	cout << "Do you want to rerun? (y/n)" << endl;
	cin >> ans;
	switch (ans) {
		case 'y':
			return true;
			break;
		case 'n':
			return false;
			break;
		default:
			cout << "Wrong answer" << endl;
			return false;
			break;
	}
}
int main() {
	bool work;
	do {
		app();
		work = replay();
	} while (work);

	
}

