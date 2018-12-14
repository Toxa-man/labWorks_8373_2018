#include <iostream>

using namespace std;

int main()
{
    float left;
    float right;
    char sign;
    float result = 0;
    bool error = false;
    cout <<"Vvedite levyi operator ";
    cin >> left;
    cout <<"Vvedite znak ";
    cin >> sign;
    cout <<"Vvedite pravyi operator ";
    cin >> right;
    switch (sign) {
        case '+': result = left + right;
        break;
        case '-': result = left - right;
        break;
        case '*': result = left * right;
        break;
        case '/':
            if (right == 0) {
                cout <<"Nel'zya delit' na nol'";
                error = true;
            } else {
                result = left / right;
            } break;
            default: {
                cout <<"Vvedite pravil'nyi znak";
                error = true;
            }
            break;
    }
    if (!error) {
        cout << "Resul'tat = " << result;
    }
    return 0;
}
