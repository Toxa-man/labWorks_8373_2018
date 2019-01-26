#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    setlocale(0, "rus");
    srand(time(NULL));
    const int n = 10;
    int arr1[n];

    for (int i = 0; i < n; i++) {
        arr1[i] = rand();
    }

    cout << "Исходный массив:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;


    int a = 0, b = 0, temp;
    while (a < n - 1) {
        b = 0;
        while (b < n - a - 1) {
            if (arr1[b] > arr1[b + 1]) {
                swap(arr1[b], arr1[b + 1]);
            }
            b++;
        }
        a++;
    }

    cout << "После сортировки:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;


    int arr2[n];
    int t = 0;

    for (int i = 0; i < n; i++) {
        if (arr1[i] % 2 == 1) {
            arr2[t] = arr1[i];
            t++;
        }
    }

    if (t == 0) {
        cout << "Нечетных элементов нет." << endl;
    } else {
        cout << "Второй массив:" << endl;
        for (int i = 0; i < t; i++) {
            cout << arr2[i] << " ";
        }
        cout << endl;

        int minimum = arr2[0], maximum = arr2[t - 1];
        float sum = 0, average;

        for (int i = 0; i < t; i++) {
            sum += arr2[i];
        }
        average = sum / t;

        cout << "Среднее значение: " << average << endl;
        cout << "Минимальный элемент: " << minimum << endl;
        cout << "Максимальный элемент: " << maximum << endl;
    }

    return 0;
}
