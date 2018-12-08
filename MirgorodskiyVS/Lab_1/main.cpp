#include <bits/stdc++.h>

using namespace std;

int main()
{
    double  s = 0;
    char operand ;
    double a = 0;
    double b = 0;
    cin >> a >> b >> operand;
    switch(operand)
    {
        case '+':
            s = a + b; cout << endl << s; break;
        case '-':
            s = a - b; cout << endl << s; break;
        case '*':
            s = a * b; cout << endl << s; break;
        case '/':
           if (b != 0)
           {
               s = a / b; cout << endl << s; break;
           }
           else
                cout << "Null non devidable";
           break;
        default:
            cout << "You are wrong" << endl;
    }
    return 0;
}
