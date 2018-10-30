#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int main()
	{
		setlocale(0,"");
		float FirstNum, SecondNum, result;
		bool IsThereError=false;
		char digit;
		cout<<"Введите первое число:";
		cin>>FirstNum;
		cout<<"Введите знак:";
		cin>>digit;
		cout<<"Введите второе число:";
		cin>>SecondNum;
		switch(digit){
			case '+':
				result=FirstNum+SecondNum;
				break;
			case '-':
				result=FirstNum-SecondNum;
				break;
			case '*':
				result=FirstNum*SecondNum;
				break;
			case '/':
				if (SecondNum==0){
					IsThereError=true;
					cout<<"Нельзя делить на ноль...";
				}else {
					result=FirstNum/SecondNum;}
				break;
			default:
				IsThereError=true;
				cout<<"Это неверный знак..."<<endl;
		} 
		if (IsThereError==false) {
			cout<<"Результат: "<<result<<endl;}
		_getch();
	/*	system("pause");
		return 0; */
}
