#include <iostream>
#include <ctime>

#define X			'x'
#define O			'o'
#define SPACE		' '

#define PC_WIN			0x5
#define PLAYER_WIN		0x4
#define ROUND_DRAW		0x3
#define NOTHING			0x0

typedef char board_t[3][3];


typedef struct cell {
	char col;
	char row;
	bool win;
}cell_t;

typedef struct cell_row {
	cell_t* data;
	char count;
}cell_row_t;

enum CheckType_t
{
	FIRST_ROW,
	SECOND_ROW,
	THIRD_ROW,

	FIRST_COL,
	SECOND_COL,
	THIRD_COL,

	MAIN_DIAGONAL,
	SECOND_DIAGONAL,
};

int randomRange(int min, int max);

void display();
void initBoard();

char smthWin();
bool checkWin(char c, CheckType_t type);

bool hasFreeCells();

void getPlayerMove();
void getPcMove();


cell_row_t getCellsByType(char type);

cell_t checkProtect();
cell_t getAttack();

using namespace  std;

board_t board;


//row - строка
//col (column) - колонка

int randomRange(int min, int max)
{
	if (min > max || max == min)
		return max;

	return min + (rand() % static_cast<int>(max - min + 1));
}

void initBoard()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = SPACE;
}

void display()
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << board[i][j] << "|";

		cout << endl;
	}
}

bool checkWin(char c, CheckType_t type)
{
	switch (type)
	{
	case FIRST_ROW:
		if (board[0][0] == c && board[0][1] == c && board[0][2] == c)
			return true;
		return false;

	case SECOND_ROW:
		if (board[1][0] == c && board[1][1] == c && board[1][2] == c)
			return true;
		return false;

	case THIRD_ROW:
		if (board[2][0] == c && board[2][1] == c && board[2][2] == c)
			return true;
		return false;

	case FIRST_COL:
		if (board[0][0] == c && board[1][0] == c && board[2][0] == c)
			return true;
		return false;

	case SECOND_COL:
		if (board[0][1] == c && board[1][1] == c && board[2][1] == c)
			return true;
		return false;

	case THIRD_COL:
		if (board[0][2] == c && board[1][2] == c && board[2][2] == c)
			return true;
		return false;

	case MAIN_DIAGONAL:
		if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
			return true;
		return false;

	case SECOND_DIAGONAL:
		if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
			return true;
		return false;
	default:
		return false;
	}
}

char smthWin()
{
	if (
		checkWin(X, FIRST_ROW) ||
		checkWin(X, SECOND_ROW) ||
		checkWin(X, THIRD_ROW) ||
		checkWin(X, FIRST_COL) ||
		checkWin(X, SECOND_COL) ||
		checkWin(X, THIRD_COL) ||
		checkWin(X, MAIN_DIAGONAL) ||
		checkWin(X, SECOND_DIAGONAL)
		)
		return PLAYER_WIN;

	if (
		checkWin(O, FIRST_ROW) ||
		checkWin(O, SECOND_ROW) ||
		checkWin(O, THIRD_ROW) ||
		checkWin(O, FIRST_COL) ||
		checkWin(O, SECOND_COL) ||
		checkWin(O, THIRD_COL) ||
		checkWin(O, MAIN_DIAGONAL) ||
		checkWin(O, SECOND_DIAGONAL)
		)
		return PC_WIN;

	return NOTHING;
}

void getPlayerMove()//add check
{
	int x;
	int y;

	do
	{
		cout << "STROKA: "; cin >> x;
		cout << "STOLBEC: "; cin >> y;
	} while (board[x][y] != SPACE);

	board[x][y] = X;
}


void getPcMove()
{
	cell_t protection = checkProtect();//получили защитную позицию
	cell_t attack = getAttack();//получили атакующа

	//проверка на выигрышный ход или защитный ход
	if (attack.win)
		board[attack.row][attack.col] = O;
	else if (protection.col != -1)
		board[protection.row][protection.col] = O;
	else
		board[attack.row][attack.col] = O;

}

//получаем клетки по определенном типу (все пробелы все крестики или все нолики)
cell_row_t getCellsByType(char type)
{
	int count = 0;
	cell_row_t result;
	result.data = new cell_t[9];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == type)
			{
				result.data[count].row = i;
				result.data[count].col = j;
				count++;
			}
		}
	result.count = count;
	return result;
}

//чтобы выиграть след ходом или поставить на рандом
cell_t getAttack()
{
	cell_row_t free = getCellsByType(SPACE);
	cell_t result = free.data[randomRange(0, free.count - 1)];
	result.win = false;
	for (int i = 0; i < free.count; i++)
	{
		board[free.data[i].row][free.data[i].col] = O;//simulation
		if (smthWin() != NOTHING)
		{
			result.row = free.data[i].row;
			result.col = free.data[i].col;
			result.win = true;
			board[free.data[i].row][free.data[i].col] = SPACE;
			break;
		}
		board[free.data[i].row][free.data[i].col] = SPACE;
	}
	return result;
}

//чтобы противник не выйграл след ходом
cell_t checkProtect()
{
	cell_t result = { -1, -1 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] == SPACE)
			{
				board[i][j] = X; //simulation
				if (smthWin() != NOTHING)
				{
					result.row = i;
					result.col = j;
					board[i][j] = SPACE;
					break;
				}
				board[i][j] = SPACE;

			}

	return result;
}

bool hasFreeCells()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] == SPACE)
				return true;

	return false;
}

using namespace std;



int main()
{
	srand(time(0));
	initBoard();

	char winType = NOTHING;

	while (winType == NOTHING)
	{
		//отрисовка доски
		display();

		//получаем ход игрока
		getPlayerMove();

		//получаем ход пк
		getPcMove();

		//смотрим кто победил
		winType = smthWin();

		//если нет свободных клеток то просто выходим из цикла)
		if (!hasFreeCells())
			break;
	}

	display();

	switch(winType)
	{
		case PC_WIN:
		cout << "PC WIN!";
		break;

		case PLAYER_WIN:
			cout << "YOU WIN!";
			break;
		case ROUND_DRAW:
			cout << "ROUND DRAW!";
			break;

		default:break;
	}
	system("pause>nul");
}