#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(0, "");

	const int n = 10;
	int arr1[n]; // размер массива

	for (int i = 0; i < n; i++) // создание массива из рандомных элементов
		arr1[i]=rand();

	for (int i = 0; i < n; i++) // вывод массива
		cout << arr1[i] << "  ";

	cout << endl << endl;
	
	int temp; // временная переменная для сортировки

	// сортировка массива пузырьком
	int i = 0, j = 0;
	while (i < n-1)
	{
		i++;
		while (j < n - i - 1) 
		{
			j++;
			if (arr1[j] > arr1[j + 1]) 
			{
				temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) // вывод массива
		cout << arr1[i] << "  ";

	cout << endl << endl;

	int arr2[n / 2];

	i = 0, j = 0;

	// здесь j - номер элемента в arr2, а i - номер элемента в arr1
	while (j < n / 2)
		while (i < n)
			if (i % 2 == 0)
				i = i + 1;
			else 
			{
				arr2[j] = arr1[i];
				j = j + 1;
			}

	for (int i = 0; i < n; i++) // вывод массива
		cout << arr2[i] << "  ";

	system("pause");
	return 0;
}