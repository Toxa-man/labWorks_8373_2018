#include <iostream>
#include <ctime>

using namespace std;

void quicksort(int *arr, int right)
{
	int i = 0;
	int j = right - 1;
	int center = arr[right / 2];
	
	while (i <= j)
	{
		while (arr[i] < center)
		{
			i++;
		}
		while (arr[j] > center)
		{
			j--;
		}
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (j > 0)
	{
		quicksort(arr, j + 1);
	}
	if (right > i)
	{
		quicksort(arr + i, right - i);
	}
}

int main()
{
	setlocale(0, "rus");
	srand(time(NULL));

	const int SIZE = 10;
	int arr[SIZE];
	int center = arr[(sizeof(arr)) / (2 * sizeof(int))];
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

	cout << "\nОтсортированный массив: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << endl;
	}

	int arr2[SIZE];
	int count = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] % 2 == 1)
		{
			arr2[count] = arr[i];
			count++;
		}
	}
    cout << "\nМассив 2: " << endl;
	
	for (int i = 0; i < count; i++)
	{
		cout << arr2[i] << endl;
	}


	int min = arr2[0], max = arr2[0], sum = arr2[0];
	for (int i = 1; i < count; i++)
	{
		if (arr2[i] < min)
		{
			min = arr2[i];
		}
		if (arr2[i] > max)
		{
			max = arr2[i];
		}
		sum += arr2[i];
    }
	
	
	cout << "\n\nmin = " << min << endl;
	cout << "max = " << max << endl;
	cout << "meen = " << float(sum) / count << endl;
	system("pause");

}