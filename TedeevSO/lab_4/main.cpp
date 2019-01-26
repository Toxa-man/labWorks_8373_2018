#include <iostream>

using namespace std;

double module(double a) {
    if (a < 0) a = -a;
    return a;
}

int power(double a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int factorial(int a) {
    int result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
    }
    return result;
}

double sqrt(double a) {
    double e = 0.00000001, result = a;
    while (e < module(result * result - a)) {
        result = 0.5 * (result + a / result);
    }
    return result;
}

bool prime(int a) {
    int c = 0;
    for (int i = 1; i <= a; i++) {
        if (a % i == 0) c++;
    }
    return c == 2;
}

int main() {
    setlocale(0, "rus");
    double a;
    int b;

    cout << "Введите параметры возведения в степень через пробел: ";
    cin >> a >> b;
    cout << a << " ^ " << b << " = " << power(a, b) << endl;

    cout << "Введите аргумент факториала: ";
    cin >> b;
    cout << b << "! = " << factorial(b) << endl;

    cout << "Введиите аргументы квадратного корня: ";
    cin >> a;
    cout << "sqrt(" << a << ") = " << sqrt(a) << endl;

    cout << "Введите аргументы для проверки на простоту: ";
    cin >> b;
    if (prime(b)) {
        cout << "Число " << b << " является простым." << endl;
    } else {
        cout << "Число " << b << " не является простым." << endl;
    }

    return 0;
}
