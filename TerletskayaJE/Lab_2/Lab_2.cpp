#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	const int size1 = 8;
	int i, j, timesym, odd = 0, timeindex = 0, sum = 0;
	float avalue;
	int arr[size1];
	cout << "Сгенерированный массив: ";
	for (i = 0; i < size1; i++)
	{
		arr[i] = rand() % 100;
		if (arr[i] % 2 == 1)
		{
			odd += 1;
		}
		cout << " " << arr[i];
	}
	cout << endl;
	bool exit = false;
	cout << "Отсортированный массив: ";
	while (!exit)
	{
		exit = true;
		for (i = 0; i < size1 - 1; i++)
		{
			for (j = 0; j < size1 - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					timesym = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = timesym;
					exit = false;
				}
			}
		}
	}
	for (i = 0; i < size1; i++)
	{
		cout << " " << arr[i];
	}
	int arr2[size1];
	for (i = 0; i < size1; i++)
	{
		arr2[i] = 0;
	}
	for (i = 0; i < size1; i++)
	{
		if (arr[i] % 2 == 1)
		{
			arr2[timeindex] = arr[i];
			timeindex += 1;
		}
	}
	cout << endl;
	cout << "Минимальный элемент: " << arr2[0];
	cout << endl;
	cout << "Максимальный элемент: " << arr2[odd-1];
	cout << endl;
	for (i = 0; i < size1; i++)
	{
		sum += arr2[i];
	}
	avalue = (float)sum / odd;
	cout << "Среднее значение: " << avalue;
	cout << endl;
	return 0;
}