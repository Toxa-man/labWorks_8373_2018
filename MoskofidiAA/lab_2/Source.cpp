#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	const int size = 10;
	int arr1[size];
	int arr2[size];
	int j(0);
	for (int i = 0; i < size; i++)
	{
		arr1[i] = rand();
		cout << arr1[i] << "  " << endl;
	}
	cout << endl;
	cout << "Uneven elements: ";
	for (int i = 0; i < size; i++)
	{
		if (arr1[i] % 2 != 0) {
			arr2[j] = arr1[i];
			j++;
			cout << arr1[i] << "  ";
		}
	} cout << endl;
	int p(0), k;
	do {
		k = 0;
		do {
			if (arr1[k + 1] > arr1[k])
			{
				swap(arr1[k + 1], arr1[k]);
			}
			k++;
		} while (k < size - 1);
		p++;
	} while (p < size);
	for (int i = 0; i < size; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;
	int min = arr2[0];
	int max = arr2[0];
	int sum = arr2[0];
	int srznach;
	for (int i = 1; i < j; i++)
	{
		if (arr2[i] < min) {
			min = arr2[i];
		}
		if (arr2[i] > max) {
			max = arr2[i];
		}
		sum += arr2[i];
	}
	srznach = sum / j;
	cout << "Min: " << min << endl;
	cout << "Max: " << max << endl;
	cout << "Average: " << srznach << endl;
	_getch();
	return 0;
}