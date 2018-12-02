#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;

const int mas_size = 10;

int main()
{
	srand(time(0)); //do not delete or random Function doesn't work well

	int mas_random[mas_size];
	int mas_odd[mas_size];
	int a = 0, odd = 0, c, k;

	cout << "First mas: " << endl;

	for (int i = 0; i < mas_size; i++)
	{
		mas_random[i] = rand() % 100 + 1;
		cout << mas_random[i] << " ";
	}
	cout << endl;
	cout << endl;

	cout << "First mas after sorting process: " << endl;	

	for (int j = 0; j < mas_size; j++)
	{
		while (j < mas_size)
		{
			a = j;
			while (a < mas_size)
			{
				if (mas_random[a] < mas_random[j])
				{
					c = mas_random[a];
					mas_random[a] = mas_random[j];
					mas_random[j] = c;
				}
				a++;
			}
			if (mas_random[j] % 2 == 1)
			{
				mas_odd[odd] = mas_random[j];
				odd++;
			}
			cout << mas_random[j] << " ";
			j++;
		}
	}

	cout << endl;
	cout << endl;

	cout << "Second mas: " << endl;

	for (int k = 0; k < odd; k++)
	{
		cout << mas_odd[k] << " ";
	}
	cout << endl;

	int Min = mas_odd[0];
	int Max = mas_odd[1];

	float sum = 0;

	for (k = 0; k < odd; k++)
	{
		if (mas_odd[k] < Min)
		{
			Min = mas_odd[k];
		}
		if (mas_odd[k] > Max)
		{
			Max = mas_odd[k];
		}
		sum += mas_odd[k];
	}
	cout << endl;

	cout << "Minimum element of second mas: " << Min << endl;
	cout << "Maximum element of second mas: " << Max << endl;
	cout << "Average element of second mas: " << sum / odd << endl;

	_getch();
	return 0;
}
