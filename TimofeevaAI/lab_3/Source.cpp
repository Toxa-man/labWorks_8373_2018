#include <iostream>
#include <string>
#include<stdio.h>

using namespace std;

int main() {
	char str[100][100];
	cout << "Enter a number of words:" << endl;
	int n;
	cin >> n;

	cout << "Enter words:" << endl;
	for (int i = 0; i < n; i++)
		cin >> str[i];

	int a[100], och[100];
	for (int i = 0; i < n; i++)
	{
		int sum = 0, s = strlen(str[i]);

		for (int j = 0; j < s; j++)
		{
			sum += (int)str[i][j];
		}
		a[i] = sum;
		och[i] = i;
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				int q = a[i];
				a[i] = a[j];
				a[j] = q;

				q = och[i];
				och[i] = och[j];
				och[j] = q;
			}
		}


	}

	cout << "Sorted string:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << str[och[i]];
		if (i != n - 1)
			cout << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}