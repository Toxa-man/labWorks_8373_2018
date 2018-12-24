#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

int main()
{
	const int razm = 10;
	int i;
	cout << "Mass 1:";
	srand(time(0));
	{
	int arr[razm];
	for (i = 0; i < razm; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << ' ';
	}
	cout << endl;
	int T = 0;
	int a = 0;
	for (int i = 1; i < razm; i++)
	{
		T = arr[i];
		a = i - 1;
		while ((a >= 0) && (arr[a] > T))
		{
			arr[a + 1] = arr[a];
			a = a - 1;
			arr[a + 1] = T;
		}
	}
	cout << "Mass 2:";
	for (i = 0; i < razm; i++) { cout << arr[i] << ' ';	}
	cout << endl;

	int min = arr[0];
	int max = arr[0];
	int sum = 0;
	cout << "Mass 3:";
	for (i = 0; i < razm; i++)
	{
		if (arr[i] % 2 == 1) { cout << arr[i] << " "; }
	}
	cout << endl;

	cout << "Control numbers:" << endl;
	int sred;
	for (i = 1; i < razm; i++)
	{
		if (arr[i] > max) { max = arr[i]; } 
		if (arr[i] < min) { min = arr[i]; }
		sum = sum + arr[i];
		sred = sum / razm;
	}
	cout << "MAX: " << max << endl;
	cout << "MIN: " << min << endl;
	cout << "SRED: " << sred << endl;
	}
	system("pause");
}