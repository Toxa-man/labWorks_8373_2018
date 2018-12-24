#include <iostream> 
#include <cstdlib> 
using namespace std;

int main()
{
	const  int size1(7);
	int arr1[size1], arr2[size1], i;
	cout << "1st array:   ";
	for (int i=0 ; i < size1; i++)
	{
		arr1[i] = 0;
	}
	cout << endl;
	for (i=0; i < size1; i++)
	{
		arr1[i] = rand();
		cout << arr1[i] << " ";
	}
	cout << endl;
	int c = 0;
	int i1 = 0;
	int change;
	cout << "sorted 1st array: ";
	while (c < size1)
	{
		i1 = c;
		while (i1 < size1)
		{
			if (arr1[i1] < arr1[c])
			{
				change = arr1[i1];
				arr1[i1] = arr1[c];
				arr1[c] = change;
			}
			i1++;
		}
		cout << arr1[c] << " ";
		c++;
	}
	cout << endl;

	cout << "2nd array:   ";
	int k = 0;
	int b = 0;
	int len;
	int sum(0), sr(0);
	for (k; k < size1; k++)
	{ 
		
			if ((arr1[k] % 2) == 1)
			{
				arr2[b] = arr1[k];
				cout << arr2[b] << "  ";
				b++;
				len = b;
			}
	}
	for (b = 0; b < len; b++)
	{
		sum += arr2[b];
	}
	int j ;
	int min = arr2[0];
	int max = arr2[0];
	for (j=0; j < len-1; j++)
	{
		if (arr2[j + 1] > max)
		{
			max = arr2[j + 1];
		}
		if (arr2[j + 1] < min)
		{
			min = arr2[j + 1];
		}
	}
	cout << endl;
	sr = sum / len;
	cout << endl;
	cout << "min of 2nd array: " << min << endl;
	cout <<"max of 2nd array: " << max << endl;
	cout << "Medium of 2nd array: " << sr << endl;
	system("pause");
	return 0;

}
