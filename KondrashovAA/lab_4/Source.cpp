#include <iostream>
#include <conio.h>

using namespace std;

double my_power(double a, int n) {
	double res = 1;
	if (n < 0) {
		n = -n;
		a = 1 / a;
	}
	while (n > 0) {
		res *= a;
		n--;
	}
	return res;
}

int my_fact(int a) {
	if (a < 0) {
		return -1;
	}
	int res = 1;
	for (; a > 1; a--) {
		res = res * a;
	}
	return res;
}

double my_sqrt(double a) {
	if (a == 0) {
		return 0;
	}
	double e = 0.000001;
	double x0 = a;
	double x1 = (x0 + a / x0) / 2;
	while (((x0 - x1) > e) || (-(x0 - x1) > e)) {
		x0 = x1;
		x1 = (x0 + (a / x0)) / 2;
	}
	return x1;
}

bool primality_check(int a) {
	if (a == 1) {
		return false;
	}
	bool res = true;
	int i = 2;
	double sqrt = my_sqrt(a) + 1;
	while ((i < sqrt) && res) {
		if (a % i == 0) {
			res = false;
		}
		i++;
	}
	return res;
}

int main() {
	double a = 0;
	int n = 0;

	cout << "Raise to the power" << endl;
	cout << "Enter the number:" << endl;
	cin >> a;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Enter the power:" << endl;
	cin >> n;
	cin.clear();
	cin.ignore(1000, '\n');
	if (a == 0 && n == 0) {
		cout << "Error: 0^0 is undefined" << endl << endl;
	}
	else {
		cout << a << "^" << n << " = " << my_power(a, n) << endl << endl;
	}

	cout << "Factorial" << endl;
	cout << "Enter the number:" << endl;
	cin >> n;
	cin.clear();
	cin.ignore(1000, '\n');
	if (n < 0) {
		cout << "Error: number should be non-negative" << endl << endl;
	}
	else {
		cout << n << "! = " << my_fact(n) << endl << endl;
	}

	cout << "Square root" << endl;
	cout << "Enter the number:" << endl;
	cin >> a;
	cin.clear();
	cin.ignore(1000, '\n');
	if (a < 0) {
		cout << "Error: number should be non-negative" << endl << endl;
	}
	else {
		cout << "Square root of " << a << " = " << my_sqrt(a) << endl << endl;
	}

	cout << "Primality check" << endl;
	cout << "Enter the number:" << endl;
	cin >> n;
	cin.clear();
	cin.ignore(1000, '\n');
	if (n < 1) {
		cout << "Error: number should be natural";
	}
	else if (primality_check(n)) {
		cout << "Number is prime";
	}
	else {
		cout << "Number is not prime";
	}
	
	_getch();

	return 0;
}