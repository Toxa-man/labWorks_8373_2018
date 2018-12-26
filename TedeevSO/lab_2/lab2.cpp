#include "pch.h"
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
	setlocale(0, "rus");
	srand(time(NULL));
	const int n = 10;
	int arr1[n];
	cout << "Исходный массив:" << endl;
	for (int i = 0; i < n; i++)
	{
		arr1[i] = 1 + rand()%100;
		cout << arr1[i] << " ";
	}
	int a = 0, b = 0, temp;
	while (a < n - 1)
	{
		b = 0;
		while (b < n - a - 1)
		{
			if (arr1[b] > arr1[b + 1])
			{
				temp = arr1[b];
				arr1[b] = arr1[b + 1];
				arr1[b + 1] = temp;
			}
			b++;
		}
		a++;
	}
	cout << endl << "После сортировки:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr1[i] << " ";
	}
	int arr2[n];
	int t = 0;
	cout << endl << "Второй массив:" << endl;
	for (int i = 0; i < n; i++)
	{
		if (arr1[i] % 2 != 0)
		{
			arr2[t] = arr1[i];
			cout << arr2[t] << " ";
			t++;
		}
	}
	int maximum = arr2[0], minimum = arr2[t-1];
	float sum = 0, average;
	for (int i = 0; i < t; i++)
	{
		sum += arr2[i];
		if (arr2[i] < minimum)
			minimum = arr2[i];
		if (arr2[i] > maximum)
			maximum = arr2[i];
	}
	average = sum / t;
	cout << endl << "Среднее значение:" << endl << average << endl;
	cout << "Минимальный элемент:" << endl << minimum << endl;
	cout << "Максимальный элемент:" << endl << maximum << endl;
}
