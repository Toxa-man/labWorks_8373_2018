#include "stdafx.h"
#include <iostream>
using namespace std;
const int arr_size = 100;
int WordCounter(char* text)
{
	int i = 0;
	int words = 1;
	while (*(text + i) != '\0')
	{
		if (*(text + i) == ' '&& *(text + i + 1) != '\0')
		{
			++words;
		}
		++i;
	}
	return words;
}
int WordMass(char* text, int number)
{
	int num = 1;
	int i = 0;
	int mass = 0;
	while (*(text + i) != '\0')
	{
		if (*(text + i) == ' ')
		{
			++num;
			++i;
		}
		while (num == number)
		{
			mass += (int)*(text + i);
			++i;
			if (*(text + i) == ' ' || *(text + i) == '\0')
			{
				++num;
				++i;
			}
		}
		++i;
		if (num > number)
		{
			break;
		}
	}
	return mass;
}
void AddWord(char* text, int number, char* SortedText, int& LenSorted)
{
	int num = 1;
	int i = 0;
	int mass = 0;
	while (*(text + i) != '\0')
	{
		if (*(text + i) == ' ')
		{
			++num;
			++i;
		}
		while (num == number)
		{
			*(SortedText + LenSorted) = *(text + i);
			++LenSorted;
			++i;
			if (*(text + i) == ' ' || *(text + i) == '\0')
			{
				++num;
				++i;
			}
		}
		++i;
		if (num > number)
		{
			break;
		}
	}
}
int main()
{
	char text[arr_size];
	char SortedText[arr_size];
	cout << "insert your text (length must be less than 100 symbols)" << endl;
	cin.getline(text, arr_size);
	int WordNum[arr_size];
	int LenSorted = 0;
	for (int i = 0; i < WordCounter(text); ++i)
	{
		WordNum[i] = i+1;
	}
	for (int i = 0; i < WordCounter(text) - 1; ++i)
	{
		for (int j = 1; j < WordCounter(text); ++j)
		{
			int buff;
			if (WordMass(text, WordNum[j - 1]) > WordMass(text, WordNum[j]))
			{
				buff = WordNum[j - 1];
				WordNum[j - 1] = WordNum[j];
				WordNum[j] = buff;
			}
		}
	}
	for (int i = 0; i < WordCounter(text); i++)
	{
		AddWord(text, WordNum[i], SortedText, LenSorted);
		SortedText[LenSorted] = ' ';
		++LenSorted;
	}
	cout << "Your text was sorted. It looks like: ";
	for (int j = 0; j < strlen(text); ++j)
	{
		cout << SortedText[j];
	}
	cout << endl;
	system("pause");
	return 0;
}
