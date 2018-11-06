#include "stdafx.h" 
#include "iostream" 
#include "conio.h" 
using namespace std;

int main()
{
	float left, right, result;
	char sign;
	setlocale(0, "");
		cout << "Ââåäèòå ëåâûé àðãóìåíò" << "\n";
				cin >> left;
		cout << "Ââåäèòå ïðàâûé àðãóìåíò" << "\n";
				cin >> right;
		cout << "Ââåäèòå çíàê âûðàæåíèÿ" << "\n";
				cin >> sign;
		
				while (sign != '+' && sign != '-' && sign != '/' && sign != '*')
				{
					cout << "Âû ââåëè íåâåðíûé çíàê, ââåäèòå âåðíûé" << "\n";
					cin >> sign;
				}
					switch (sign)
					{
						case'+':
							result = left + right;
							break;
						case'-':
							result = left - right;
							break;
						case'*':
							result = left*right;
							break;
						case'/':
							if (right == 0)
							{
								cout << "Íà íîëü äåëèòü íåëüçÿ, ââåäèòå äðóãîé äåëèòåëü" << "\n";
								cin >> right;
								result = left / right;
								return;
							}
							else
							{
								result = left / right;
								break;
							}
					}
				

		cout << left << sign << right << "=" << result;
		_getch();
	return 0;
}
