#include <iostream> 
using namespace std;
int main()
{
	float left;
	float right;
	float result;
	cout << "First number:";
	cin >> left;
	cout << "Second number:";
	cin >> right;
	char sign;
	cout << "Sign:";
	cin >> sign;
	int error = 0;
	if (right == 0) {
		if (sign == '/') {
			cout << "cannot be divided by 0 " << endl;
			error = 1;
		}
	}
	switch (sign)
	{
	case'+':result = left + right;
		break;
	case'-':result = left - right;
		break;
	case'*':result = left * right;
		break;
	case'/':result = left / right;
		break;

	default:   error = 1;

		cout << "Other sign" << endl;
		break;
	}
	if (error == 1) {}

	else

	{
	  cout << "Result:" << result << endl;
	}

	getch();
}
