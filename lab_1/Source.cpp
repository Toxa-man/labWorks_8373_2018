#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	float left, right, result;
	char sign;

	cout << "������� ����� �������: ";
	cin >> left;
	cout << "������� ������ �������: ";
	cin >> right;
	cout << "������� ���� ��������: ";
	cin >> sign;

	switch (sign) {
	case'+': result = left + right;
		break;
	case'-': result = left - right;
		break;
	case'*': result = left * right;
		break;
	case'/': if (right == 0) {
			     cout << "������: �� ���� ������ ������!" << endl;
				 system("pause");
				 return 0;
			 }
			 result = left / right;
		break;
	default:
		cout << "������: ������� ������������ ������." << endl;
		system("pause");
		return 0;
		break;
	}
    
	cout << "���������: " << result << endl;
	
	system("pause");
	return 0;
}