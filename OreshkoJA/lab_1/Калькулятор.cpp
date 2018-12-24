#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	float first, second;
	cout << "Введите первое число:";
	cin >> first;
	char sign;
	cout << "Введите знак:";
	cin >> sign;
	cout << "Введите второе число:";
	cin >> second;
	float result;
	int error = 0;
	if (second == 0) {
		if (sign == '/') {
			cout << "Делить на ноль нельзя" << endl;
			error = 1;
		}
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
		default: 	error = 1;
			cout << "Неправильный ввод знака" << endl;
			break;
		}
		if (error == 1) {  }
		else
		{cout << "Результат:" << result << endl;}
	system("pause");
}