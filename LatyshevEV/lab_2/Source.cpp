#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

const int lenght = 8;

void print(int a[])
{
	for (int i = 0; i < lenght; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}


void sort(int items[], int left, int right)
{
	int pivot = items[left];
	int mleft = left;
	int mright = right;
	while (left < right)
	{
		while ((items[right] >= pivot) && (left < right))
		{
			right--;
		}
		while ((items[left] <= pivot) && (left < right))
		{
			left++;
		}
		if (left < right)
		{
			int c = items[left];
			items[left] = items[right];
			items[right] = c;
			left--;
			right++;
		}
	}
	int c = items[mleft];
	items[mleft] = items[left];
	items[left] = c;
	if ((left - 1 - mleft) > 0) {
		sort(items, mleft, left - 1);
	}
	if ((mright - mleft + 1) > 0) {
		sort(items, left + 1, mright);
	}
}

void third_task(int items[])
{
	int items2[lenght];
	int count = 0;
	float sum = items[0];
	int min = items[0];
	int max = items[0];
	for (int i = 1; i < lenght; i++)
	{
		if (items[i] < min)
		{
			min = items[i];
		}
		if (items[i] > max)
		{
			max = items[i];
		}
		sum += items[i];

	}
	for (int i = 0; i < lenght; i++)
	{
		if ((items[i] % 2) == 1)
		{
			items2[count] = items[i];
			count++;
		}
	}
	cout << "Массив из нечетных элементов: " << endl;
	for (int i = 0; i < count; i++)
	{
		cout << items2[i] << ' ';
	}
	cout << endl << "Максимум: " << max << ' ' << "Минимум: " << min << endl;
	float midd = sum / lenght;
	cout << "Среднее значение: " << midd;
}

int main()
{
	setlocale(0, "");
	int a[lenght];
	cout << "Исходный массив:" << endl;
	for (int i = 0; i < lenght; i++)
	{
		a[i] = rand();
	}
	print(a);
	sort(a, 0, lenght - 1);
	cout << "Сортированный массив:" << endl;
	print(a);
	third_task(a);
	_getch();
	return 0;
}