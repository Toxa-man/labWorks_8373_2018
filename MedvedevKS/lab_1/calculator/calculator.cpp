#include "stdafx.h"
#include "iostream"
#include "conio.h"
using namespace std;

int main()
{
	float left, right, result; 
	char sign;
	setlocale(0, "");
	do {
		cout << "Введите левый оперант: " << endl;
		cin >> left;
		cout << "Введите правый оперант: " << endl;
		cin >> right;
		cout << "Введите знак выражения:" << endl;
		cin >> sign;
			while (!(sign == '+' || sign == '-' || sign == '*' || sign == '/'))
				{
				cout << "Введите правильный знак: " << endl;
				cin >> sign;
				}

			switch (sign)
				{
				case'+':
					result = left + right;
					break;
				case'-':
					result = left - right;
					break;
				case'*':
					result = left*right;
					break;
				case'/':
					if (right == 0)
						{
						cout << "Вы попытались разделить на ноль - введите новое выражение!"<<endl;
						continue;
						}
					else
						{
						result = left / right;
						break;
						}
				}

		cout << "Результат: " << endl << left << sign << right << "=" << result;
		_getch();
	} while (right == 0 && sign =='/');
	return 0;
}
