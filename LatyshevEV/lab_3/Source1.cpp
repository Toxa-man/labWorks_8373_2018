#include <algorithm>
#include <iostream>
#include <string>
#include<conio.h>
using namespace std;


int word_len(char str[], int begin)
{
	int result = 0;
	while ((str[begin] != ' ') && (begin < strlen(str)))
	{
		begin++;
		result++;
	}
	return result;
}

int word_sum(char str[], int begin)
{
	int result = 0;
	while ((str[begin] != ' ') && (begin < strlen(str)))
	{
		result += (int)str[begin];
		begin++;
	}
	return result;
}


void find_some_data(char str[], int* sums_of_words, int* lengths_of_words, int* first_elements, int &amount)
{
	int counter = 0;
	int add = 0;
	while (counter < (strlen(str)))
	{
		sums_of_words[add] = word_sum(str, counter);
		lengths_of_words[add] = word_len(str, counter);
		first_elements[add] = counter;
		amount += 1;
		int a = word_len(str, counter);
		add++;
		counter += (a + 1);
	}
}

void add_new_word(char in[], char out[], int index, int &out_counter, int* first_elements, int* lengths_of_words)
{
	for (int i = first_elements[index]; i < first_elements[index] + lengths_of_words[index]; i++)
	{
		out[out_counter] = in[i];
		out_counter++;
	}
	out[out_counter] = ' ';
	out_counter++;
}


int main()
{
	setlocale(0, " ");
	int sums_of_words[50];
	int lengths_of_words[50];
	int first_elements[50];
	int amount = 0;
	int out_counter = 0;
	cout << "write any string: " << endl;
	char input_str[200];
	char output_str[200];
	cin.getline(input_str, 200);
	for (int i = 0; i < strlen(input_str); i++)
	{
		if (input_str[i] == ' ')
		{
			if (input_str[i + 1] == ' ')
			{
				cout << "Mistake: 2 spaces";
				_getch();
				return 0;
			}
		}
	}
	find_some_data(input_str, sums_of_words, lengths_of_words, first_elements, amount);
	int sorted_sums[50];
	for (int i = 0; i < amount; i++)
	{
		sorted_sums[i] = sums_of_words[i];
	}
	sort(sorted_sums, sorted_sums + amount);
	for (int i = 0; i < amount; i++)
	{
		for (int k = 0; k < amount; k++)
		{
			if (sorted_sums[i] == sums_of_words[k])
			{
				add_new_word(input_str, output_str, k, out_counter ,first_elements, lengths_of_words);
				sums_of_words[k] = -1;
			}
		}
	}
	cout << "sotred string: " << endl;
	for (int i = 0; i < out_counter; i++)
	{	
		cout << output_str[i];
	}
	_getch();
}