#include <iostream>
#include <cstdlib>
using namespace std;
int main() 
{
	const int ARR_SIZE = 9;
	int arr[ARR_SIZE];
	int secarr[ARR_SIZE];

	for (int counter = 0; counter < ARR_SIZE; counter++)
	{
		arr[counter] = rand();
		cout << arr[counter]<< " ";

	}
	cout << "\nSorted arr:" << endl;
		int temp;
		for (int i = 0; i < ARR_SIZE - 1; i++) 
		{
			for (int j = 0; j < ARR_SIZE - i - 1; j++) 
			{
				if (arr[j] > arr[j + 1]) 
				{
					// меняем элементы местами
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < ARR_SIZE; i++)
		{
			cout << arr[i] << " ";
		}
		int counter2 = 0;
		for (int i = 0; i < ARR_SIZE; i++) 
		{
			if (arr[i] % 2 == 1)
			{
				secarr[counter2] = arr[i];
				counter2++;
			}
			else {
				secarr[i] = 0;
			}
		}
		cout << "\nSecond arr:\n";
		for (int i = 0; i < counter2; i++)
		{
			cout << secarr[i] << " ";
		}
		cout << "\nmin: " << secarr[0];
		cout << "\nmax: " << secarr[counter2 - 1];
		int avg_arr = 0;
		int cntr = 0;
		for (int i = 0; i < counter2; i++)
		{
			avg_arr += secarr[i];
			cntr += 1;
		}
		cout << "\nAverage number is " << avg_arr / cntr << endl;

		system("pause");
		return 0;

	
}