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
	if (!(sign == '+' || sign == '-' || sign == '*' || sign == '/'))
	{
		while (!(sign == '+' || sign == '-' || sign == '*' || sign == '/'))
		{
			cout << "������ �������� ����, ������� ���������� ���� ";
			cin >> sign;
		}
		switch (sign)
		{
		case '+': result = first + second;
			break;
		case '-': result = first - second;
			break;
		case '*': result = first * second;
			break;
		case '/':
			if (second == 0)
			{
				while (second == 0)
				{
					cout << "�� ���� ������ ������, ������� ������ ����������� ";
					cin >> second;
				}
				result = first / second;
			}
			break;
		}
	}
	cout << first << " " << sign << " " << second << " = " << result;
	_getch();
    return 0;	
}