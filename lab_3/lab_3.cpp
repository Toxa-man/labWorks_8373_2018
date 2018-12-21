#include <iostream>
using namespace std;

int main() {
	setlocale(0, "");
	int count = 0, sum = 0, temp = 0, counter = 0;
	char str1[100], temp1[1] = {};
	char words[100][100];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			words[i][j] = '\0';
		}
	}
	int k = 0, j = 0;
	int sums[100];
	cout << "Введите строку: ";
	cin.getline(str1, 100);
	for (int i = 0; i < 100; i++) {
		if (str1[i] == ' ') {
			words[j][k] = '\0';
			k = 0;
			j++;
			continue;
		}
		if (str1[i] == '\0') {
			words[j][k] = '\0';
			k = 0;
			j++;
			break;
		}
		words[j][k] = str1[i];
		k++;
	}
	cout << endl;
	for (int i = 0; i < j; i++) {
		counter++;
		for (int i2 = 0; i2 < 100; i2++) {
			if (words[i][i2] == '\0') {
				cout << " -" << sum;
				sums[i] = sum;
				sum = 0;
				break;
			}
			cout << words[i][i2];
			sum = sum + (int)words[i][i2];
		}
		cout << endl;
	}
	for (int i = 0; i < counter-1; i++) {
		for (int z = i; z < counter-1; z++) {
			if (sums[z] > sums[z + 1] && sums[z] != 0 && sums[z + 1] != 0) {
				temp = sums[z];
				sums[z] = sums[z + 1];
				sums[z + 1] = temp;
				for (int j = 0; j < 10; j++) {
					temp1[0] = words[z][j];
					words[z][j] = words[z + 1][j];
					words[z + 1][j] = temp1[0];
				}
			}
		}
	}
	cout << endl;
	cout << "Отсортированная строка: ";
	for (int i = 0; i < j; i++) {
		for (int j = 0; j < 10; j++) {
			if (words[i][j] != '\0') {
				cout << words[i][j];
			}
			}
		cout << " ";
	}
	cout << endl;
	return 0;
}
