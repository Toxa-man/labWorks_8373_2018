#include <iostream> 
#include <conio.h> 
using namespace std;
int main()
{
	float left, right, result;
	char sign;
	cout << "Insert first argument" << endl;
	cin >> left;
	cout << "Insert sign" << endl;
	cin >> sign;
	cout << "Insert second argument" << endl;
	cin >> right;


	switch (sign)
	{
	case '+':  cout << "Answer" << left << sign << right << " = " << left + right;
		break;

	case '-':  cout << "Answer" << left << sign << right << " = " << left - right;
		break;

	case '*':  cout << "Answer" << left << sign << right << " = " << left * right;
		break;

	case '/': if (right != 0) {
		cout << "Answer" << left << sign << right << " = " << left / right;
		break;
	}
			  else {
		cout << "Waring: it's not available to divide by 0";
		break;
	}

	default: cout << "Waring: wrong sign";
		break;
	}
	cout << endl;
	_getch();
	return 0;
}
