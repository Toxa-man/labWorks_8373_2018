#include "pch.h"
#include <iostream>
#include <string.h>
using namespace std;



int main() {
	int i = 0;
	int j = 0;
	int len = 0;
	char str[50] = {0};
	cout << "Enter the string: ";
	cin.getline(str, 50);
	while (str[i] != 0) {
		len++; i++;
	}
	//cout << "Lenght of string: " << len << endl;
	int k = 0;
	char str2[50];
	

	//cout << endl;
	for (int i = 0; i < len; i++) {
		if (str[i] == 32) {
			k = k + 1;
		}
	}
	str[len + 1] = 32;
	k+=1; //kolichestvo slov
	int Sum_of_word[10] = {0};
	char matrix[10][10] = {0};
	
	for (int i = 0; i < k;i++) {
		int j = 0;
		while (str[j] != 32) {
			matrix[i][j] = str[j];
			Sum_of_word[i] += (int)str[j];
			//cout << Sum_of_word[i]<<" ";
			j++;
		}
		for (int t = 0; t < len; t++) {
			if (t < len - j+1) {
				str[t] = str[t + j+1];
			}
			else {
				str[t] = 0;
			}
		}
		//cout << endl;
		len = len - j;
		j = 0;
	}
	//cout << endl;
	/*for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			cout << matrix[i][j]<<"   ";
		}
		cout << endl << endl;
	}*/
	int arr[10] = { 0 };
	for (int i = 0; i < k; i++) {
		arr[i] = Sum_of_word[i];
		//cout << Sum_of_word[i]<<" ";
	}
	i = 1;
	//cout << endl << "Sorted array: ";
	while (i < k) {
		j = i;
		while (Sum_of_word[j] < Sum_of_word[j - 1]) {
			int p = Sum_of_word[j];
			Sum_of_word[j] = Sum_of_word[j - 1];
			Sum_of_word[j - 1] = p;
			j--;
		}
		i++;
	}
	for (int i = 0; i < k; i++) {
		//cout << Sum_of_word[i] << " ";
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (arr[i] == Sum_of_word[j]) {
				int w = 0;
				while (matrix[j][w] != 0) {
					cout << matrix[j][w];
					w++;
				}
			}
		}
		cout << " ";
	}



	
	/*for (int i = 0; i < len; i++) {
			cout << str2[i];
	}*/
	return 0;
}