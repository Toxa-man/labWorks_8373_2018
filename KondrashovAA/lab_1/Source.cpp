#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	setlocale(0, "");
	float left, right, result = 0;
	char sign;
	bool errorcheck = false;
	cout << "Ââåäèòå ëåâûé îïåðàíä: ";
	cin >> left;
	cout << "Ââåäèòå ïðàâûé îïåðàíä: ";
	cin >> right;
	cout << "Ââåäèòå çíàê: ";
	cin >> sign;
	do {
		errorcheck = false;
		switch (sign) {
		case '+': result = left + right;
			break;
		case '-': result = left - right;
			break;
		case '*': result = left * right;
			break;
		case '/': if (right == 0) {
			errorcheck = true;
			cout << "Äåëèòü íà íîëü íåëüçÿ" << endl
				<< "Ââåäèòå ïðàâûé îïåðàíä: ";
			cin >> right;
			} 
			else result = left / right;
			break;
		default: errorcheck = true;
			cout << "Ââåäåí íåïðàâèëüíûé çíàê" << endl
					<< "Ââåäèòå çíàê: ";
			cin >> sign;
		};
	} while (errorcheck);
	cout << "Ðåçóëüòàò: " << result << endl;
	_getch();
	return 0;
}
