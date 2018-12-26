#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	float left, right, result;
	char sign;

	cout << "Введите левый операнд: ";
	cin >> left;
	cout << "Введите правый операнд: ";
	cin >> right;
	cout << "Введите знак действия: ";
	cin >> sign;

	switch (sign) {
	case'+': result = left + right;
		break;
	case'-': result = left - right;
		break;
	case'*': result = left * right;
		break;
	case'/': if (right == 0) {
			     cout << "Ошибка: На ноль делить нельзя!" << endl;
				 system("pause");
				 return 0;
			 }
			 result = left / right;
		break;
	default:
		cout << "Ошибка: Введены неправильные данные." << endl;
		system("pause");
		return 0;
		break;
	}
    
	cout << "Результат: " << result << endl;
	
	system("pause");
	return 0;
}