#include <iostream>
#include <locale>

using namespace std;
int main()
{

	setlocale(LC_ALL, "Rus");

	double left, right;
	char sign;
	cout << "Введите число ";
	cin >> left;
	cout << "Выберите операцию ";
	cin >> sign;
	cout << "Введите число ";
	cin >> right;

	switch (sign)
	{
	case '+': cout << "result " << left + right; break;
	case '-': cout << "result " << left - right; break;
	case '/':

		if (right == 0) { return 2; }
		cout << "result" << left / right;
		break;

	case '*': cout << "result" << left * right; break;
	default:cout << "Error" << endl; system("pause"); return 1;
	}
	system("pause");
	return 0;


}

}
