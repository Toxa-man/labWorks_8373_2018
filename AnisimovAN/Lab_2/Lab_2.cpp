#include <iostream> 
#include <conio.h> 
using namespace std;
int main()
{
	float left, right, result, check=0;
	char sign;
	cout << "Insert first argument" << endl;
	cin >> left;
	cout << "Insert sign" << endl;
	cin >> sign;
	cout << "Insert second argument" << endl;
	cin >> right;


	switch (sign)
	{
	case '+':result = left + right; 
		break;

	case '-':result = left - right; 
		break;

	case '*':result = left * right;
		break;

	case '/': if (right != 0) {
		result = left / right;
		break;
	}
			  else {
		cout << "Waring: it's not available to divide by 0";
		break;
	}

	default: cout << "Waring: wrong sign";
		check++;
		break;
	}
	if ((sign != '/') && (right != 0) && (check==0)) {
		cout << result;
		cout << endl;
	}
	_getch();
	return 0;
}
