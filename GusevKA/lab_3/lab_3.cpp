#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;



int score(int *str1, int size)
{
	int couter;
	int score = str1[0];
	int i = 0;
	while ( i < size)
	{
		if (str1[i] <= score)
		{
			score = str1[i];
			couter = i;
		}
		i++;
	}

	return couter;
}
int main()
{
	const int size = 100;
	char str[size] = " ";
	setlocale(0, "");
	cout << "first str ";
	cin.getline(str, size);
	int str1[size] = { '\0' };

	int  S = 0;
	int i = 0;
	while ( i < size )
	{
		if (str[i] != ' ' && str[i] != 0)
		{
			str1[S] = str1[S] + str[i];
		}
		else if (str[i] == ' ')
		{
			S++;
		}
		i++;
	}
	S++;

	
	int spase;
	int counter;
	int counter2;
	int size2 = 0;
	int counter_max = 0;
	char str2[size] = { '\0' };
	

	for (int j = 0; j < S; j++)
	{
		spase = 0;
		counter2 = 0; 
		counter = score(str1, S);
		for (int i = 0; i < size; i++)
		{
			if (str[i] == ' ')
			{
				spase++;
				if (spase == counter)
				{
					counter2 = i;
				}
			}
		}
		if (counter2 != 0)
		{
			counter2++;
		}
		for (int i = counter2; i < size; i++)
		{
			if (str[i] != ' ' && str[i] != 0)
			{
				str2[size2] = str[i];
				size2++;
			}
			else
			{
				str2[size2] = ' ';
				size2++;
				break;
			}
		}
		int q = 0;
		do
		{
			if (str1[q] > counter_max)
			{
				counter_max = str1[q];
			}
			q++;
		} while (q < S);
		str1[counter] = counter_max + 1;
	}
	cout << "second str " << str2;
	_getch();
	return 0;
}