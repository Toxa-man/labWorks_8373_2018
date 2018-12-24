#include "stdafx.h"
#include <iostream>
#include "string.h"
using namespace std;


int main()
{
	setlocale(0, "");
	char str1[30];
	char str2[30];
	bool Gear = false, Check = false;
	int counter = 0;


	cout << "Программа выведет координаты первой строки (номера позиций в строке, начиная с нулевой) в которых содержится вторая строка. Если вторая строка не содержится в первой хотя бы один раз, то программа выведет *Вхождений не обнаружено*" << endl;
	cout << "Введите первую строку, длиной не более 30 символов: ";
	cin.getline(str1, 30);
	cout << "Введите вторую строку, длиной не более 30 символов: ";
	cin.getline(str2, 30);


	if (strlen(str1) < strlen(str2))
	{
		Check = false;
	}
	else
	{
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i] == str2[0])
			{
				Gear = false;
				while (str1[i + counter] == str2[0 + counter] && Gear == false)
				{
					counter++;
					if (counter == strlen(str2))
					{
						Check = true;
						for (int j = i; j < strlen(str2) + i; j++)
						{
							cout << j << ' ';
						}
						counter = 0;
						Gear = true;
					}
				}
			}
		}
	}
	if (Check == false)
	{
		cout << "Вхождений не обнаружено\n";
	}
	system("pause");
	return 0;
}