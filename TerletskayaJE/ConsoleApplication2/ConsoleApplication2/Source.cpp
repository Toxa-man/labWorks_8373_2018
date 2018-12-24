#include <iostream> 
#include <conio.h> 
using namespace std;

int main()

{
	setlocale(0, "");
	float left, right, result;
	int erorr = 0;
	cout << "Ââåäèòå ëåâûé îïïåðàíò: ";
	cin >> left;
	cout << "Ââåäèòå ïðàâûé îïïåðàíò: ";
	cin >> right;
	char sign;
	cout << "Ââåäèòå çíàê ìåæäó îïïåðàíòàìè: ";
	cin >> sign;
	switch (sign)
	{
	case '+': result = left + right;
		break;
	case '-': result = left - right;
		break;
	case '*': result = left * right;
		break;
	case '/':
		if (right == 0)
		{
			cout << "Íà íîëü äåëèòü íåëüçÿ!";
			erorr = 1;
		}
		else
		{
			result = left / right;
			break;
		}
	default:
		cout << "Íåïðàâèëüíûé çíàê! ";
		erorr = 1;
		break;
	}
	if (erorr == 0)
	{
		cout << "Ðåçóëüòàò: " << result;
		_getch();
	}
	else
	{
		cout << "Îøèáêà!";
		_getch();
	}
}
