#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	setlocale(0, "");
	float first, second, result;
	char sign;
	cout << "������� ������ ����� ";
	cin >> first;
	cout << "������� ������ ����� ";
	cin >> second;
	cout << "������� ���� ";
	cin >> sign;
	switch (sign)
	{
	case '+': cout << first << " " << sign << " " << second << " = " << first + second;
		break;
	case '-':cout << first << " " << sign << " " << second << " = " << first - second;
		break;
	case '*':cout << first << " " << sign << " " << second << " = " << first * second;
		break;
	case '/':
		if (second == 0)
		{
			while (second == 0)
			{
				cout << "�� ���� ������ ������, ������� ������ ����������� ";
				cin >> second;
			}
			cout << first << " " << sign << " " << second << " = " << first / second;
		}
		break;
	default: 
		cout << "������: �������� ���� ";
	}
	_getch();
    return 0;	
}