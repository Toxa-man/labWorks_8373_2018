#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(0, "");
	float first, second, result;
	char sign;
	cout << "������� ������ �����";
	cin >> first;
	cout << "������� ������ �����";
	cin >> second;
	cout << "������� ����";
	cin >> sign;

	switch (sign)
	{
	case '+': result = first + second;
		break;
	case '-': result = first - second;
		break;
	case '*': result = first*second;
		break;
	case '/': result = first / second;

		if (second == 0)
		{
			cout << "������: �� ���� ������ ������";
			_getch();
			return 0;
		}
		break;
	default: cout << "������: ����������� ����";
		_getch();
		return 0;
	}
	cout << first << " " << sign << " " << second << " = " << result;
	_getch();
	return 0;
}
