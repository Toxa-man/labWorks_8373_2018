#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct wordinfo {
	int value;
	int firstcoor;
	int lastcoor;
};

int main() {
	const int size = 100;
	int space = 0;
	char str[size];
	wordinfo word[size];
	cout << "Enter some words." << endl;
	gets_s(str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			space++;
		}
	}
	for (int i = 0; i < size; i++) {
		word[i].value = 0;
	}
	int j = 0;
	word[0].firstcoor = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			j++;
			word[j].firstcoor = i + 1;
		}
		else {
			word[j].value += (int)str[i];
			word[j].lastcoor = i;
		}
	}
	for (int i = 0; i < space; i++) {
		for (int j = 0; j < space - i; j++) {
			if (word[j].value > word[j + 1].value) {
				wordinfo temp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = temp;
			}
		}
	}
	cout << "Sorted words: " << endl;
	for (int i = 0; i < space+1; i++) {
		for (int j = word[i].firstcoor; j <= word[i].lastcoor; j++) {
			cout << str[j];
		}
		if (i != space) {
			cout << ' ';
		}
	}
	_getch();
	return 0;
}