#include <iostream>
using namespace std;

void power(int digit, int pow) {
	int pow, i = 0;
	float b = 1.0;
	if (digit != 0 && pow != 0) {
		if (pow > 0) {
			while (i != pow) {
				b *= digit;
				i++;
			}
		}
		else if (pow < 0) {
			while (i != pow) {
				b /= digit;
				i--;
			}
		}
		else {
			b = 1;
		}
		return b;
	}
}

void factorial(int digit) {
	int p = 1, fac = 1;
	if (digit >= 0) {
		while (p <= digit) {
			fac *= p;
			p++;
		}
		return fac;
	}
}

void root(int digit) {
	float root = 0.00;
	while (root*root < digit) {
		root += 0.01;
	}
	root -= 0.01;
	return root;
}

void simple(int digit) {
	int a = 2, k = 0;
	while (a < digit) {
		if (digit%a == 0) {
			k++;
		}
		a++;
	}
	return k;
}

int main() {
	setlocale(0, "");
	int digit, pow;
	cout << "Введите число: ";
	cin >> digit;
	cout << "Введите степень: ";
	cin >> pow;
	if (digit != 0 && pow != 0) {
		power(digit, pow);
		cout << "Число " << digit << " в степени " << pow << " равно " << b;
	}
	else {
		cout << "Число " << digit << " в степени " << pow << " не существует";
	}
	cout << endl;
	if (digit >= 0) {
		factorial(digit);
		cout << "Факториал числа " << digit << " равен " << fac;
		cout << endl;
		root(digit);
		cout << "Корень из числа " << digit << " равен " << root;
	}
	else {
		cout << "Факториала числа " << digit << " не существует";
		cout << endl;
		cout << "Кореня из числа " << digit << " не существует";
	}
	cout << endl;
	if (digit <= 1) {
		cout << "Число " << digit << " не простое";
	}
	else {
		simple(digit);
		if (k == 0) {
			cout << "Число " << digit << " простое";
		}
		else {
			cout << "Число " << digit << " не простое";
		}
	}
	cout << endl;
	return 0;
}
