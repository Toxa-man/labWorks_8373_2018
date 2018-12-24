#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;
const int SIZE = 10;
int main()
{
	srand(time(0));
	setlocale(0, "");

	int arr_random[SIZE];
	
	cout << "Сгенерированный массив: " << endl;
	
	for (int i = 0; i < SIZE; i++)
	{
		arr_random[i] = rand() % 100 + 1;
		cout << arr_random[i] << " ";
	}
	cout << endl;

	cout << "Остортированный массив по возрастанию: " << endl;
	
	int arr_ncht[SIZE];
	int a = 0;
	int c;
	int ncht = 0;

	for (int j = 0; j < SIZE; j++)
	{
		while (j < SIZE)
		{
			a = j;
			while (a < SIZE)
			{
				if (arr_random[a] < arr_random[j])
				{
					c = arr_random[a];
					arr_random[a] = arr_random[j];
					arr_random[j] = c;
				}
				a++;
			}
			if (arr_random[j] % 2 == 1)
			{
				arr_ncht[ncht] = arr_random[j];
				ncht++;
			}
			cout << arr_random[j] << " ";
			j++;
		}
	}
	cout << endl;
	
	cout << "Нечетные элементы массива: " << endl;

	for (int k = 0; k < ncht; k++)
	{
		cout << arr_ncht[k] << " ";
	}
	cout << endl;

	int Min = arr_ncht[0];
	int Max = arr_ncht[1];
	float sum = 0;

	for (int k = 0; k < ncht; k++)
	{
		if (arr_ncht[k] < Min)
		{
			Min = arr_ncht[k];
		}
		if (arr_ncht[k] > Max)
		{
			Max = arr_ncht[k];
		}
		sum += arr_ncht[k];
	}

	cout << "Минимальный элемент = " << Min << endl;
	cout << "Максимальный элемент = " << Max << endl;
	cout << "Среднее арифметическое = " << sum / ncht << endl;
	
	_getch();
	return 0;
}