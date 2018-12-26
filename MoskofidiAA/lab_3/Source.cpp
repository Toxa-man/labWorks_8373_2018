#include <iostream>
#include "string.h"
#include "conio.h"

using namespace std;

int main()
{
	const int N = 500;
	const int M = 15;
	char str_in[N];
	char str_out[N];
	char str[M][N];
	int j(0), m(0), l(0), p(0);
	int len(0);
	int SumMin(0);
	int count(1);
	cout << "Enter string: ";
	cin.getline(str_in, N);
	cout << endl;
	len = strlen(str_in);
	for (int i = 0; i < len; i++)
	{
		if (str_in[i] == ' ') count += 1;
	}
	int *sum = new int[count];
	for (int i = 0; i < count; i++)
	{
		sum[i] = 0;
		while ((str_in[j] != ' ') && (str_in[j] != '\0'))
		{
			str[i][m] = str_in[j];
			sum[i] += static_cast<int>(str_in[j]);
			j++;
			m++;
		}
		j++;
		str[i][m] = '\0';
		m = 0;
	}
	for (int t = 0; t < count; t++)
	{
		for (int i = 0; i < count; i++)
		{
			if (sum[i] < sum[SumMin])
			{
				SumMin = i;
			}
		}
		while (str[SumMin][p] != '\0')
		{
			str_out[l] = str[SumMin][p];
			l++;
			p++;
		}
		str_out[l] = ' ';
		l++;
		sum[SumMin] = 10000000;
		p = 0;
	}
	str_out[l] = '\0';
	for (int i = 0; i <= len; i++)
	{
		cout << str_out[i];
	}
	delete[] sum;
	_getch();
	return 0;
}
