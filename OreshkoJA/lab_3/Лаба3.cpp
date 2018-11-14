#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
const int con = 100;
int main()
{
	int pluss(0), index1(0), index2(0), error(0);
	int counter(0),prob(0), min, minind, probel(0),begin,end(0);
	char fn[con], fin[con];
	int help1[con] = { 0 };
	int help2[con] = { 0 };
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
	index1--;
	for (int i = 0; fn[i] != '\0'; i++)
	{
		if (fn[i] == ' ' || i == 0)
		{
			help2[counter] = prob;
			prob++;
			counter++;
		}
		else
		{
			prob++;
		}
	}
	counter = 0;
	while (index1+1 != index2)
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
		for (int i = 0; i < con; i++)
		{
			if (min == help1[i] ||error==1)
			{
				error = 1;
				help1[i] = help1[i + 1];
			}
		}
		error = 0;
		for (int i = 0; minind+1 != probel || minind ==0; i++)
		{
			if (fn[i]==' ' || fn[i] == (char) -52 )
			{
				probel++;
			}
			if (probel == minind && fn[i] !=' ')
			{
				for (int j = counter; fn[i]!=' '; j++)
					{ 
					if (fn[i - 1] == ' ' || i == 0)
					{
						begin = i;
					}
					if (fn[i] =='\0')
						break;
					else 
					{ 
						fin[j] = fn[i];
						counter++;
						i++;
						end++;
						index2++;
					}
				}
			}
			if (fn[i] == '\0')
				break;
			if (minind == 0)
			{
				probel = 2 ;
				minind = 1;
			}
		}
		for (int i = begin; i < con; i++)
		{
			fn[i] = fn[i + end + 1];
		}
		probel = 0;
		fin[counter] = ' ';
		counter++;
		index2++;
		end = 0;
	}
	fin[index1] = '\0';
	cout << fin << endl;
	system ("pause");
}