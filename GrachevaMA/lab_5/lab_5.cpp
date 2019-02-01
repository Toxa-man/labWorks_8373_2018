#include <iostream>
#include  <cstdlib>

#include  <conio.h>

using namespace  std;
typedef struct { int** raw; unsigned cols; unsigned rows; } matrix_t;


//Инициализация матриы 
int** initMatrix(unsigned& cols, unsigned& rows)
{
	cols = rows = 0;

	cout << "Cols->";
	cin >> cols;

	cout << "Rows->";
	cin >> rows;

	//Выделение памяти под N строк
	int** result = new int*[rows];
	
	for (unsigned i = 0; i < rows; i++)
		result[i] = new int[cols];

	//Заполняем матрицу
	for (unsigned i = 0; i < rows; i++)
		for (unsigned j = 0; j < cols; j++)
			cin >> result[i][j];
		
	return result;
}

enum Types : unsigned
{
	MULT = 1,
	SUM,
	SUB,
};

//Очистка матрицы
void clr(int** &matrix, unsigned rows)
{
	if (matrix == nullptr)
		return;
	for (unsigned i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
	matrix = nullptr;
}

//Умножение матриц 
int** muilt(const matrix_t a, const matrix_t b)
{
	
	if (a.cols != b.rows)
		return nullptr;

	
	int** result = new int*[a.rows];
	for (unsigned i = 0; i < a.rows; i++)
		result[i] = new int[b.cols];

	
	
	for (unsigned i = 0; i < a.rows; i++)
		for (unsigned j = 0; j < b.cols; j++)
		{
			result[i][j] = 0;
			for (unsigned k = 0; k < a.cols; k++)
				result[i][j] += a.raw[i][k] * b.raw[k][j];
		}

	return result;
}

//Сложенение матриц 
int** sum(matrix_t a, matrix_t b)
{
	if (a.cols != b.cols || a.rows != b.rows)
		return nullptr;
	
	int** result = new int*[a.rows];
	for (unsigned i = 0; i < a.rows; i++)
		result[i] = new int[a.cols];

	for (unsigned i = 0; i < a.rows; i++)
		for (unsigned j = 0; j < a.cols; j++)
			result[i][j] = (a.raw[i][j] + b.raw[i][j]);

	return  result;
}


//Вычитание матриц
int** sub(matrix_t a, matrix_t b)
{
	if (a.cols != b.cols || a.rows != b.rows)
		return nullptr;

	int** result = new int*[a.rows];
	for (unsigned i = 0; i < a.rows; i++)
		result[i] = new int[a.cols];
	
	for (unsigned i = 0; i < a.rows; i++)
		for (unsigned j = 0; j < a.cols; j++)
			result[i][j] = (a.raw[i][j] - b.raw[i][j]);

	return  result;
}

//Функция которая красиво обработает умножение матриц
void multab(int** m1, unsigned c1, unsigned r1, int** m2, unsigned c2, unsigned r2)
{
	int** mult = muilt({ m1, c1, r1 }, { m2, c2, r2 });

	if (mult == nullptr)
	{
		cout << "check matrix dimensions!" << endl;
		return;
	}

	for (unsigned i = 0; i < r1; i++)
	{
		for (unsigned j = 0; j < c2; j++)
			cout << mult[i][j] << " ";

		cout << endl;
	}

	clr(mult, r1);
}

//Функция которая красиво обработает сложение матриц
void sumab(int** m1, unsigned c1, unsigned r1, int** m2, unsigned c2, unsigned r2)
{
	int** mult = sum({ m1, c1, r1 }, { m2, c2, r2 });

	if (mult == nullptr)
	{
		cout << "check matrix dimensions!" << endl;
		return;
	}

	for (unsigned i = 0; i < r1; i++)
	{
		for (unsigned j = 0; j < c1; j++)
			cout << mult[i][j] << " ";

		cout << endl;
	}

	clr(mult, r1);
}

//Функция которая красиво обработает вычитание матриц
void subab(int** m1, unsigned c1, unsigned r1, int** m2, unsigned c2, unsigned r2)
{
	int** mult = sub({ m1, c1, r1 }, { m2, c2, r2 });

	if (mult == nullptr)
	{
		cout << "check matrix dimensions!" << endl;
		return;
	}

	for (unsigned i = 0; i < r1; i++)
	{
		for (unsigned j = 0; j < c1; j++)
			cout << mult[i][j] << " ";

		cout << endl;
	}

	clr(mult, r1);
}


int main()
{

	while (1)
	{
		unsigned c1 = 0;
		unsigned r1 = 0;

		unsigned c2 = 0;
		unsigned r2 = 0;
		unsigned type = 0;

		int** m1 = initMatrix(c1, r1);

		if (m1 == nullptr)
		{
			cout << "lul, ty again" << endl;
			system("pause");
			exit(~0);
		}


		int** m2 = initMatrix(c2, r2);

		if (m2 == nullptr)
		{
			cout << "lul, ty again" << endl;
			system("pause");
			exit(~0);
		}

		cout << "atcion" << endl;
		cout << "1 - multiplication" << endl;
		cout << "2 - summation" << endl;
		cout << "3 - subtraction" << endl;
		cout << "->";
		cin >> type;
		switch (type)
		{
		case SUB:
			subab(m1, c1, r1, m2, c2, r2);
			break;
		case SUM:
			sumab(m1, c1, r1, m2, c2, r2);
			break;
		case MULT:
			multab(m1, c1, r1, m2, c2, r2);
			break;
		default:
			cout << "invalid type!" << endl;
			break;
		}
		clr(m1, r1);
		clr(m2, r2);
		cout << "press <esc> to exit" << endl;
		if (_getch() == 27)//Пока не нажали пробел вводим матрицы заполняем и производим с ними разные действия
			break;

		system("cls");
	}
}
