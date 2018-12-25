#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

int main() {
	const int size = 100;
	int size_of_str;
	int wordlen, word = 0, n = 0, p1 = 0,p2 = 0;
	char str[size];
	char sorted_str[size][size];
	int sumofcodes[size];
	
	cout << "Enter string: ";
	cin.getline(str, size);
	size_of_str = strlen(str);
	
	while (n < size_of_str) {
		wordlen = 0;
		sumofcodes[word] = 0;
		while ((str[n] >= 97 && str[n] <= 122)||(str[n] >= 65 && str[n] <= 90)) {
			sorted_str[word][wordlen] = str[n];
			sumofcodes[word] += (int)(str[n]);
			wordlen++;
			n++;
		}
		sorted_str[word][wordlen] = '\0';
		word++;
		n++;
	}

	int i = 1, j = 0;
	while (i < word) {
		j = i;
		while (sumofcodes[j] < sumofcodes[j - 1]) {
			p1 = sumofcodes[j];
			sumofcodes[j] = sumofcodes[j - 1];
			sumofcodes[j - 1] = p1;

			for (int w = 0; w < size; w++) {
				 p2 = sorted_str[j][w];
				sorted_str[j][w] = sorted_str[j - 1][w];
				sorted_str[j - 1][w] = p2;
			}
			j--;
		}
		i++;
	}

	cout << "Result: ";
	for (int x = 0; x < word; x++) 
		cout << sorted_str[x] << " ";
	
	cout << endl;
	system("pause");
	return 0;
}