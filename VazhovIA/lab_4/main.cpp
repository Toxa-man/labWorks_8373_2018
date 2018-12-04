#include <iostream>
using namespace std;


int pow(int num, int deg)
{
	if (deg == 1)
		return num;
	if (deg == 2) {
	        return num*num;
	} else
	{
	        return num*pow(num,deg-1);
	}
}

unsigned int long fact(unsigned num)
{
    if (num == 1) {
        return 1;
    } else
    {
        return num*fact(num-1);
    }
}
double sqrt(int input)
{
	double t;
	double result = input / 2;
	do {
		t = result;
		result = (t + (input / t)) / 2;
	} while ((t - result) != 0);

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
    int input,degree;
    cout << "Enter number" << endl;
    cin >> input;
    cout << "Enter degree" << endl;
    cin >> degree;
	cout << "Warning!\nFactorial's maximum is 65\nResults:\nPow: " << pow(input,degree) << endl;
    if (input < 0) {
        cout << "\nfactorial, sqrt and simplicity are unavailable" << endl;
    }
	else
	{
		cout << "sqrt: " << sqrt(input) << "\nsimple? " << simple(input);
		if (input <= 65)
			cout << "\nfact: " << fact(input);
		cout << endl;
	}

    return 0;
}
