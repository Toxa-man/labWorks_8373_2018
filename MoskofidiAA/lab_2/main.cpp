#include <iostream>

using namespace std;

int main()
{
    const int size = 10;
    int arr1[size];
    for (int i = 0; i < size; i++)
    {
        arr1[i] = rand();
        cout << arr1[i] << "  " << endl;
    }
    cout << endl;
    int i = 0;
    cout <<"Even-numbered: ";
    while (i <= size)
    {
        if (arr1[i] % 2 == 0) {
            cout << arr1[i] << "  ";
        }
        ++i;
    }
    cout<< endl;
    int j = 0;
    int arr2[size];
    cout << "Uneven elements: ";
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] % 2 != 0) {
            arr2[j] = arr1[i];
            j++;
            cout << arr1[i] << "  ";
        }
    } cout << endl;
    int min = arr2[0];
    int max = arr2[0];
    int sum = arr2[0];
    int srznach;
    for (int i = 1; i < j; i++)
    {
        if (arr2[i] < min) {
            min = arr2[i];
        }
        if (arr2[i] > max) {
            max = arr2[i];
        }
        sum += arr2[i];
    }
    srznach = sum / j;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Average: " << srznach << endl;
    return 0;
}
