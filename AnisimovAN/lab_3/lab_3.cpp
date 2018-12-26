#include "pch.h"
#include <iostream>

using namespace std;

const int mas_size = 255;

int main()
{
	char words[mas_size][mas_size];
	char str[mas_size];

	int word_sum[mas_size];
	int word_index = 0;
	int	letter_index = 0;
	int	sum = 0;                    

	cout << "Write a string which you want to check: " << endl;
	cin.getline(str, sizeof(str)); 

	for (int i = 0; i<sizeof(str); ++i)
	{      
		if ((str[i] == ' ') || (str[i] == '\0'))  //"\0"-symbol of end of the word
		{
			words[word_index][letter_index] = '\0';   
			word_sum[word_index] = sum;

			sum = 0;              
			letter_index = 0;      

			++word_index;                   

			if (str[i] == '\0') 
			{   
				break;              
			}
		}
		else 
		{                    
			sum += (int)str[i];    
			words[word_index][letter_index] = str[i]; 

			++letter_index;                   
		}
	}

	for (int i = 0; i < word_index; ++i)
	{ 
		int min = i;                      
		int j = i + 1;            

		for (j; j < word_index; ++j) 
		{
			if (word_sum[min] > word_sum[j])   
			{
				min = j;              
			}
		}
		swap(words[min], words[i]);   
		swap(word_sum[min], word_sum[i]); 
	}

	cout << "Result: " << endl;
	for (int i = 0; i < word_index; ++i)
	{ 
		cout << words[i] << " ";    
	}

	return 0;                      
}
