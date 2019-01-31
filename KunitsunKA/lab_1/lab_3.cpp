#include <iostream>
#include <windows.h>
#include "stdafx.h"
using namespace std;

struct structure
{
	int first_simbol;
	int last_symbol;
	int summa_symbolov;
};
int main()
{
	setlocale(0, "");
	int const size = 200;
	structure word[size];
	char str[size];
	int i, j, words_num, o;

	cout << "Введите строку, разделяйте слова одним пробелом\n";
	cout << "введенные строка:\n";
	gets_s(str);

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			if (str[i + 1] == ' ')
			{
				cout << "Вы ввели больше чем один пробел\n";
				system("pause");
				return 0;
			}
		}
	}
	words_num = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' && str[i + 1] != '\0')
		{
			words_num++;
		}
	}
	for (i = 0; i < words_num; i++)
	{
		word[i].summa_symbolov = 0;
	}
	j = 0;
	for (i = 0; i < words_num; i++)
	{
		while (str[j] != '\0')
		{
			word[i].summa_symbolov += int(str[j]);
			if (str[j + 1] == ' ')
			{
				j++;
				break;
			}
			j++;
		}
		j++;
	}

	word[0].first_simbol = 0; j = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			j++;
			word[j].first_simbol = i + 1;
		}
		else
		{
			word[j].last_symbol = i;
		}
	}
	o = 0; i = 0; j = 0;
	for (i = 0; i < words_num; i++)
	{
		for (j = i; j < words_num; j++)
		{
			if (word[i].summa_symbolov > word[j].summa_symbolov)
			{
				structure o = word[j];
				word[j] = word[i];
				word[i] = o;
			}
		}
	}

	cout << "Отсортированная строка:\n";
	for (int i = 0; i < words_num; i++)
	{
		for (int j = word[i].first_simbol; j <= word[i].last_symbol; j++)
		{
			cout << str[j];
		}
		if (i != words_num)
		{
			cout << ' ';
		}
	}
	cout << endl;
	system("pause");
	return 0;
}


