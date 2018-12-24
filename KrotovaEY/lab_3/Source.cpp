#include <iostream>
#include <conio.h>
using namespace std;

int min(int *mass, int size)
{
	int min = mass[0];
	int index;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] <= min)
		{
			min = mass[i];
			index = i;
		}
	}
	return index;
}
int main()
{
	const int size = 50;
	char str[size] = " ";
	setlocale(0, "");
	cout << "Введите строку: ";
	cin.getline(str, size);
	int mas[size] = { 0 };
	int  sizemas= 0;
	for (int i = 0; i < size; i++)
	{
		if (str[i] != ' ' && str[i] != 0)
		{
			mas[sizemas] += str[i];
		}
		else if(str[i]==' ')
		{
			sizemas++;
		}
	}
	sizemas++;
	char str2[size] = { 0 };
	int probel;
	int index;
	int index2;
	int size_str2=0;
	int max = 0;
	for (int i = 0; i < sizemas; i++)
	{
		if (mas[i] > max)
		{
			max = mas[i];
		}
	}
	for (int j = 0; j < sizemas; j++)
	{
		index=min(mas, sizemas);
		probel = 0;
		index2 = 0;
		for (int i = 0; i < size; i++)
		{
			if (str[i] == ' ')
			{
				++probel;
				if (probel == index)
				{
					index2 = i;
				}
			}
		}
		if (index2 != 0)
		{
			++index2;
		}
		for (int i = index2; i < size; i++)
		{
			if (str[i]!= ' ' && str[i]!=0)
			{
				str2[size_str2] = str[i];
				++size_str2;
			}
			else
			{
				str2[size_str2] = ' ';
				++size_str2;
				break;
			}
		}
		mas[index]=max + 1;
	}
	cout <<"Отсортированная строка: "<< str2;
	_getch();
	return 0;
}