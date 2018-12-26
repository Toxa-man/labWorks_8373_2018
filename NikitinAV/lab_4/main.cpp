
#include <iostream>
#include <conio.h>
using namespace std;
//======= 1 
double chislo_step(int stepen, double chislo) {
	double result = 1;
		for (int i = 0; i < stepen; i++) {
			result = result * chislo;
		}
	
	if (stepen < 0) {
		for (int i = 0; i > stepen; i--) {
			result = result / chislo;
		}
	}
	return result;
}
//======= 2 
int factorial(int chislo) {
	double result = 1;
	for (int i = 1; i <= chislo; i++) {
		result = result * i;
	}
if (chislo<0){
	return 0;
	}
	return result;
}
//======= 3 
double sq_root(double chislo) {
	double result=0;
	for (int i = 0; i <100; i++) {
		result = 1+(chislo-1)/(result+1);
	}
	if (chislo == 0) {
		return 0;
	}
	return result;
}
//======= 4 
bool prosto(int chislo) {
	for (int i = 2; i <chislo; i++) {
		if (chislo % i == 0) {
			return false;
		}
	}
	if (chislo <= 1) {
		return false;
	}
	return true;
}
int main() {
	char znak;
	cout << "type ur sign:" << endl << "1) ^ for exponentiation" << endl << "2) ! for factorial" << endl << "3) k for square root" << endl << "4) p to check ur number for simplicity" << endl;
	cin >> znak;
		while (!(znak == '^' || znak == '!' || znak == 'k' || znak == 'p')) {
			cout << "wrong sign, try it again\n";
			cin >> znak;
		}
	int stepen;
	double chislo;
	double result;
	switch (znak) {
	case '^':
		//====== 1
		cout << "type ur number" << endl;
		cin >> chislo;
		cout << "type power" << endl;
		cin >> stepen;
		cout << chislo_step(stepen, chislo);
		break;
	case '!':
		//====== 2
		cout << "type ur number" << endl;
		cin >> chislo;
		while (chislo < 0) {
			cout << "type positive number" << endl;
			cin >> chislo;
		}
		cout << factorial(chislo);
		break;

	case 'k':
		//====== 3
		cout << "type ur number" << endl;
		cin >> chislo;
		while (chislo < 0) {
			cout << "type positive number\n";
			cin >> chislo;
		}
		cout << sq_root(chislo);
		break;
	case'p':
		//====== 4
		cout << "type ur number" << endl;
		cin >> chislo;
		if (prosto(chislo)) {
			cout << "ur number is prime";
		}
		else {
			cout << "ur number isnt prime";
		}
		break;
	}
	_getch();
	return 0;
}

