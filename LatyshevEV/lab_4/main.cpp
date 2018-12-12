#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdlib>
#include<math.h>
#include<limits>
#include<conio.h>
using namespace std;

float exponentation(int number, int power)
{
    float result = 1;
    if (power == 0)
    {
        return 1;
    }
    else if (power > 0)
    {
        for (int i = 0; i < power; i++)
        {
            result *= number;
        }
    }
    else if (power < 0)
    {
        for (int i = 0; i < -power; i++)
        {
            result /= number;
        }
    }
    return result;
}

long long factorial(int a)
{
    if (a == 0)
    {
        return 1;
    }
    else
    {
        return (a * factorial(a - 1));
    }
}

float square_root(float n)
{
    float x = 1;
    float next_x = ((x + n / x) / 2);
    while (fabs(next_x - x) > (numeric_limits <float>::epsilon()))
    {
        x = next_x;
        next_x = ((x + n / x) / 2);
    }
    return next_x;
}

bool IsPrimeNumber(int n)
{
    if (n == 1)
    {
        return false;
    }
    else if (n == 2)
    {
        return true;
    }
    else if (n % 2 == 0)
    {
        return false;
    }

    for (int i = 3; i <= (int)square_root(n); i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main() {
    setlocale(0, "");
    cout << "2 in power of 3:   " << exponentation(2, 3) << endl;
    cout << "2 in power of -3   " << exponentation(2, -3) << endl;
    cout << "3 factorial:  " << factorial(3) << endl;
    cout << "9 factorial:   " << factorial(9) << endl;
    cout << "Square root of 2:   " << square_root(2) << endl;
    cout << "Square root of 256:  " << square_root(256) << endl;
    if (IsPrimeNumber(1046527))
    {
        cout << "1046527 - is prime" << endl;
    }
    else
    {
        cout << "1046527 - is not prime" << endl;
    }
    if (IsPrimeNumber(49))
    {
        cout << "49 - is prime" << endl;
    }
    else
    {
        cout << "49 - is not prime" << endl;
    }
    if (IsPrimeNumber(1))
    {
        cout << "1 - is prime" << endl;
    }
    else
    {
        cout << "1 - is not prime" << endl;
    }
    if (IsPrimeNumber(3))
    {
        cout << "3 - is prime" << endl;
    }
    else
    {
        cout << "3 - is not prime" << endl;
    }
	_getch();
    return 0;
}
