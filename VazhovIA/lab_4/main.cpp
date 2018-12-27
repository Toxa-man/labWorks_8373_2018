#include <iostream>
using namespace std;


double pow(double num, int deg)
{
    if (deg < 0) {
        if (deg == -1)
            return 1/num;
        if (deg == -2) {
            return 1/num*pow(num,deg+1);
        } else
        {
            return 1/num*pow(num,deg+1);
        }
    } else {
        if (deg == 0)
            return 1.0;
        if (deg == 1)
            return num;
        if (deg == 2) {
            return num*num;
        } else
        {
            return num*pow(num,deg-1);
        }
    }
}
unsigned int long fact(double num)
{
    if (num <= 1.0)
    {
        return 1;
    } else
    {
        return num*fact(num-1);
    }
}
double sqrt(double input)
{
    double t;
    double result = input / 2.0;
    do {
        t = result;
        result = (t + (input / t)) / 2.0;
    } while ((t - result) != 0.0);

    return result;
}
bool simple(int input)
{
    for (int i(2);i<input;i++) {
        if (input % i == 0)
            return false;
    }
    return true;
}
int main()
{
    double input;
    int degree;
    cout << "Enter number" << endl;
    cin >> input;
    cout << "Enter degree" << endl;
    cin >> degree;
    cout << "Warning! Factorial's maximum is 65\n\nResults:\nPow: " << pow(input,degree) << endl;
    if (input < 0) {
        cout << "\nfactorial, square root and simplicity check are unavailable" << endl;
    }
    else
    {
        cout << "Square root: " << sqrt(input) << "\nsimple? " << simple(input);
        if (input <= 65)
            cout << "\nfact: " << fact(input);
        cout << endl;
    }

    return 0;
}
