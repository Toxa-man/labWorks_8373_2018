#include <iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int main()
{
	float first, second, resault;
	char sign;
	setlocale(0, "rus");
	cout << "¬вести первое число: ";
	cin >> first;
	cout << "¬вести второе число: ";
	cin >> second;
	cout << "¬вести операцию: ";
	cin >> sign;
	
	
	    switch (sign) {
		case '+': resault = first + second; break;
		case '-': resault = first - second; break;
		case '*': resault = first * second; break;
		case '/':
			if (second == 0) {
				cout << "ќшибка!" << endl;
			}
			else {
				resault = first / second; break;
			}
		default:
			cout << "ќшибка ввода!" << endl; 
	}
	
	cout << first << " " << sign << " " << second << " " << "=" << " " << resault <<endl;
	
	
}