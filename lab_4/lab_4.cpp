#include <iostream>
using namespace std;

void power(int digit) {
	int pow, i = 0;
	float b = 1.0;
	cout << "Введите степень: ";
	cin >> pow;
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
		cout << "Число " << digit << " в степени " << pow << " равно " << b;
	}
	else {
		cout << "Число " << digit << " в степени " << pow << " не существует";
	}
	cout << endl;
}

void factorial(int digit) {
	int p = 1, fac = 1;
	if (digit >= 0) {
		while (p <= digit) {
			fac *= p;
			p++;
		}
		cout << "Факториал числа " << digit << " равен " << fac;
	}
	else {
		cout << "Факториала числа " << digit << " не существует";
	}
	cout << endl;
}

void root(int digit) {
	if (digit >= 0) {
		cout << "Корень из числа " << digit << " равен " << sqrt(digit);
	}
	else {
		cout << "Корня из числа " << digit << " не существует";
	}
	cout << endl;
}

void simple(int digit) {
	if (digit <= 1) {
		cout << "Число " << digit << " не простое";
	}
	else {
		int a = 2, k = 0;
		while (a < digit) {
			if (digit%a == 0) {
				k++;
			}
			a++;
		}
		if (k == 0) {
			cout << "Число " << digit << " простое";
		}
		else {
			cout << "Число " << digit << " не простое";
		}
	}
	cout << endl;
}

int main() {
	setlocale(0, "");
	int digit;
	cout << "Введите число: ";
	cin >> digit;
	power(digit);
	factorial(digit);
	root(digit);
	simple(digit);
	return 0;
}