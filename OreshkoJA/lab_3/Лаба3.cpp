#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
const int con = 100;
int main()
{
	int pluss(0), index1(0), index2(0), error(0), dop, index3;
	int counter(0),prob(0), min, minind, probel(0),begin,end(0);
	char fn[con], fin[con];
	int help1[con] = { 0 };
	int help2[con] = { 0 };
	cout << "Input string:";
	cin.getline(fn, con);
	for (int i=0; fn[i-1] != '\0';i++)
	{
		if (fn[i] == ' ' || fn[i] == '\0')
		{
				help1[counter] = pluss;
				++counter;
				pluss = 0;
				index1++;
		}
		else
		{
				pluss = pluss + (int)fn[i];
				index1++;
		}
	}
	counter = 0;
	for (int i = 0; fn[i-1] != '\0'; i++)
	{
		if (fn[i] == ' ' || fn[i] == '\0')
		{
			help2[counter] = prob;
			prob=0;
			counter++;
		}
		else
		{
			prob++;
		}
	}
	counter = 0;
	while (index1 != index2)
	{
		min = help1[0];
		minind = 0;
		for (int i = 0; help1[i] != 0; i++)
		{
			if (help1[i] < min)
			{
				min = help1[i];
				minind = i;
			}
		}
		for (int i = minind; i < con; i++)
		{
			help1[i] = help1[i + 1];
		}
		error = 0;
		for (int i = minind; i < con; i++)
		{
			help2[i] = help2[i + 1];
		}
		error = 0;

		for (int i = 0; i != minind; i++)
		{
			counter = counter + help2[i];
		}
		counter += minind;
		for (int i = counter; fn[i] != ' ' ; i++)
		{
			if (fn[i] != '\0')
			{
				fin[index2] = fn[i];
				index2++;
				probel++;// изменить
			}
			else
				break;
		}
		if (index2 != index1)
		{
			fin[index2] = ' ';
			index2++;
		}
		for (int i = counter; i < con; i++)
		{
			fn[i] = fn[i + probel + 1];
		}
		counter = 0;
		probel = 0;
	}
	fin[index1] = '\0';
	cout << fin << endl;
	system ("pause");
}