#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;


int main()
{
	setlocale(0,"");
	const int arr_size =10;
	int arr[arr_size];
	cout << "первый массив:\n";
	srand(time(0));
	for (int i = 0; i < arr_size; i++)
	{
		arr[i] = rand();
		cout << arr[i] << " ";
	}
	cout << endl;
	int change = 0;
	bool exit = false;
	int i = 0, j = 0;
	while (i < arr_size)
	{
		j = 0;
		while (j < arr_size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				change = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = change;
			}
			j++;
		}
		i++;
	}
	cout << "отсортированный массив: \n";
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "массив из нечетных чисел: " << endl;
	int secondArr[arr_size];
	int kolsecarr=0;
	int sum = 0;
	for (int x = 0; x < arr_size; x++)
	{
		if (arr[x] % 2 == 1)
		{
			secondArr[kolsecarr] = arr[x];
			cout << secondArr[kolsecarr] << " ";
			sum += secondArr[kolsecarr];
			kolsecarr++;
		}
	}
	cout << endl;
	cout << "Минимальное значение: " << endl;
	cout << secondArr[0] << endl;
	cout << "Максимальное значение: " << endl;
	cout << secondArr[kolsecarr-1] << endl;
	cout << "Среднее значение отсортированного массива: " << endl;
	cout << sum / float(kolsecarr) << endl;
	system("pause");
	return 0;
}