#include "stdafx.h" 
#include "iostream" 
#include "conio.h" 
using namespace std;

int main()
{
	float left, right, result;
	char sign;
	setlocale(0, "");
		cout << "������� ����� ��������" << "\n";
				cin >> left;
		cout << "������� ������ ��������" << "\n";
				cin >> right;
		cout << "������� ���� ���������" << "\n";
				cin >> sign;
		
				while (sign != '+' && sign != '-' && sign != '/' && sign != '*')
				{
					cout << "�� ����� �������� ����, ������� ������" << "\n";
					cin >> sign;
				}
					switch (sign)
					{
						case'+':
							result = left + right;
							break;
						case'-':
							result = left - right;
							break;
						case'*':
							result = left*right;
							break;
						case'/':
							if (right == 0)
							{
								cout << "�� ���� ������ ������, ������� ������ ��������" << "\n";
								cin >> right;
								result = left / right;
								break;
							}
							else
							{
								result = left / right;
								break;
							}
					}
				

		cout << left << sign << right << "=" << result;
		_getch();
	return 0;
}