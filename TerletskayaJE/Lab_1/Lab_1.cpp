#include <iostream> 
#include <conio.h> 
using namespace std;

int main()

{
	setlocale(0, "");
	float left, right, result;
	int erorr = 0;
	cout << "������� ����� ��������: ";
	cin >> left;
	cout << "������� ������ ��������: ";
	cin >> right;
	char sign;
	cout << "������� ���� ����� �����������: ";
	cin >> sign;
	switch (sign)
	{
	case '+': result = left + right;
		break;
	case '-': result = left - right;
		break;
	case '*': result = left * right;
		break;
	case '/':
		if (right == 0)
		{
			cout << "�� ���� ������ ������!";
			erorr = 1;
		}
		else
		{
			result = left / right;
			break;
		}
	default:
		cout << "������������ ����! ";
		erorr = 1;
		break;
	}
	if (erorr == 0)
	{
		cout << "���������: " << result;
		_getch();
	}
	else
	{
		cout << "������!";
		_getch();
	}
}