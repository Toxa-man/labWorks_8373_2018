#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(0, "");
	float left, right, result;
	cout << "������� ����� �������";
	cin >> left;
	cout << "������� ������ �������";
	cin >> right;
	char sign;
	cout << "������� ����";
	cin >> sign;
	switch (sign) {
	case'+':result = left + right;
		break;
	case'-':result = left - right;
		break;
	case'*':result = left * right;
		break;
	case'/':if (right = '0') {
		cout << "������� �� ���� ����������";
		_getch();
		break;
	}
			else {
		result = left / right;
		break;
	}
	default: cout << "������� ���������� ����";
	}
	cout << "���������: " << result;
	_getch();
}