#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;
const int con = 10;
int main()
{
	int j = 0;
	int i, s;
	cout << "Number 1:";
	srand(time(0));
	{int arr[con];
	for (i = 0; i < con; i++)
	{
		arr[i] = rand();
		cout << arr[i] << ' ';
	}
	cout << endl;
i = con;
while (i > 0) {
	j = i;
	while (arr[j] > arr[j - 1]) {
		s = arr[j];
		arr[j] = arr[j - 1];
		arr[j - 1] = s;
		j++;
	}
	i--;
}
		cout << "Number 2:";
		for (i = 0; i < con; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
		cout << "Odd numbers:";
		int arr2[con];
		int cons = 0;
		for (i = 0; i < con; i++) {
			if ((arr[i] % 2)==1) { 
				arr2[cons] = arr[i];
				cout << arr2[cons] << " ";
				cons++;
			}
		}
		cout << endl;
		int min = arr2[0];
		int max = arr2[0];
		double sum = 0;
		for (i = 0; i < cons; i++)
		{
			if (arr2[i] > max)
			{
				max = arr2[i];
			}
			if (arr2[i] < min) {
				min = arr2[i];
			}
			sum = sum + arr2[i];
		}
		sum = sum / cons;
		cout << "MAX: " << max << endl;
		cout << "MIN: " << min << endl;
		cout << "SUM: " << sum << endl;
	}
	system("pause");
	}


