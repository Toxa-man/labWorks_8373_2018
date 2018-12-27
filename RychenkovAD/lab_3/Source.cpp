#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;


void sort_words(char str[])
{
	char str2[50][100];
	int sum[50];
	for (int i = 0; i < 50; i++)
	{
		sum[i] = 0;

		for (int j = 0; j < 100; j++)
		{
			str2[i][j] = '/0';
		}
	}


	int count_words = 0;
	int sym = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] != 32)
		{
			str2[count_words][sym] = str[i];
			sum[count_words] = sum[count_words] + (int)str[i];
			sym++;
		}
		else
		{
			str2[count_words][sym] = '\0';
			sym = 0;
			count_words++;
		}
	}
	str2[count_words][sym] = '\0';
	for (int i = 0; i <= count_words - 1; i++)
	{
		for (int j = i + 1; j <= count_words; j++)
		{
			if (sum[j] < sum[i])
			{
				swap(sum[j], sum[i]);
				for (int k = 0; k < strlen(str); k++)
				{
					if ((str2[i][k] != '\0') || (str2[j][k] != '\0'))
					{
						swap(str2[i][k], str2[j][k]);
					}
					else
						break;
				}
			}
		}
	}

	for (int i = 0; i < count_words + 1; i++)
	{
		for (int j = 0; j < strlen(str); j++)
		{
			if (str2[i][j] != '\0')
			{
				cout << str2[i][j];
			}
			else
			{
				cout << " ";
				break;
			}
		}

	}

	cout << endl;


	/*for (int i = 0; i < count; i++)
	{
		delete[] str2[i];
	}
	delete[] str2;
	delete[] sum;*/
}

int main()
{
	const int size = 100;
	char str[size];
	cout << "Enter the string:\n" << endl;
	cin.getline(str, size);

	cout << "\n2nd string sorted by the sum of elements in words:\n" << endl;
	sort_words(str);

	
	_getch();
}