#include<conio.h>
#include<iostream>

using namespace std;

int main() {
	setlocale(0, "");
	float first, second, result;
	char sign;
	cout << "Введите 1 число." << endl;
	cin >> first;
	cout << "Введите символ операции." << endl;
	cin >> sign;
	cout << "Введите 2 число." << endl;
	cin >> second;
	//классический вариант ответной реакции после попытки деления на "0"
	/*if (second == 0 && sign == '/') {
		cout << "Ошибка. Вы пытались разделить на 0." << endl;
		_getch();
		return 0;
	}*/
	//альтернативный вариант после попытки деления на "0"
	if (second == 0 && sign == '/') {
		while (second == 0) {
			cout << "Ошибка. Вы пытались разделить на 0. Введите другой знаменатель." << endl;
			cin >> second;
		}
		result = first / second;
		cout << "Ответ: " << result;
		_getch();
		return 0;
	}
	switch (sign) {
	case '+': result = first + second;
		break;
	case '-': result = first - second;
		break;
	case '*': result = first * second;
		break;
	case '/': result = first / second;
		break;
	default: cout << "Ошибка. Вы ввели неподходящий символ операции." << endl;
		_getch();
		return 0;
	}
	cout << "Ответ: " << result;
	_getch();
	return 0;
}