#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <iostream>
using namespace std;

void StringPartToString(char str1[], char str2[], int i, int j)
{
	int k = 0;
	for (i; i <= j; i++)
	{
		str2[k] = str1[i];
		k++;
	}
	str2[k] = 0;
}

int StringCodesSum(char str[], int i, int j)
{
	int result = 0;
	for (i; i < j; i++)
	{
		result += int(str[i]);
	}
	return result;
}

int main()
{
	const int N = 500;
	char str[N], word1[N], word2[N];
	int WordsScopes[4];											
	int s1(0), s2(0), words_count(0);				
	cout << "Enter the string: ";
	cin.getline(str, N);
	int n = strlen(str);
	str[n] = ' ';
	n++;
	str[n] = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ' ')
		{
			words_count++;
		}
	}
	for (int i = 0; i < words_count - 1; i++)
	{
		WordsScopes[0] = WordsScopes[1] = WordsScopes[2] = WordsScopes[3] = 0;
		int k = 1;
		for (int j = 0; j < n; j++)
		{
			if (str[j] == ' ')
			{
				if (k == 1)
				{
					WordsScopes[k] = j;
					k++;
				}
				if (k == 2)
				{
					WordsScopes[k] = j + 1;
				}
				if (k == 3)
				{
					WordsScopes[k] = j;
				}
				k++;
			}
			if (WordsScopes[3] != 0)
			{
				s1 = StringCodesSum(str, WordsScopes[0], WordsScopes[1]);
				s2 = StringCodesSum(str, WordsScopes[2], WordsScopes[3]);
				if (s1 > s2)
				{
					StringPartToString(str, word1, WordsScopes[0], WordsScopes[1] - 1);
					StringPartToString(str, word2, WordsScopes[2], WordsScopes[3]);
					strcat_s(word2, word1);
					int l1 = WordsScopes[0];
					for (int l = 0; l < strlen(word2); l++)
					{
						str[l1] = word2[l];
						l1++;
					}
					j -= strlen(word1);
				}
				else
				{
					j -= (WordsScopes[3] - WordsScopes[2]);
				}
				WordsScopes[0] = j;
				WordsScopes[1] = WordsScopes[2] = WordsScopes[3] = 0;
				k = 1;
				j--;
			}
		}
	}
	n--;
	str[n] = 0;
	cout << "Result: " << str;
	_getch();
	return 0;
}
