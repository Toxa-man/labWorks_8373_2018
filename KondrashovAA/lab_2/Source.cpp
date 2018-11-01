#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	const int size1 = 10;
	int arr1[size1], arr2[size1];
	cout << "randomly generated array: " << endl;
	for (int i = 0; i < size1; i++) {
		arr1[i] = rand() % 1000;
		cout << arr1[i] << ' ';
	}
	int n = size1;
	while (n > 1)
	{
		int i = 0, last = 1;
		while (++i < n)
		{
			if (arr1[i - 1] > arr1[i])
			{
				int tmp = arr1[i];
				arr1[i] = arr1[i - 1];
				arr1[i - 1] = tmp;
				last = i;
			}
		}
		n = last;
	}
	int size2 = 0;
	int sum = 0;
	for (int i = 0; i < size1; i++) {
		if (arr1[i] % 2) {
			arr2[size2] = arr1[i];
			size2++;
			sum += arr1[i];
		}
	}
	cout << endl << "sorted array: " << endl;
	for (int i = 0; i < size1; i++) {
		cout << arr1[i] << ' ';
	}
	float aver_val = (float)sum / size2;
	cout << endl << "odd elements of array: " << endl;
	for (int i = 0; i < size2; i++) {
		cout << arr2[i] << ' ';
	}
	cout << "min odd element: " << arr2[0] << endl;
	cout << "max odd element: " << arr2[size2-1] << endl;
	cout << "average value of odd elements: " << aver_val << endl;
	_getch();
	return 0;
}