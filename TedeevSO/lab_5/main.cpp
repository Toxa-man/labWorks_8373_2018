#include <iostream>

using namespace std;

void sum(int *m1, int *m2, int *m3, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(m3 + i * size + j) = *(m1 + i * size + j) + *(m2 + i * size + j);
        }
    }
}

void sub(int *m1, int *m2, int *m3, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(m3 + i * size + j) = *(m1 + i * size + j) - *(m2 + i * size + j);
        }
    }
}

void mul(int *m1, int *m2, int *m3, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(m3 + i * size + j) = 0;
            for (int k = 0; k < size; k++) {
                *(m3 + i * size + j) += *(m1 + i * size + k) * *(m2 + k * size + j);
            }
        }
    }
}

void print(int *m, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << *(m + i * size + j) << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(0, "rus");
    const int n = 2;
    int m1[n * n], m2[n * n], m3[n * n];

    cout << "Введите первую матрицу " << n << "x" << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> *(m1 + i * n + j);
        }
    }

    cout << "Введите вторую матрицу " << n << "x" << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> *(m2 + i * n + j);
        }
    }

    char sign = 1;
    while (true) {
        cout << "Введите операцию: ";
        cin >> sign;
        if (sign == 27) break;
        cout << sign << endl;

        bool f = true;
        switch (sign) {
            case '+':
                sum(m1, m2, m3, n);
                break;
            case '-':
                sub(m1, m2, m3, n);
                break;
            case '*':
                mul(m1, m2, m3, n);
                break;
            default:
                f = false;
                cout << "Неизвестная операция." << endl;
                break;
        }

        if (f) {
            cout << "Результат:" << endl;
            print(m3, n);
            cout << endl;
        }

        cout << "Продолжить? (y/n)" << endl;
        cin >> sign;
        if (sign == 'n') break;
    }

    cout << endl << "Конец работы." << endl;
    return 0;
}
