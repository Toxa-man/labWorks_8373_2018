#include "stdafx.h"
#include "iostream"
#include "conio.h"
using namespace std;


int main()
{
	const int size(11);
	int random_arr[size], odd_arr[size];
	cout << "Generated 1st array: \t\t";
	for (int i(0); i < size; i++)
	{
		random_arr[i] = rand();
		cout << random_arr[i] << " ";
	}
	cout << endl;
	int i = 0;
	int i1(0);
	int changer;
	cout << "Sorted 1st array: \t\t";
	while (i < size)
	{
		i1 = i;
		while (i1 < size)
		{
			if (random_arr[i1] < random_arr[i])
			{
				changer = random_arr[i1];
				random_arr[i1] = random_arr[i];
				random_arr[i] = changer;
			}
			i1++;
		}
		cout << random_arr[i] << " ";
		i++;
	}
	cout << endl;
	i = 0;
	i1 = 0;
	int sum_of_odd_arr(0);
	cout << "2nd array: \t\t\t";
	while (i < size)
	{
	    if (random_arr[i] % 2 == 1)
		{
		    odd_arr[i1]=random_arr[i];
		    sum_of_odd_arr += odd_arr[i1];
		    cout << odd_arr[i1] << " ";
		    i1++;
		}
	    i++;
	}
	cout << endl;
	cout << "Min element of 2nd arr: \t" << odd_arr[0] << endl;
	cout << "Max element of 2nd arr: \t" << odd_arr[i1-1] << endl;
	cout << "Average amounth of 2nd arr elements:\t" << sum_of_odd_arr/float(i1) << endl;
	_getch();
	return 0;
}
