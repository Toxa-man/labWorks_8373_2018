#include<conio.h>
#include<iostream>

using namespace std;

int main() {
	setlocale(0, "");
	float first, second, result;
	char sign;
	bool check = 0;
	cout << "Введите 1 число." << endl;
	cin >> first;
	cout << "Введите символ операции." << endl;
	cin >> sign;
	cout << "Введите 2 число." << endl;
	cin >> second;
	if (second == 0 && sign == '/') {
		cout << "Ошибка.Вы попытались разделить на ноль." << endl;
		check = 1;
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
		check = 1;
	}
	if (check == 0) {
		cout << "Ответ: " << result;
	}
	_getch();
	return 0;
}
