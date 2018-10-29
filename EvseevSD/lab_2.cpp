#include<iostream>
#include<cstdlib>
#include<conio.h>

using namespace std;

int main() {
	const int masq1 = 8;
	long int mas1[masq1], mas2[masq1], change , sum = 0;
	int size2 = 0;
	cout << "array with random elements :" << endl;
	for (int i = 0; i < masq1; i++) {
		mas1[i] = 0 + rand() % 2147483647;
		cout << mas1[i] << ' ';
		if (mas1[i] % 2 != 0) {
			size2++;
		}
	}
	int i = 0;
	while(i != masq1){
		int j = 0;
		while( j != masq1-1){
			if (mas1[j] > mas1[j + 1]) {
				change = mas1[j];
				mas1[j] = mas1[j + 1];
				mas1[j + 1] = change;
			}
			j++;
		}
		i++;
	}
	cout << endl << "sorted array with random elements :" << endl;
	for (int i = 0; i < masq1; i++) {
		cout << mas1[i] << ' ';
	}
	i = 0;
	while (i != size2) {
		for (int j = 0; j < masq1; j++) {
			if (mas1[j] % 2 != 0) {
				mas2[i] = mas1[j];
				sum += mas2[i];
				i++;	
			}
		}
	}
	const int s = size2-1;
	long float average = sum / size2;
	cout << endl << "Minimum of array with odd elements:" << ' ' << mas2[0] << endl<< "Maximum of array with odd elements:" << ' ' << mas2[s] << endl << "Average value of elements array with odd elements" << ' ' << average;
	_getch();
	return 0;
}