#include<conio.h>
#include<iostream>

using namespace std;

int main() {
	setlocale(0, "");
	float first, second, result;
	char sign;
	cout << "������� 1 �����." << endl;
	cin >> first;
	cout << "������� ������ ��������." << endl;
	cin >> sign;
	cout << "������� 2 �����." << endl;
	cin >> second;
	//������������ ������� �������� ������� ����� ������� ������� �� "0"
	/*if (second == 0 && sign == '/') {
		cout << "������. �� �������� ��������� �� 0." << endl;
		_getch();
		return 0;
	}*/
	//�������������� ������� ����� ������� ������� �� "0"
	if (second == 0 && sign == '/') {
		while (second == 0) {
			cout << "������. �� �������� ��������� �� 0. ������� ������ �����������." << endl;
			cin >> second;
		}
		result = first / second;
		cout << "�����: " << result;
		_getch();
		return 0;
	}
	switch (sign) {
	case '+': result = first + second;
		break;
	case '-': result = first - second;
		break;
	case '*': result = first * second;
		break;
	case '/': result = first / second;
		break;
	default: cout << "������. �� ����� ������������ ������ ��������." << endl;
		_getch();
		return 0;
	}
	cout << "�����: " << result;
	_getch();
	return 0;
}