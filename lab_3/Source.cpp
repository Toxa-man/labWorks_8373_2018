#include <iostream>
#include <windows.h>
using namespace std;

struct word_struct
{
	int first_symbol;
	int last_symbol;
	int sum_symbol;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int const size = 256;
	word_struct word[size];
	char input_string[size], sorted_string[size];
	int i, j, words_num, temp;

	cout << "¬ведите вашу строку, состо€щую из английских слов. —лова раздел€йте пробелами." << endl;
	cout << "¬веденна€ строка:" << endl;
	gets_s(input_string);

	for (int i = 0; i < strlen(input_string); i++)
	{
		if (input_string[i] == ' ')
		{
			if (input_string[i + 1] == ' ')
			{
				cout << "ќшибка: введено два пробела" << endl;
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
		word[i].sum_symbol = 0;
	}
	j = 0;
	for (i = 0; i < words_num; i++) {                      
		while (input_string[j] != '\0') {
			word[i].sum_symbol += int(input_string[j]);
			if (input_string[j + 1] == ' ') {
				j++;
				break;
			}
			j++;
		}
		j++;
	}

	word[0].first_symbol = 0;
	i = 0; j = 0;
	while (i < strlen(input_string)) {
		if (input_string[i] == ' ') {
			j++;
			word[j].first_symbol = i+1;
		}
		else {
			word[j].last_symbol = i;
		}
		i++;
	}

	i = 0; j = 0; temp = 0;
	while (i < words_num) {
		j = i;
		while (j < words_num) {
			if (word[i].sum_symbol > word[j].sum_symbol) {
				word_struct temp = word[j];
				word[j] = word[i];
				word[i] = temp;
			}
			j++;
		}
		i++;
	}

	cout << "ќтсортированна€ строка: " << endl;
	for (int i = 0; i < words_num; i++) {
		for (int j = word[i].first_symbol; j <= word[i].last_symbol; j++) {
			cout << input_string[j];
		}
		if (i != words_num) {
			cout << ' ';
		}
	}
	cout << endl;

	system("pause");
	return 0;
}