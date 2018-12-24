#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;

void quickSort(int *mas, int left, int right)
{
	int pivot;
	int l_hold = left;
	int r_hold = right; 
	pivot = mas[left];
	while (left < right) 
	{
		while ((mas[right] >= pivot) && (left < right))
			right--;
		if (left != right) 
		{
			mas[left] = mas[right]; 
			left++;
		}
		while ((mas[left] <= pivot) && (left < right))
			left++;
		if (left != right) 
		{
			mas[right] = mas[left];
			right--; 
		}
	}
	mas[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
	{
		quickSort(mas, left, pivot - 1);
	}
	else if (right > pivot)
	{
		quickSort(mas, pivot + 1, right);
	}
}
int main()
{
	const int size = 8;
	int massif[size];
	setlocale(0, "");
	cout << "Ìàññèâ:" << endl;
	for (int i = 0; i < size; i++)
	{
		massif[i] = rand();
		cout << massif[i] << endl;
	}
	quickSort(massif, 0, size-1); 
	cout << "Îòñîðòèðîâàííûé ïî âîçðàñòíèþ ìàññèâ:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << massif[i] << endl;
	}
	int k = 0;
	int massif_2[size];
	cout << "Íå÷¸òíûå çíà÷åíèÿ ìàññèâà:" << endl;
	for (int i = 0; i < size; i++)
	{
		if (massif[i] % 2 != 0)
		{
			massif_2[k] = massif[i];
			cout << massif_2[k] << endl;
			k++;
		}
	}
	int max = massif_2[0]; 
	int min = massif_2[0];
	int sum = 0;
	const int size_2 = k;
	for (int j = 0; j < size_2; j++)
	{
		if (massif_2[j] > max)
		{
			max = massif_2[j];
		}
		if (massif_2[j] < min)
		{
			min = massif_2[j];
		}
		sum += massif_2[j];
	}
	float crednee = sum / size_2;
	cout << "Ìàêñèìàëüíîå çíà÷åíèå: " << max << endl;
	cout << "Ìèíèìàëüíîå çíà÷åíèå: " << min << endl;
	cout << "Ñðåäíåå çíà÷åíèå: " << crednee << endl;
	_getch();
	return 0;
}
