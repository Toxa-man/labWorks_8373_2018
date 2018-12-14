#include <string>
#include <iostream>
using namespace std;

int main() {
	setlocale(0, "");
	int count = 0, sum = 0, temp = 0, time_count = 0;
	char str1[200];
	string arr[200], str2;
	cout << "Введите строку: ";
	cin.getline(str1, 200);
	for (int i = 0; i < strlen(str1); i++) {
		if (str1[i] == ' ') {
			count++;
			arr[time_count] = str2;
			time_count++;
			str2 = "";
		}
		else if (i == strlen(str1) - 1) {
			str2 += str1[i];
			count++;
			arr[time_count] = str2;
		}
		else {
			str2 += str1[i];
		}
	}
	const int size = 200;
	int arrdig[size];
	for (int i = 0; i < count; i++) {
		for (int z = 0; z < arr[i].size(); z++) {
			sum += int(arr[i][z]);
		}
		arrdig[i] = sum;
		sum = 0;
	}
	for (int i = 0; i < count; i++) {
		for (int z = 0; z < count - 1; z++) {
			if (arrdig[z] > arrdig[z + 1]) {
				temp = arrdig[z];
				arrdig[z] = arrdig[z + 1];
				arrdig[z + 1] = temp;
				str2 = arr[z];
				arr[z] = arr[z + 1];
				arr[z + 1] = str2;
			}
		}
	}
	cout << "Отсортированная строка: ";
	for (int i = 0; i < count; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}