#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(0,"");
    float left, right;
    char znak;
    cin >>left>>znak>>right;
    switch (znak)
    {
    case '+':
        cout <<left+right;
        break;
    case '-':
        cout <<left-right;
        break;
    case '*':
        cout <<left*right;
        break;
    case '/':
        if (right == 0)
            cout << "Ошибка! На ноль делить нельзя";
        else
        cout <<left/right;
        break;
    default:
        cout <<"Ошибка! Проверьте правильность введенных данных";
    }


    return 0;
}
