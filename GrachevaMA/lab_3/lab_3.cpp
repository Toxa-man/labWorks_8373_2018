/*
 *Крч это самый тупой код, который я смог придумать
 *На чистом C без магии
 */
#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//это просто чтение текста, нам надо считать текст при этом учитывая пробелы
char* readText(size_t* len, size_t* space_count)//указатель куда вернется текст и его размер + кол-во пробелов (будем считать, что слова разделены одим пробелом)
{
	char* text = (char*)(calloc(1, 1));//сначала 1 символ, надо юзать calloc ибо надо нулями заполнить

	while (1)//да типо бесконечный цикл почти
	{
		char c = getchar();//берем символ из консоли
		if (c == '\n')//если это знак переноса строки то выходим из цикла
			break;

		if (c == ' ')
			++*space_count;

		if (len != 0)//если длина не нулевая, то перевыделяем память
		{
			//этими коммандами мы сохраняем старый текст

			//тут выделили буфер
			char* buf = (char*)(calloc(*len, 1));

			//тут скопировали старый текст
			memcpy(buf, text, *len);


			//выделили памяти на два сивола больше (в плюсах обязательно строка должна заканчиваться нул символом, тобишь нулем)
			text = (char*)(calloc(*len + 2, 1));

			//и опять скопировали уже из буфера наш текст в результирующий
			memcpy(text, buf, *len);


			//память чистим на всяк случай
			free(buf);

		}

		//записываем введенный символ в коец строки перед нулем
		text[*len] = c;

		//увеличиваем длину
		++*len;
	}

	return text;
}

//В чистом C нет ссылок, поэтому мы не лохи и будем юзать указатели (хотя можно делать говно через двойные, но не)
char** getWords(char* text, size_t length, size_t space_count)
{
	//Дальше выделяем память под наши слова (они разделены пробелами и их будет на 1 больше чем пробелов)
	char** text_matrix = (char**)calloc(space_count + 1, sizeof(char*));

	size_t space_point = 0;//Это счетчик символов, но в данном контексте он будет указывать на пробел
	size_t last_point = 0;//Сюда будем пихать индекс последнего пробела, чтобы отгораживать двумя пробелами слово
	size_t word_length;//Длина слова, которую мы будем сохранять
	size_t space_iter = 0;//Счетчик для кол-ва слов (чтобы обращаться к нужнему индексу)
	//Начинается МАГИЯ
	//Код делает следующее, он идет по готовому тексту
	for(size_t i = 0;;i++)
	{
		//Если символ не пробел и еще пробелы есть
		if(*(text + i) != ' ' && space_count != space_iter)
		{
			space_point++;//Увеличиаем итератор для поиска пробела (то бишь смотрим через сколько символов встретится пробел)
			continue;
		}
		
		//Когда встретили НЕ ПОСЛЕДНИЙ пробел
		if(space_iter != space_count)
		{
			//Получаем длину слова (надо вычесть из первого пробела, последний, который мы запомнили)
			word_length = space_point - last_point;

			//Выделяем под след слово память (формально это двумерный массив и при появлении нового слова мы увеличиваем еще один итератор)
			text_matrix[space_iter] = (char*)calloc(word_length + 1, sizeof(char));
			
			//Заполняем это слово с помощью копирования памяти (копируем с последнего пробела и копируем столько символов сколько длина слова)
			memcpy(text_matrix[space_iter], (text + last_point), word_length);
			space_point++;//Увеличиваем счетчик символов
			last_point = space_point;//Сохраняем позицию последнего пробела
			space_iter++;//Увеличиваем кол-во слов
		}
		else
			break;
	}

	//Тут выполняем тоже самое просто это последне слово и можно просто скопировать все до конца строки начиная с последнего пробела
	word_length = length - last_point;
	text_matrix[space_iter] = (char*)calloc(word_length + 1, sizeof(char));
	memcpy(text_matrix[space_iter], (text + last_point), word_length);

	return text_matrix;
}

//тут мы получаем вес слова (тупо надо пройтись по буквам и поплюсовать их коды
size_t getRank(char* word)
{
	size_t result = 0;//изначавльно это ноль
	while (*word != '\0')//считываем пока указатель не указывает на нул символ
	{
		result += *word;//результат плюсуем со значением указателя (буквы)
		++word;//смещаемся на след букву
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
	//ну тут понятно, выедляем память и получаем построчно ранги
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