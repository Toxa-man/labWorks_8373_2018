#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int choose, chislo, stepen;
	float function, result;

	cout << "�������� ��������." << endl;
	cout << "1 - ���������� ����� � �������." << endl;
	cout << "2 - ��������� �����." << endl;
	cout << "3 - ���������� ������ �� �����." << endl;
	cout << "4 - �������� ����� �� ��������" << endl << "��� �����: ";
	cin >> choose;
	cout << "������� �����: ";
	cin >> chislo;

	switch (choose) {
	case 1:
		cout << "������� �������: ";
		cin >> stepen;
		result = 1;
		if (stepen == 0) {
			result = 1;
		} else {
			for (int i = 0; i < stepen; i++) {
				result = result * chislo;
			}
		}
		cout << "�����: " << result << endl;
			break;

	case 2:
		result = 1;
		for (int i = 0; i < chislo; i++) {
			result = result * (chislo - i);
		}
		cout << "�����: " << result << endl;
			break;

	case 3:
		result = chislo;
		function = chislo;
		if (chislo < 0) {
			cout << "������: ������������ ���� �����." << endl;
		}
		else {
			while (1)
			{
				function = (chislo / function + function) / 2;
				if (result > function) {
					result = function;
				}
				else {
					cout << "�����: " << result << endl;
					system("pause");
					return 0;
				}
		    }
		}
			break;

	case 4:
		if ((chislo % 2 != 0) && (chislo % 3 != 0) && (chislo % 5 != 0)) {
			cout << "�����: ��� ����� �������." << endl;
		}
		else {
			cout << "�����: ��� ����� ���������." << endl;
		}
			break;

	default:
		cout << "������: ������������ ����� ��������." << endl;
		system("pause");
		return 0;
			break;
	}

	system("pause");
	return 0;
}