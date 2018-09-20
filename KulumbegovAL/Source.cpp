#include <iostream>
#include <stdio.h>

using namespace std;
float main()
{
		float left, right;
		cout << "Enter left value" << "\n";
		 cin >> left;
		 cout << "Enter right value" << "\n";
		 cin >> right;
	char sign; // char занимает один байт
	cout << "Enter sign" << "\n";
	cin >> sign;
    float result;
	switch (sign) {
	case'+':result = left + right;
		break;
	case'-':result = left - right;
		break;
	case'*':result = left * right;
		break;
	case'/':
		if (right == 0)
		{
			cout << "WTF?" << "\n";
			system("pause");
			//_getch();
			break;	
			
		}
		else
		{
			result = left / right;
			break;
		}
		system("pause");
		
	default:
		cout << "Wrong sign" << "\n";
	}
	if (sign == '+') {
		result = left + right;
		cout << "result:" << left + right << "\n";
		system("pause");
		//_getch();
	}
}