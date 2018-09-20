#include "stdafx.h" 
#include "iostream" 
#include "conio.h" 
using namespace std;

int main()
{
	float left, right, result;
	char sign;
	setlocale(0, "");
		cout << "Введите левый аргумент" << "\n";
				cin >> left;
		cout << "Введите правый аргумент" << "\n";
				cin >> right;
		cout << "Введите знак выражения" << "\n";
				cin >> sign;
		
				while (sign != '+' && sign != '-' && sign != '/' && sign != '*')
				{
					cout << "Вы ввели неверный знак, введите верный" << "\n";
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
								cout << "На ноль делить нельзя, введите другой делитель" << "\n";
								cin >> right;
								result = left / right;
								break;
							}
							else
							{
								result = left / right;
								break;
							}
					}
				

		cout << left << sign << right << "=" << result;
		_getch();
	return 0;
}