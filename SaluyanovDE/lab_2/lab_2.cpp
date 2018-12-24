#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	const int ArrLen = 20;
	int Arr1[ArrLen], Arr2[ArrLen];
	int buffer, min = 0, max = 0, counter = 0, a = 0;
	float sum = 0;

	cout << "First Array is: ";
	for (int i = 0; i < ArrLen; i++)
	{
		Arr1[i] = rand() % 100 + 1;
		cout << Arr1[i] << ' ';
	}
	cout << endl;


	while (a < ArrLen)
	{
		if (a + 1 != ArrLen && Arr1[a] > Arr1[a + 1])
		{
			buffer = Arr1[a];
			Arr1[a] = Arr1[a + 1];
			Arr1[a + 1] = buffer;
			counter = 1;
		}
		a++;
		if (a == ArrLen && counter == 1)
		{
			counter = 0;
			a = 0;
		}
	}


	cout << "First array(sorted) is: ";
	for (int i = 0; i < ArrLen; i++)
	{
		cout << Arr1[i] << ' ';
	}
	cout << endl;

	
	counter = 0;
	cout << "Second array is: ";
	for (int i = 0; i < ArrLen; i++)
	{
		if (Arr1[i] % 2 == 1)
		{
			Arr2[counter] = Arr1[i];
			cout << Arr2[counter] << ' ';
			counter++;
		}
	}
	cout << endl;


	min = Arr2[0];
	max = Arr2[0];
	sum = Arr2[0];
	for (int i = 1; i < counter; i++)
	{
		sum = sum + Arr2[i];
		if (Arr2[i] < min)
		{
			min = Arr2[i];
		}
		if (max < Arr2[i])
		{
			max = Arr2[i];
		}
	}
	cout << "In second array: \n" << "Min. value is " << min << "\n" << "Max. value is " << max << "\n" << "Average value is " << sum / counter << endl;
	system("pause");
	return 0;
}
