#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int choose, chislo, stepen;
	float function, result;

	cout << "Выберете операцию." << endl;
	cout << "1 - Возведение числа в степень." << endl;
	cout << "2 - Факториал числа." << endl;
	cout << "3 - Квадратный корень из числа." << endl;
	cout << "4 - Проверка числа на простоту" << endl << "Ваш выбор: ";
	cin >> choose;
	cout << "Введите число: ";
	cin >> chislo;

	switch (choose) {
	case 1:
		cout << "Введите степень: ";
		cin >> stepen;
		result = 1;
		if (stepen == 0) {
			result = 1;
		} else {
			for (int i = 0; i < stepen; i++) {
				result = result * chislo;
			}
		}
		cout << "Ответ: " << result << endl;
			break;

	case 2:
		result = 1;
		for (int i = 0; i < chislo; i++) {
			result = result * (chislo - i);
		}
		cout << "Ответ: " << result << endl;
			break;

	case 3:
		result = chislo;
		function = chislo;
		if (chislo < 0) {
			cout << "Ошибка: неправильный ввод числа." << endl;
		}
		else {
			while (1)
			{
				function = (chislo / function + function) / 2;
				if (result > function) {
					result = function;
				}
				else {
					cout << "Ответ: " << result << endl;
					system("pause");
					return 0;
				}
		    }
		}
			break;

	case 4:
		if ((chislo % 2 != 0) && (chislo % 3 != 0) && (chislo % 5 != 0)) {
			cout << "Ответ: Это число простое." << endl;
		}
		else {
			cout << "Ответ: Это число составное." << endl;
		}
			break;

	default:
		cout << "Ошибка: неправильный выбор операции." << endl;
		system("pause");
		return 0;
			break;
	}

	system("pause");
	return 0;
}