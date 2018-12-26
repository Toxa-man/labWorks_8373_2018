#include <iostream> 
#include <windows.h> 
#include <conio.h>
using namespace std;

struct word_struct
{
	int fst_S;
	int last_s;
	int sum;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int const size = 256;
	word_struct word[size];
	char input_string[size], sorted_string[size];
	int i, j, words_num, temp;

	cout << "Введите строку, состоящую из английских слов, разделенных пробелами" << endl;
	cout << "Введенная строка:" << endl;
	gets_s(input_string);

	for (i = 0; i < strlen(input_string); i++)
	{
		if (input_string[i] == ' ')
		{
			if (input_string[i + 1] == ' ')
			{
				cout << "Ошибка: введено два пробела" << endl;
				system("pause");
				return 0;
			}
		}
	}

	i = 0;
	words_num = 1;
	while (input_string[i] != '\0')
	{
		if (input_string[i] == ' ' && input_string[i + 1] != '\0')
		{
			words_num++;
		}
		i++;
	}

	for (i = 0; i < words_num; i++) {
		word[i].sum = 0;
	}
	j = 0;
	for (i = 0; i < words_num; i++) {
		while (input_string[j] != '\0') {
			word[i].sum += int(input_string[j]); // Для считывания ASCI
			if (input_string[j + 1] == ' ') {
				j++;
				break;
			}
			j++;
		}
		j++;
	}

	word[0].fst_S = 0;
	i = 0; j = 0;
	while (i < strlen(input_string)) {
		if (input_string[i] == ' ') {
			j++;
			word[j].fst_S = i + 1;
		}
		else {
			word[j].last_s = i;
		}
		i++;
	}

	i = 0; j = 0; temp = 0;
	while (i < words_num) {
		j = i;
		while (j < words_num) {
			if (word[i].sum > word[j].sum) {
				word_struct temp = word[j];
				word[j] = word[i];
				word[i] = temp;
			}
			j++;
		}
		i++;
	}

	cout << "Отсортированная строка: " << endl;
	for (int i = 0; i < words_num; i++) {
		for (int j = word[i].fst_S; j <= word[i].last_s; j++) {
			cout << input_string[j];
		}
		if (i != words_num) {
			cout << ' ';
		}
	}
	cout << endl;

	_getch();
	return 0;
}