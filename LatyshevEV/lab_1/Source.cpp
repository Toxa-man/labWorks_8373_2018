#include<iostream>
#include<string>
using namespace std;
int main()
{
	setlocale(0, "");
	float left;
	char sign;
	float right;
	bool flag = false;
	cout << "Ââåäèòå ëåâûé îïåðàíä" << endl;
	cin >> left;
	cout << "Ââåäèòå ïðàâûé îïåðàíä" << endl;
	cin >> right;
	cout << "Ââåäèòå çíàê" << endl;
	cin >> sign;
	float result;
	switch (sign)
	{
	case '+': result = left + right;
		break;
	case '-': result = left - right;
		break;
	case '*' : result = left * right;
		break;
	case '/' : 
		if (right != false)
		{ 
			result = left / right; 
		}
		else 
		{ 
			flag = true;
			cout << "Îøèáêà: äåëåíèå íà íîëü"<<endl; 
		}
		break;
	default:cout << "Îøèáêà: çíàê íå âàëèäåí"<< endl;
		flag = true;
		break;
	}
	if (flag == false)
	{
		cout << left << sign<< right << '=' << result;
	}
	cout << endl;
	system("pause");
	return 0;
}
