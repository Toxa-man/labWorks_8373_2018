#include <iostream>

using namespace std;
const int arrSize = 4;

#ifdef __linux__
#include <termios.h>
#elif _WIN32
#include <conio.h>
#endif

using namespace std;
static struct termios oldSetts, nwSetts;
void initTermios()
{
	tcgetattr(0, &oldSetts);
	nwSetts = oldSetts;
	nwSetts.c_lflag &= ~ICANON;
	nwSetts.c_lflag &= ~ECHO;
	tcsetattr(0, TCSANOW, &nwSetts);
}
char _getch() 
{
	cin.ignore(1,'\n');
	char ch;
	initTermios();
	ch = getchar();
	tcsetattr(0, TCSANOW, &oldSetts);
	return ch;
}

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
	cout << "Enter first matrix with size" << arrSize << endl;

	for (int i(0);i<arrSize;i++) {
		for (int k(0);k<arrSize;k++) {
			cin >> matrix1[i][k];
		}

		cout << endl;
	}
	cout << "Enter second matrix with size" << arrSize << endl;
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
	cout << "Do you want to rerun? (y/n/anykey for yes)" << endl;
	ans = _getch();
	cout << ans;
	switch (ans) {
		case 'y':
			return true;
			break;
		case 'n':
			return false;
			break;
		default:
			return true;
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

