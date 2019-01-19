#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

int main()
{
	const int size = 10;
	int array[size];

	//filling the array with random numbers
	cout << "Initial array: " << endl;
	for (int i = 0; i < size; i++)
	{
		array[i] = rand();
		cout << array[i] << endl;
	}

	cout << endl;

	//sorting the array
	int temp = 0;
	bool exit = false;
	while (!exit)
	{
		exit = true;
		for (int i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				exit = false;
			}
		}
	}
	
	cout << "Sorted array: " << endl;
	for (int i = 0; i < size; i++) 
	{
		cout << array[i] << endl;
	}

	cout << endl;

	//creating new array
	cout << "Array of odd elements: " << endl;
	int oddarray[size];
	int oddsize = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] % 2 == 1)
		{
				oddarray[oddsize] = array[i];
				oddsize++;
		}
	}

	for (int i = 0; i < oddsize; i++)
	{
		cout << oddarray[i] << endl;
	}

	cout << endl;

	//search of max, min and average

	cout << "Search of max, min and average:" << endl;
	int sum = 0, max = array[0], min = array[0];
	int average;
	for (int i = 1; i < oddsize; i++)
	{
		if (oddarray[i] > max)
		{	
			max = oddarray[i]; 
		}
		if (oddarray[i] < min) 
		{ 
			min = oddarray[i]; 
		}
		sum = sum + oddarray[i];
	}
	average = sum / size;

	cout << "max: " << max << endl;
	cout << "min: " << min << endl;
	cout << "average: " << average << endl;

	system("pause");
	return 0;
}