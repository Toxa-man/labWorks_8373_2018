#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	float number1, number2;
	char sign;
	float result;
	int error = 0;
	cout << "¬ведите первое число:";
	cin >> number1;
	cout << "¬ведите знак:";
	cin >> sign;
	cout << "¬ведите второе число:";
	cin >> number2;
		if (number2 == 0 && sign == '/')
		 {
			cout << "ќшибка, вы пытаетесь поделить на 0" << endl;
			error = 1;
		}
		else {
		switch (sign) {
		case '+': result = number1 + number2;
			break;
		case '-': result = number1 - number2;
			break;
		case '*': result = number1 * number2;
			break;
		case '/': result = number1 / number2;
			break;
		default: 	error = 1;
			cout << "ќшибка, вы вводите неправильный знак" << endl;
			break;
		}
	}
	if (error == 1) {
		cout << "ќшибка, проверьте правильность вводимых данных" << endl;
	}
	else
	{
		cout << "–езультат:" << result << endl;
	}
	system("pause");
}