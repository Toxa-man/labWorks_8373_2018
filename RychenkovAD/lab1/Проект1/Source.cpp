#include <iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int main()
{
	float first, second, resault;
	bool flag = true;
	char sign;
	setlocale(0, "rus");
	cout << "Ââåñòè ïåðâîå ÷èñëî: ";
	cin >> first;
	cout << "Ââåñòè âòîðîå ÷èñëî: ";
	cin >> second;
	cout << "Ââåñòè îïåðàöèþ: ";
	cin >> sign;
	
	switch(sign){
		case '+': 
			resault = first + second; break;
		case '-':
			resault = first - second; break;
		case '*': 
			resault = first * second; break;
		case '/':
			if (second == 0) {
				flag = false;
				cout << "Îøèáêà ââîäà!" << endl; break;
			}
			else {
				resault = first / second; break;
			}
		default:{
		       flag = false;
		       cout << "Îøèáêà ââîäà!" << endl;
		}
	}
	if(flag){
               cout << first << " " << sign << " " << second << " " << "=" << " " << resault << endl;
	}

	//system("pause");
}
