 #include <iostream>
#include <conio.h>

using namespace std;

const int size_str = 100;

void word_sort(char* str, int* sums, int* words_pos, int size_sum) {
	
	char temp_str1[size_str], temp_str2[size_str], word_str[size_str];
	while (size_sum > 1) {
		int min = sums[0], imin = 0, temp_sum = 0, temp_wpos = 0, word_length = 0;
		for (int i = 1; i < size_sum; i++) {
			if (sums[i] < min) {
				min = sums[i];
				imin = i;
			}
		}
		if (imin != size_sum - 1) {
			word_length = words_pos[imin + 1] - words_pos[imin] - 1;
		}
		else {
			word_length = words_pos[imin + 1] - words_pos[imin];
		}

		strncpy_s(word_str, str + words_pos[imin], word_length);
		strncpy_s(temp_str1, str, words_pos[imin]);
		strcpy_s(temp_str2, str + words_pos[imin + 1]);
		strcat_s(temp_str1, temp_str2);
		strcat_s(word_str, " ");
		strcat_s(word_str, temp_str1);
		strcpy_s(str, size_str, word_str);


		for (int i = size_sum; i > imin; i--) {
			words_pos[i] -= word_length + 1;
		}
		for (int i = imin; i > 0; i--) {
			sums[i] = sums[i - 1];
			words_pos[i] = words_pos[i - 1];
		}

		sums[0] = min;

		str += word_length + 1;
		sums += 1;
		words_pos += 1;
		size_sum--;
	}
	while (str[strlen(str) - 1] == ' ') {
		str[strlen(str) - 1] = '\0';
	}
}


int main() {
	char str[size_str];
	int sum = 0;
	int sums[size_str];
	int words_pos[size_str] = { 0 };
	int size_sum = 0;

	cout << "Enter the string: " << endl;
	gets_s(str);

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			sums[size_sum] = sum;
			sum = 0;
			words_pos[size_sum + 1] = i + 1;
			size_sum++;
		}
		else {
			sum += str[i];
		}
	}
	sums[size_sum] = sum;
	words_pos[size_sum + 1] = strlen(str);
	size_sum++;

	word_sort(str, sums, words_pos, size_sum);

	cout << endl << "Words sorted in ascending order: " << endl << str;

	_getch();
}