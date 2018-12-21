#include <iostream>
using namespace std;

float power(int digit, int pow) {
	int  i = 0;
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

float factorial(int digit) {
	int p = 1, fac = 1;
	if (digit >= 0) {
		while (p <= digit) {
			fac *= p;
			p++;
		}
		return fac;
	}
}

float root(float digit) {
	float sqrt = digit / 2;
	float temp;
	do {
		temp = sqrt;
		sqrt = (temp + (digit / temp)) / 2;
	} while ((temp - sqrt) != 0);
	return sqrt;
}

float simple(int digit) {
	int k = 0, i = 0;
	while (i < digit / 2){
		i++;
		if (digit % i == 0) {
			k++;
			if (k == 2) {
				break;
			}
		}
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
	if (digit == 0 && pow == 0) {
		cout << "Числа " << digit << " в степени " << pow << " не существует";
	}
	else {
		if (pow == 0) {
			cout << "Число " << digit << " в степени " << 0 << " равно " << 1;
		}
		else {
			float b = power(digit, pow);
			cout << "Число " << digit << " в степени " << pow << " равно " << b;
		}
	}
	cout << endl;
	if (digit >= 0) {

		float fac = factorial(digit);
		cout << "Факториал числа " << digit << " равен " << fac;
		cout << endl;
		if (digit == 0) {
			cout << "Корень из числа " << digit << " равен " << 0;
		}
		else {
			float roo = root(digit);
			cout << "Корень из числа " << digit << " равен " << roo;
		}
	}
	else {
		cout << "Факториал числа " << digit << " не существует";
		cout << endl;
		cout << "Корень из числа " << digit << " не существует";
	}
	cout << endl;
	if (digit <= 1) {
		cout << "Число " << digit << " не простое";
	}
	else {
		float k = simple(digit);
		if (k == 1) {
			cout << "Число " << digit << " простое";
		}
		else {
			cout << "Число " << digit << " не простое";
		}
	}
	cout << endl;
	return 0;
}
