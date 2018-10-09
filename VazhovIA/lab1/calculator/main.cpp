#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float left, right, result;
    char sign;
    cout << "Enter expression, e.g. 2+2" << endl;
    cin >> left >> sign >> right;

    switch (sign)
    {
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    case '*':
        result = left * right;
        break;
    case '/':
        if (right == 0) {
            cout << "Division by zero is forbidden" << endl;
            return 8;
        }
        result = left / right;
        break;
    default:
        cout << "Wrong sign" << endl;
        return 1;
        break;
    }
    cout << result << endl;
    return 0;
}
