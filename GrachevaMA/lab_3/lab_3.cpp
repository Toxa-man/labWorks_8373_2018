
#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* readText(size_t* len, size_t* space_count)
	char* text = (char*)(calloc(1, 1));
	while (1)
	{
		char c = getchar();
		if (c == '\n')
			break;

		if (c == ' ')
			++*space_count;

		if (len != 0)
		{
			// сохраняем старый текст

			char* buf = (char*)(calloc(*len, 1));

			
			memcpy(buf, text, *len);

			text = (char*)(calloc(*len + 2, 1));
			memcpy(text, buf, *len);

			free(buf);

		}

		
		text[*len] = c;

		
		++*len;
	}

	return text;
}

char** getWords(char* text, size_t length, size_t space_count)
{
	char** text_matrix = (char**)calloc(space_count + 1, sizeof(char*));

	size_t space_point = 0;
	size_t last_point = 0;
	size_t word_length;
	size_t space_iter = 0;
	
	for(size_t i = 0;;i++)
	{
	
		if(*(text + i) != ' ' && space_count != space_iter)
		{
			space_point++;
			continue;
		}
		
		//Когда встретили НЕ ПОСЛЕДНИЙ пробел
		if(space_iter != space_count)
		{
			//Получаем длину слова 
			word_length = space_point - last_point;

			//Выделяем под след слово память  
			text_matrix[space_iter] = (char*)calloc(word_length + 1, sizeof(char));
			
			//Заполняем это слово с помощью копирования памяти 
			memcpy(text_matrix[space_iter], (text + last_point), word_length);
			space_point++;
			last_point = space_point;
			space_iter++;
		}
		else
			break;
	}


	word_length = length - last_point;
	text_matrix[space_iter] = (char*)calloc(word_length + 1, sizeof(char));
	memcpy(text_matrix[space_iter], (text + last_point), word_length);

	return text_matrix;
}

//тут мы получаем вес слова
size_t getRank(char* word)
{
	size_t result = 0;
	while (*word != '\0')
	{
		result += *word;
		++word;
	}

	return  result;//возвращаем вес слова
}

//Так же сортировка
void sort(size_t* arr, const unsigned int size, char*** words)
{
	int temp;
	char* c_temp;
	for (unsigned int i = 0; i < size; i++)
	{
		for (unsigned int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

				c_temp = (*words)[i];
				(*words)[i] = (*words)[j];
				(*words)[j] = c_temp;
			}
		}
	}
}

size_t* getRanks(char** words, const size_t count)//функция получения всех весов слов
{
	// выедляем память и получаем построчно ранги
	size_t* ranks = (size_t*)calloc(count, sizeof(size_t));
	for (size_t i = 0; i < count; i++)
		ranks[i] = getRank(words[i]);

	return  ranks;
}

int main()
{

	size_t len = 0;
	size_t space_count = 0;
	char* text = readText(&len, &space_count);

	char** words = getWords(text, len, space_count);
	size_t* ranks = getRanks(words, space_count + 1);
	sort(ranks, space_count + 1, &words);
	for (size_t i = 0; i < space_count + 1; i++)
		printf("%s ", words[i]);
}
