#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 10;
	int i,j,temp, MAX, MIN, sr_znach;
	int rand_mass[size], sort_mass[size];

	for (int i = 0; i < size; i++) {
		rand_mass[i] = rand() % 101;
	}

	cout << "1) Cгенерированный массив: ";
	for (i = 0; i < size; i++) {
		cout << rand_mass[i] << " ";
	}
	cout << endl;


	i = 0;
	j = 0;
	temp = 0;
	while (i < size) {
		j = i;
		while (j < size) {
			if (rand_mass[i] > rand_mass[j]) {
				temp = rand_mass[j];
				rand_mass[j] = rand_mass[i];
				rand_mass[i] = temp;
			}
			j++;
		}
		i++;
	}
	
	cout << "2) Отсортированный массив: ";
	for (i = 0; i < size; i++) {
		cout << rand_mass[i] << " ";
	}
	cout << endl;


	i = 0;
	j = 0;
	temp = 0;
	MAX = -1000;
	MIN = 1000;
	sr_znach = 0;
	cout << "3) Массив из нечетных элементов: ";
	while (i < size)
	{
		if (rand_mass[i] % 2 == 1)
		{
			sort_mass[j] = rand_mass[i];
			sr_znach = sr_znach + sort_mass[j];
			if (sort_mass[j] > MAX) MAX = sort_mass[j];
			if (sort_mass[j] < MIN) MIN = sort_mass[j];
			cout << sort_mass[j] << " ";
			j++;
		}
		i++;
	}
	sr_znach = sr_znach / j;
	cout << endl;
	cout << "Минимальное значение: " << MIN << endl;
	cout << "Максимальное значение: " << MAX << endl;
	cout << "Среднее значение: " << sr_znach << endl;

	system("pause");
	return 0;
}