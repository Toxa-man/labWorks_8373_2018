#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(0, "");

	const int n = 10;
	int arr1[n]; // ������ �������

	for (int i = 0; i < n; i++) // �������� ������� �� ��������� ���������
		arr1[i]=rand();

	for (int i = 0; i < n; i++) // ����� �������
		cout << arr1[i] << "  ";

	cout << endl << endl;
	
	int temp; // ��������� ���������� ��� ����������

	// ���������� ������� ���������
	int i = 0, j = 0;
	while (i < n-1)
	{
		i++;
		while (j < n - i - 1) 
		{
			j++;
			if (arr1[j] > arr1[j + 1]) 
			{
				temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) // ����� �������
		cout << arr1[i] << "  ";

	cout << endl << endl;

	int arr2[n / 2];

	i = 0, j = 0;

	// ����� j - ����� �������� � arr2, � i - ����� �������� � arr1
	while (j < n / 2)
		while (i < n)
			if (i % 2 == 0)
				i = i + 1;
			else 
			{
				arr2[j] = arr1[i];
				j = j + 1;
			}

	for (int i = 0; i < n; i++) // ����� �������
		cout << arr2[i] << "  ";

	system("pause");
	return 0;
}