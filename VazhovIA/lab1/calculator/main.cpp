#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float left, right;
    char sign;
    cin >> left >> sign >> right;

    switch (sign)
    {
    case '+':
        cout << left + right << endl;
        break;
    case '-':
        cout << left - right << endl;
        break;
    case '*':
        cout << left * right << endl;
        break;
    case '/':
        if (right == 0) {
            cout << "Division by zero is forbidden" << endl;
            return 8;
        }
        cout << left / right << endl;
        break;
    }
    return 0;
}
