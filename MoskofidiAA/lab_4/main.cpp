#include <iostream>

using namespace std;

float deg (float n, int degree) {
    int k = n;
    n = 1;
    for (int i = 0; i < degree; i++) {
        n *= k;
    }
    return n;
}

int fact (int n) {
    int k = 1;
    for (int i = 2; i <= n; i++) {
        k *= i;
    }
    return k;
}

double sqrt(double num)
{
    double m;
    double result = num / 2;
    do
    {
        m = result;
        result = (m + (num / m)) / 2;

    }
    while ((m - result) != 0);
    return result;
}

int simple (int n) {
    int i(0), k(0);
    for ( i = 2; i < n; i++) {
        if ( n % i == 0) {
            k++;
        }
    }
    if (k == 0) {
        cout << "Number " << n << " is simple" << endl;
    }
    else {
        cout << "Number " << n << " isn't simple" << endl;
    }
    return 0;
}

int main() {
    int n(0), degr(0);
    int l(0);
    cout << "Select action:\n";
    cout << "1. Degree\n";
    cout << "2. Factorial\n";
    cout << "3. SQRT\n";
    cout << "4. Simple\n" << endl;
    cin >> l;
    cout << endl;
    while ((l == 1) || (l == 2) || (l == 3) || (l == 4)) {
        switch (l) {
            case 1:
                cout << "Enter number and degree:\n";
                cin >> n;
                cin >> degr;
                cout << endl;
                cout << "Result: " << deg (n, degr) << endl;
            break;
            case 2:
                cout << "Enter number: ";
                cin >> n;
                cout << endl;
                cout << "Result: " << fact (n) << endl;
            break;
            case 3:
                cout << "Enter number: ";
                cin >> n;
                cout << endl;
                cout << "Result: " << sqrt (n) << endl;
            break;
            case 4:
                cout << "Enter number: ";
                cin >> n;
                cout << endl;
                simple (n);
            break;
            default:
                if (l == 0) {
                    exit(1);
                }
            break;
        }
        cout << "If you want to continue - enter number of action, else enter 0\n" << endl;
        cin >> l;
    }
return 0;
}
