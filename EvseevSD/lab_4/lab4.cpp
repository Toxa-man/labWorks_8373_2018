#include<iostream>
#include<conio.h>
using namespace std;

double my_degree(double numberd, int degree) {
	double temp = numberd;
	if (degree > 0) {
		for (int i = 1; i < degree; i++) {
			numberd *= temp;
		}
	}
	else {
		if (degree < 0) {
			numberd = 1 / numberd;
			for (int i = 1; i < -degree; i++) {
				numberd /= temp;
			}
		}
		else {
			if (degree == 0) numberd = 1;
		}
	}
		return numberd;
}

int my_factorial(int numberf) {
	int temp = numberf;
	numberf = 1;
	for (int i = 1; i <= temp; i++) {
		numberf *= i;
	}
	return numberf;
}

double my_sqrt(double numbers){
	double temp = numbers;
	while ( (numbers - temp / numbers) > numeric_limits<double>::epsilon() ){
		numbers = (numbers + temp / numbers) / 2;
	}
	return numbers;
}

int prime(int numberp){
	for (int i = 2; i <= my_sqrt(numberp); i++) {
		if (numberp % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int degree;
	double number;
	char sign;
	do {
		cout << "Insert the number." << endl;
		cin >> number;
		if (number == (int)number) {
			cout << "Insert the opertion. If you want to found sqrt of nember, press \"s\". To found factorial of mumber, press \"!\"." << endl << "To build a number to a degree, press \"d\". To find out number is simple, press \"p\"." << endl;
			cin >> sign;
			switch (sign) {
				case '!': cout << my_factorial(number) << endl;
					break;
				case 'd': cout << "Insert the degree." << endl; cin >> degree; cout << my_degree(number, degree) << endl;
					break;
				case 'p':	if (prime(number) == true) {
								cout << "Number is simple." << endl;
							}
							else {
								cout << "Number is not simple." << endl;
							}
							break;
				case 's': cout << my_sqrt(number) << endl;
					break;
				default: cout << "Mistake. You entered wrong operation." << endl;
					break;
			}
		}
		else {
			cout << "Insert the opertion. If you want to found sqrt of nember, press \"s\"." << endl << "To build a number to a degree, press \"d\". To find out number is simple, press \"p\"." << endl;
			cin >> sign;
			switch (sign) {
				case 'd': cout << "Insert the degree." << endl; cin >> degree; cout << my_degree(number, degree) << endl;
					break;
				case 'p': cout << "Number is not simple." << endl;
					break;
				case 's': cout << my_sqrt(number) << endl;
					break;
				default: cout << "Mistake. You entered wrong operation." << endl;
					break;
			}
		}
		cout << "Press any key to continue or press Esc to close the program" << endl;
	} while (_getch() != 27);
	return 0;
}
