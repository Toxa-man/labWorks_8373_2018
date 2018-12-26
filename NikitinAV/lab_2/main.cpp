
#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	setlocale(0, "");
	const int arrsize = 8;
	int arr1[arrsize];
	int arr2[arrsize];
	int j;
	int i;
	cout << "������, ����������� ���������� ����������:" << endl;
	for (i = 0; i < arrsize; i++) {
		arr1[i] = rand();
		cout << arr1[i] << " ";
	}
	cout << endl;
	// ����� 2
	int t, m = 0;
	i = 0;
	j = 0;
	cout << "��������������� ������:" << endl;
		while (i < arrsize) {
   j = i;
		while (j < arrsize){
				if (arr1[i]>arr1[j])
				{
					t = arr1[j];
					arr1[j] = arr1[i];
					arr1[i] = t;
				}
				j++;
			}
			i++;
		}
		for (int i = 0; i < arrsize; i++) {
			cout << arr1[i] << " ";
	}
 cout << "\n";
	// ����� 3
	for (i = 0; i < arrsize; i++) {
		if (arr1[i] % 2 == 1) {
			arr2[m] = arr1[i];
			m++;
		}
	}
	cout << "������ �� �������� ��������� �������:" << endl;
	for (i = 0; i < m; i++) {
		cout << arr2[i] << " ";
	}


	float sum = 0;
		for (i= 0; i < m; i++) {
			sum += arr2[i];
		}
		sum = sum / m;
	cout << endl;
	cout << "������������ ������� ������� �������:" << arr2[0] << endl;
	cout << "������������ ������� ������� �������:" << arr2[m-1] << endl;
	cout << "������� �������� ��������� ������� �������:" << sum << endl;
	_getch();
	return 0;
}
