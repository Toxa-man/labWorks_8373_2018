#include <iostream> 
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));

	const int size = 10;
	int arr[size]; int arrn[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
		cout << i + 1 << ":" << arr[i] << endl;
	}

	int i = 0, j = 0, u = 0, l = 0;
	int q, min, k;
	float sred = 0, sum = 0;

	while (i < size)
	{
		j = i;
		min = arr[j];			
		k = j;					
		while (j < size)
		{
			if (arr[j] < min)
			{
				min = arr[j];	
				k = j;			
			}
			j++;
		}

		q = arr[i];
		arr[i] = arr[k];
		arr[k] = q;
		i++;
	}

	int counter = 0;
	i = 0;

	cout << "Sorted array:";
	while (i < size)
	{
		cout << arr[i] << ' ';
		i++;
	}
	cout << endl;

	for (int z = 0; z < size; z++)
	{
		if (arr[z] % 2 != 0)
		{
			arrn[counter] = arr[z];
			counter++;
		}

	}

	cout << "Nechet array:";
	for (int l = 0; l < counter; l++)
	{
		cout << arrn[l] << " ";
		sum += arrn[l];

	}
	cout << endl;

	cout << "MaxNechet:" << arrn[counter - 1] << endl;
	cout << "MinNechet:" << arrn[0] << endl;
	cout << "SrznachNechet:" << sum / counter << endl;

	system("pause");
	return(0);
}