#include <iostream>
#include <stdio.h>

using namespace std;
float main()
{
		float left, right;
		cout << "Enter left value" << "\n";
		while (!(cin >> left))
		{
			cin.clear();
			while (cin.get() != '\n') continue;
			cout << "Enter correct number " << "\n";
		}
		 cout << "Enter right value" << "\n";
		 while (!(cin >> right))
		 {
			 cin.clear();
			 while (cin.get() != '\n') continue;
			 cout << "Enter correct number " << "\n";
		 }
	char sign; // char занимает один байт
	cout << "Enter sign" << "\n";
	cin >> sign;
    float result;
	switch (sign) {
	case'+':result = left + right;
		cout << "Result:" << result << "\n";
		system("pause");
		break;
	case'-':result = left - right;
		cout << "Result:" << result << "\n";
		system("pause");
		break;
	case'*':result = left * right;
		cout << "Result:" << result << "\n";
		system("pause");
		break;
	case'/':
		if (right == 0)
		{
			cout << "WTF?" << "\n";
			system("pause");
			break;		
		}
		else
		{
			result = left / right;
			cout << "Result:" << result << "\n";
			system("pause");
			break;
		}
		system("pause");
	default:
		cout << "Wrong sign" << "\n";
	}	
}
