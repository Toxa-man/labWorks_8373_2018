#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	const int size = 10;
	int arr1[size];
	int arr2[size];
	cout << "first arr ";
	cout << endl;
	srand(time(0));
		for (int i = 0; i < size; i++)
		{
				arr1[i] = rand()%20;
				cout << arr1[i] << " ";
		}


		
	cout << endl;
	cout << "sorted arr "<<endl;

	
	int b = 0;
	int c = 0;
	while ( c < size)
	{
		while (c < size)
		{
			b = c;
			while (b < size)
			{
				if (arr1[b] < arr1[c])
				{
					int temp;
					temp = arr1[b];
					arr1[b] = arr1[c];
					arr1[c] = temp;
				}
				b++;
			}
			
			cout << arr1[c] << " ";
			c++;
		}
		c++;
	}

	
	
	cout << endl;
	
	cout << "second arr "<<endl;
	int oddnum = 0;
	for (int z = 0; z < size; z++)
	{
		if (arr1[z] % 2 == 1)
		{
			arr2[oddnum] = arr1[z];
			oddnum++;
		}
		else 
		{
			arr2[z] = 0;
		}
	}



	for (int w = 0; w < oddnum; w++)
	{
		cout << arr2[w] << " ";
	}
	float average = 0;
	float denom=0;
	for (int q = 0; q < oddnum; q++)
	{
		average = average + arr2[q];
		denom = denom + 1;
	}
	float result;
	result = average / denom;
	cout << endl;
	cout << "average number  "<< endl; 
	cout << result << endl;
	cout << "arr's min number "<<endl;
	cout <<  arr2[0]<<endl;
	cout << "arr's max number "<<endl;
	cout << arr2[oddnum - 1]<<endl;
	
	system("pause");
	return(0);
		

}
