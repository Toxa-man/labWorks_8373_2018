#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float left, right, result;
    char sign;
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
        cout << "wrong sign" << endl;
        break;
    }
    cout << result << endl;
    return 0;
}
