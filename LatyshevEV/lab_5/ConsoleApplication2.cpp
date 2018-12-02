#include <algorithm>
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int const max_size = 10;

void input(int* matrix, int length, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < length; k++)
		{
			int a;
			cin >> a;
			*(matrix + i * max_size + k) = a;
		}
	}
}
void my_print(int* matrix, int length, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < length; k++)
		{
			cout << *(matrix + i * max_size + k) << ' ';
		}
		cout << endl;
	}
}

void summ(int* matrix1, int* matrix2, int* result_matrix, int length1, int length2, int height1, int height2)
{
	if (length1 != length2 || height1 != height2)
	{
		cout << "Impossible to get Sum" << endl;
	}
	else
	{
		for (int i = 0; i < length1; i++)
		{
			for (int k = 0; k < height1; k++)
			{
				int a = *(matrix1 + i * max_size + k) + *(matrix2 + i * max_size + k);
				*(result_matrix + i * max_size + k) = a;
			}
		}
		my_print((int*)result_matrix, length2, height1);
	}
}

void difference(int* matrix1, int* matrix2, int* result_matrix, int length1, int length2, int height1, int height2)//tupe boolean
{
	if (length1 != length2 || height1 != height2)
	{
		cout << "Impossible to get Difference" << endl;
	}
	else
	{
		for (int i = 0; i < length1; i++)
		{
			for (int k = 0; k < height1; k++)
			{
				int a = *(matrix1 + i * max_size + k) - *(matrix2 + i * max_size + k);
				*(result_matrix + i * max_size + k) = a;
			}
		}
		my_print((int*)result_matrix, length2, height1);
	}
}

void multiplication(int* matrix1, int* matrix2, int* result_matrix, int length1, int length2, int height1, int height2)
{
	if (length1 != height2)
	{
		cout << "Multiplication is impossible!" << endl;
	}
	else
	{
		for (int i = 0; i < height1; i++)
		{
			for (int j = 0; j < length2; j++)
			{
				int element = 0;
				for (int k = 0; k < length1; k++)
				{
					element += (*(matrix1 + i * max_size + k)) * (*(matrix2 + k * max_size + j));
				}
				*(result_matrix + i * max_size + j) = element;
			}
		}
		my_print((int*)result_matrix, length2, height1);
	}
}

int main()
{
	int length1, length2, height1, height2;
	int matrix1[max_size][max_size], matrix2[max_size][max_size], result_matrix[max_size][max_size];
	cout << "Length of 1st matrix: ";
	cin >> length1;
	cout << "Height of 1st matrix: ";
	cin >> height1;
	cout << "Length of 2nd matrix: ";
	cin >> length2;
	cout << "Height of 2nd matrix: ";
	cin >> height2;
	cout << "Write first matrix here: " << endl;
	input((int*)matrix1, length1, height1);
	cout << "Write second matrix here: " << endl;
	input((int*)matrix2, length2, height2);
	bool flag = false;
	cout << "Press : s - to summarize, d - to subtract, m - to multiply, q - to quit" << endl;
	while (flag == false)
	{
		char answer = _getch();
		if (answer == '\0')
		{
			continue;
		}

		switch (answer)
		{
		case ('s'):  summ((int*)matrix1, (int*)matrix2, (int*)result_matrix, length1, length2, height1, height2);
			break;
		case ('d'):  difference((int*)matrix1, (int*)matrix2, (int*)result_matrix, length1, length2, height1, height2);
			break;
		case ('m'): multiplication((int*)matrix1, (int*)matrix2, (int*)result_matrix, length1, length2, height1, height2);
			break;
		case('q'): flag = true;
			break;
		default:
			cout << "Don't understand what to do, none of keys S, D, M, Q was pressed " << endl;
			break;
		}
		if (!flag)
		{
			cout << "Press : s - to summarize, d - to subtract, m - to multiply, q - to quit" << endl;
		}
	}
	return 0;
}
