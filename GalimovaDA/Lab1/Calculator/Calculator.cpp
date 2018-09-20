#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(0, "");
	float left, right, result;
	cout << "¬ведите левый операнд";
	cin >> left;
	cout << "¬ведите правый операнд";
	cin >> right;
	char sign;
	cout << "¬ведите знак";
	cin >> sign;
	switch (sign) {
	case'+':result = left + right;
		break;
	case'-':result = left - right;
		break;
	case'*':result = left * right;
		break;
	case'/':if (right = '0') {
		cout << "ƒеление на ноль невозможно";
		_getch();
		break;
	}
			else {
		result = left / right;
		break;
	}
	default: cout << "¬ведите правильный знак";
	}
	cout << "–езультат: " << result;
	_getch();
}