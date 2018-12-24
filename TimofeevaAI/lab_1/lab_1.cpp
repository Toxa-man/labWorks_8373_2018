#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int main()
{
	float FirstNum, SecondNum, result;
	bool IsThereError = false;
	char sign;
	cout << "Enter first number:";
	cin >> FirstNum;
	cout << "Enter sign:";
	cin >> sign;
	cout << "Enter second number:";
	cin >> SecondNum;

	switch (sign)
	{
	    case '+':
		   result = FirstNum + SecondNum;
		  break;
	    case '-':
		   result = FirstNum - SecondNum;
		  break;
	    case '*':
		   result = FirstNum * SecondNum;
		  break;
	    case '/':
		   if (SecondNum == 0)
		   {
			IsThereError = true;
			cout << "You can not divide by zero";
		   }
		   else
		   {
			result = FirstNum / SecondNum;
		   }
		   break;
	    default:
		 IsThereError = true;
	 	 cout << "Wrong sign" << endl;
	}
	if (IsThereError == false) 
    {
	  cout << "Result: " << result << endl;
    }
	_getch();
	system("pause");
	return 0;
}