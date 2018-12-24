// ConsoleApplication12.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

const int Num = 100;
char arr[Num];
int scale[Num / 2];
int len[Num / 2];
int bgn[Num / 2];

void swap(int a, int b)
{	
	int razm = strlen(arr);
	char buffer[100];
	for (int j = 0; j < len[a]; j++)
	{
		buffer[j] = arr[j + bgn[a]];
	}
	buffer[len[a]] = '\0';
	//cout << "buf: ";
	//puts(buffer);
	//cout << endl;
	if (len[a] >= len[b])
	{
		for (int j = bgn[a] + len[a] - len[b]; j < razm; j++)
		{
			arr[j + len[b] - len[a]] = arr[j];
			//puts(arr);
			//cout << endl;
		}
		/*cout << "null" << endl;
		for (int j = razm - len[a] + len[b]; j < razm; j++)
		{
			arr[j] = '\0';
		}*/
	}
	else
		for (int j = razm; j > bgn[a] - len[b] + len[a]; j--)
		{
			arr[j + len[b] - len[a]] = arr[j];
			//puts(arr);
			//cout << endl;
		}
	//puts(arr);
	//cout << endl;
	//cout << "swap" << endl;
	for (int j = 0; j < len[b]; j++)
	{
		//cout << "bgn[a]+j: " << bgn[a] + j << endl;
		//cout << "bgn[b]+j: " << bgn[b] + j << endl;
		arr[bgn[a]+j] = arr[bgn[b]+j - len[a] + len[b]];
		//puts(arr);
		//cout << endl;
	}
	//puts(arr);
	//cout << endl;

	if (len[b] >= strlen(buffer))
		for (int j = bgn[b] + len[b] - strlen(buffer); j < razm; j++)
		{
			arr[j] = arr[j + len[b] - strlen(buffer)];
			//puts(arr);
			//cout << endl;
		}
	else
		for (int j = razm - 1; j > bgn[a] + len[b] ; j--)
		{
			//cout << "j + strlen(buffer) - len[b]: " << j + strlen(buffer) - len[b] << endl;
			//cout << "j: " << j << endl;
			arr[j + strlen(buffer) - len[b]] = arr[j];
			//puts(arr);
			//cout << endl;
		}
	//cout << "null" << endl;
	arr[razm] = '\0';
	//puts(arr);
	//cout << endl;
	//cout << "swap" << endl;
	for (int j = 0; j < strlen(buffer); j++)
	{
		//cout << "bgn[b]+j: " << bgn[b] + j - len[a] + len[b] << endl;
		//cout << "j: " << j << endl;
		arr[bgn[b] + j - len[a] + len[b]] = buffer[j];
		//puts(arr);
		//cout << endl;
	}
	//puts(arr);
	//cout << endl;
}

int main()
{
	setlocale(0, "");
	cout << "¬ведите строку (меньше " << Num << " символов): ";
	gets_s(arr);
	bool prov = false;
	while (!prov)
	{
		prov = true;
		for (int i = 0; i < strlen(arr)-1; i++)
		{
			if ((arr[i] == ' ') && (arr[i + 1] == ' '))
			{
				prov = false;
				cout << "¬ведите строку только с одинарными пробелами: ";
				gets_s(arr);
				break;
			}
		}
		if (arr[strlen(arr) - 1] == ' ')
		{
			prov = false;
			cout << "¬ведите строку без пробела в конце: ";
			gets_s(arr);
		}
	}
	bgn[0] = 0;
	int Word = 1;
	for (int i = 0; i < strlen(arr); i++)
	{
		if ((arr[i] == ' ') && (i!=strlen(arr) - 1))
		{
			bgn[Word] = i+1; 
			scale[Word - 1] = 0;
			len[Word - 1] = bgn[Word] - bgn[Word - 1] - 1;
			for (int j = bgn[Word - 1]; j < i; j++)
			{
				scale[Word - 1] += arr[j];
			}
			//cout << scale[Word - 1] << ' ';
			Word++;
		}
	}
	Word--;
	for (int j = bgn[Word]; j < strlen(arr); j++)
	{
		scale[Word] += arr[j];
	}
	//cout << scale[Word] << ' ';
	//cout << endl;
	len[Word] = strlen(arr) - bgn[Word];
	//метод пузырька из второй лабы
	int ex = 0;
	int it = 0;
	Word++;
	while ((ex < Word) && (Word!=1))
	{
		if (scale[it] > scale[(it + 1)%(Word)])
		{
			//cout << "__________________________" << endl;
			swap(it, it + 1);
			/*int tmp = scale[it];
			scale[it] = scale[(it + 1) % Word];
			scale[(it + 1) % Word] = tmp;
			tmp = bgn[it];
			bgn[it] = bgn[(it + 1) % Word];
			bgn[(it + 1) % Word] = tmp;
			tmp = len[it];
			len[it] = len[(it + 1) % Word];
			len[(it + 1) % Word] = tmp;
			*/
			ex = 0;
		}
		it = (it + 1) % (Word-1);
		ex = ex + 1;
		bgn[0] = 0;
		int Word = 1;
		for (int i = 0; i < strlen(arr); i++)
		{
			if ((arr[i] == ' ') && (i != strlen(arr) - 1))
			{
				bgn[Word] = i + 1;
				scale[Word - 1] = 0;
				len[Word - 1] = bgn[Word] - bgn[Word - 1] - 1;
				for (int j = bgn[Word - 1]; j < i; j++)
				{
					scale[Word - 1] += arr[j];
				}
				//cout << scale[Word - 1] << ' ';
				Word++;
			}
		}
		Word--;
		scale[Word] = 0;
		for (int j = bgn[Word]; j < strlen(arr); j++)
		{
			scale[Word] += arr[j];
		}
		//cout << scale[Word] << ' ';
		//cout << endl;
		len[Word] = strlen(arr) - bgn[Word];
		Word++;
	}

	cout << "ќтсортированна€ строка: ";
	puts(arr);
	_getch();
	return 0;
}