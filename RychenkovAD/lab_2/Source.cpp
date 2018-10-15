#include <iostream>
#include <ctime>

using namespace std;

void quicksort(int *a, int right)
{
	int i = 0;
	int j = right - 1;
	int center = a[(sizeof(a)) / (2 * sizeof(int))];
	while (i <= j)
	{
		while (a[i] < center)
		{
			i++;
		}
		while (a[j] > center)
		{
			j--;
		}
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (j > 0)
	{
		quicksort(a, j + 1);
	}
	if (right > i)
	{
		quicksort(a + i, right - i);
	}
}

int main()
{
	setlocale(0, "rus");
	srand(time(NULL));

	const int SIZE = 10;
	int arr[SIZE];
	bool t;
	cout << "Неотсортированный массив: " << endl;
	for (int i = 0; i < SIZE; )
	{
		t = true;
		int a = rand() % 20;
		for (int j = 0; j < i; j++) 
		{
			if (a == arr[j]) 
			{
				t = false;
				break;
			}
		}
		if (t) 
		{
			arr[i] = a;
			cout << arr[i] << endl;
			i++;
        }
	}
	
	
	quicksort(arr, SIZE);
	

	int count = 0;
	cout << "Отсортированный массив: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
        cout << arr[i] << endl;
	}

	int arr2[SIZE];
	int min, max, k = 0, sum = 0;

	cout << "Массив 2: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] % 2 == 1)
		{
			arr2[i] = arr[i];
		}
		else {
			arr2[i] = 0;
		}
		if (arr2[i] != 0)
		{
			cout << arr2[i] << endl;
			
			min = arr2[i];
			max = arr2[i];
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (arr2[i] != 0)
		{
			k++;
			sum = sum + arr2[i];

			if (arr2[i] < min)
			{
				min = arr2[i];
			}
			if (arr2[i] > max)
			{
				max = arr2[i];
			}
		}
	}
	float meen = float(sum) / k;
	cout << "min = " << min << endl;
	cout << "max = " << max << endl;
	cout << "meen = " << meen << endl;
	
	
	
}