#include <iostream>
#include <conio.h>
#include <ctime>


using namespace std;
const int SIZE = 10;


int main()
{
	srand(time(0));
	*setlocale(0, "");

	int arr_random[SIZE];
	cout << "Сгенерированный массив: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		arr_random[i] = rand() % 100 + 1;
		cout << arr_random[i] << " ";
	}
	cout << endl;

	cout << "Отсортированный по возрастанию массив: " << endl;

	int i = 0, a = 0;
	int c;

	while (i < SIZE)
	{
		a = i;
		while (a < SIZE)
		{
			if (arr_random[a] < arr_random[i])
			{
				c = arr_random[a];
				arr_random[a] = arr_random[i];
				arr_random[i] = c;
			}
			a++;
		}
		cout << arr_random[i] << " ";
		i++;
	}
	cout << endl;
	cout << "Массив из нечетных элементов первого массива: " << endl;

	for (i = 0; i < SIZE; i++)
	{
		if (arr_random[i] % 2 == 1)
		{
			cout << arr_random[i] << " ";
		}
	}
	cout << endl;
	int Min = 1000000;
	int Max = -1000000;
	float sum = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (arr_random[i] < Min)
		{
			Min = arr_random[i];
		}
		if (arr_random[i] > Max)
		{
			Max = arr_random[i];
		}
		sum += arr_random[i];
	}
	cout << "Минимальное число = " << Min << endl;
	cout << "Максимальное число = " << Max << endl;
	cout << "Среднее арифметическое = " << sum / SIZE << endl;




	_getch();
	return 0;
}