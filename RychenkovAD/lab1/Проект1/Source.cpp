#include <iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int main()
{
	float first, second, resault;
	char sign;
	setlocale(0, "rus");
	cout << "������ ������ �����: ";
	cin >> first;
	cout << "������ ������ �����: ";
	cin >> second;
	cout << "������ ��������: ";
	cin >> sign;
	
	
	    switch (sign) {
		case '+': resault = first + second; break;
		case '-': resault = first - second; break;
		case '*': resault = first * second; break;
		case '/':
			if (second == 0) {
				cout << "������!" << endl;
			}
			else {
				resault = first / second; break;
			}
		default:
			cout << "������ �����!" << endl; 
	}
	
	cout << first << " " << sign << " " << second << " " << "=" << " " << resault <<endl;
	
	
}