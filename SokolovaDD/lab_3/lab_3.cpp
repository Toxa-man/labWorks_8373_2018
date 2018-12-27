#include <iostream> 
#include <stdio.h>
#include<conio.h>
using namespace std;
const int N = 50;
int main()
{
	char arr[N];
	int counter[N] = { 0 };
	int  start_words[N] = { 0 };
	int sum[N] = { 0 };
	char otv[N] = { 0 };
	
	cout << "Enter text:  ";
	gets_s(arr);
	int s = 0, k = 1;
	start_words[0] = 0;
	for (int i=0; arr[i-1]!='\0'; i++)
	{
		if (arr[i] == ' '|| arr[i] == '\0')
		{
			if (arr[i] == ' ')
			{
				start_words[k] = i + 1;
				++k;
			}
			++s;
		}
		else
		{
			sum[s] = sum[s] + (int)arr[i];
			counter[s]++;
		}
	}
	int change=0,change2=0, change3 = 0;
	for (int c = 0; c < s-1; c++) 
	{
		for (int k = c+1; k < s; k++)
		{
			if (sum[c] >sum[k])
			{
				change = sum[c];
				sum[c] = sum[k];
				sum[k] = change;
				change2= start_words[c];
				start_words[c] = start_words[k];
				start_words[k] = change2;
				change3 = counter[c];
				counter[c] = counter[k];
				counter[k] = change3;
			}
		}
	}
	int x = 0;
	for (int p=0; p <s; p++)
	{
			for (int y = start_words[p]; y<start_words[p]+counter[p]; y++)
			{
					otv[x] = arr[y];
					x++;
				}
			otv[x] = ' ';
			x++;
	}

	cout << "Words to increase theS sum of character codes: ";
	for (int m = 0; m<N; m++) {
		cout <<  otv[m];
	}
	system("pause");
	return 0;
} 
