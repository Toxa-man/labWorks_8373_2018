#include <iostream>

#define MINDIFF 2.25e-308 

using namespace std;

double my_sqrt(double x)
{
	double root = x / 3;
	double last;
	double diff;

	if (x <= 0) return 0;
	do 
	{
		last = root;
		root = (root + x / root) / 2;
		diff = root - last;
	} while (diff > MINDIFF || diff < -MINDIFF);
	return root;
}

double my_pow(double x, unsigned power)
{
	if (power == 0)
		return 1;

	const double buff = x;

	for (unsigned i = 1; i < power; i++)
		x *= buff;

	return x;
}

unsigned my_factorial(unsigned x)
{
	if (x == 0)
		return 0;

	unsigned result = 1;
	for (unsigned i = 1; i <= x; i++)
		result *= i;

	return result;
}


bool is_prime(unsigned n) 
{
	for (unsigned i = 2; i <= static_cast<unsigned>(my_sqrt(n)); i++)
		if (n % i == 0)
			return false;

	return true;
}

void sqrt_test()
{
	system("cls");

	double sqrt_var = 0;

	cout << "sqrt test" << endl;
	cout << "x->";
	cin >> sqrt_var;

	if (sqrt_var < 0)
		cout << "invalid value!" << endl;
	else
		cout << "sqrt = " << my_sqrt(sqrt_var) << endl;

	system("pause");
}

void pow_test()
{
	system("cls");

	double x = 0;
	int power = 0;

	cout << "power test" << endl;
	cout << "x and power->";
	cin >> x >> power;

	if (power < 0)
		cout << "invalid power!" << endl;
	else
		cout << "pow(" << x << ", " << power << ") = " << my_pow(x, power) << endl;

	system("pause");
}

void fac_test()
{
	system("cls");

	unsigned x = 0;

	cout << "factorial test" << endl;
	cout << "x->";
	cin >> x;

	cout << "factorial <" << x << "> = " << my_factorial(x) << endl;

	system("pause");
}

void prime_test()
{
	system("cls");

	unsigned x = 0;

	cout << "prime test" << endl;
	cout << "x->";
	cin >> x;

	cout << "is " << (is_prime(x) ? "" : " not ") << "prime" << endl;

	system("pause");
}
int main()
{
	sqrt_test();
	pow_test();
	fac_test();
	prime_test();
}