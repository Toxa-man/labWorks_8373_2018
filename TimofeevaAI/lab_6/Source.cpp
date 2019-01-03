#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
using namespace std;
#define ArrowUp 72
#define ArrowDown 80
#define ArrowLeft 75
#define ArrowRight 77
const int cellHeight = 20;
const int cellWidth = 20;
const int Left = 70;
const int Top = 10;
const int width = 25, height = 15; 
const int MAX = 16; 

typedef struct Cell
{
	int row; 
	int col;
	int state; 
};

Cell field[height][width]; 

typedef struct Snake
{
	Cell body[MAX+1];
	int bodyLength; 
};

Snake Python;

void Init()
{
	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
		{
			field[row][col].row = row;
			field[row][col].col = col;
			field[row][col].state = 0;
		}
	for (int row = 0; row < height; row++)
	{
		field[row][0].state = -100;
		field[row][width - 1].state = -100;
	}
	for (int col =0 + 1; col < width - 1; col++)
	{
		field[0][col].state = -100;
		field[height - 1][col].state = -100;
	}
	srand(time(NULL));
	Python.body[0].col = rand() % (width - 2) + 1;
	Python.body[0].row = rand() % (height - 2) + 1;
	Python.body[0].state = 777;
	Python.bodyLength = 1;

	for (int k = 0; k < MAX; k++)
	{
		int x;
		int y;
		do
		{
			x = rand() % (width - 2) + 1;
			y = rand() % (height - 2) + 1;
		} while (field[y][x].state != 0);
		field[y][x].state = +1;
	}	
}

HPEN whitepen = CreatePen(PS_SOLID, 2, 0xFFFFFF); 
HBRUSH whitebrush = CreateSolidBrush(0xFFFFFF);
HPEN blackpen = CreatePen(PS_SOLID, 2, 0x808080); 
HBRUSH blackbrush = CreateSolidBrush(0x808080);
HPEN redpen = CreatePen(PS_SOLID, 2, 0x0000FF); 
HBRUSH redbrush = CreateSolidBrush(0x0000FF);
HPEN greenpen = CreatePen(PS_SOLID, 2, 0x00FF00); 
HBRUSH greenbrush = CreateSolidBrush(0x00FF00);
HWND hWnd = GetConsoleWindow(); 
HDC hDC;

void Paint(Cell cell)
{

	if (cell.state == 0)
	{
		SelectObject(hDC, whitepen);
		SelectObject(hDC, whitebrush);
	}

	if (cell.state < 0)
	{
		SelectObject(hDC, blackpen);
		SelectObject(hDC, blackbrush);
	}

	if (cell.state == 777) 
	{
		SelectObject(hDC, greenpen);
		SelectObject(hDC, greenbrush);
	}

	int left = cell.col * cellWidth + Left;
	int right = left + cellWidth;
	int top = cell.row * cellHeight + Top;
	int bottom = top + cellHeight;

	if (cell.state > 0 && cell.state != 777)
	{
		SelectObject(hDC, whitebrush);
		SelectObject(hDC, whitepen);
		Rectangle(hDC, left, top, right, bottom);
		SelectObject(hDC, redpen);
		SelectObject(hDC, redbrush);
		Ellipse(hDC, left, top, right, bottom);
	}
	else
		Rectangle(hDC, left, top, right, bottom);
}

void Insert(int X, int Y)
{
	Python.bodyLength++; 
	for (int k = Python.bodyLength - 1; k > 0; k--)
		Python.body[k] = Python.body[k - 1];
	Python.body[0].state = 777;
	Python.body[0].row = Y;
	Python.body[0].col = X;
}

bool At(int x, int y)
{
	return Python.body[0].col == x && Python.body[0].row == y;
}

int Move(char key)
{
	int result = Python.bodyLength;
	int newx = Python.body[0].col;
	int newy = Python.body[0].row;
	switch (key)
	{
	case ArrowUp:newy--;	break;
	case ArrowDown:newy++;	break;
	case ArrowLeft:newx--; break;
	case ArrowRight: newx++; break;
	default: return result; 
	}
	
	for (int k = 1; k < Python.bodyLength; k++)
		if (At(Python.body[k].col, Python.body[k].row))
			return -666; 

	
	int state = field[newy][newx].state;

	if (state == 0)
	{
		for (int k = Python.bodyLength - 1; k > 0; k--)
			Python.body[k] = Python.body[k - 1];
		Python.body[0].row = newy;
		Python.body[0].col = newx;
		return result;
	}

	if (state == 1) 
	{
		Insert(newx, newy);
		field[newy][newx].state = 0;
		return result + 1;
	}

	if (state < 0) 
	{
		return -666; 
	}

	if (Python.bodyLength >= MAX) 
	{
		return 777; 
	}

	return result;
}


int main()
{
	Init();
	cprintf("Start!\n");
	char c = 0;
	int TimeOut = 300;
	while (true)
	{
		cprintf("\r%d", Python.bodyLength);
		hDC = GetDC(hWnd); 
		for (int row = 0; row < height; row++)
			for (int col = 0; col < width; col++)
			{
				Paint(field[row][col]);
			}

		for (int k = 0; k < Python.bodyLength; k++)
			Paint(Python.body[k]);

		if (kbhit())
		{
			char newc = getch();
			if (newc == 27) return 0;
			c = newc; 
		}
		else
			Sleep(TimeOut);

		switch (Move(c))
		{
		case -666:
			cprintf("\n LOSE");
			getch();
			return 0;
		case MAX+1:
			cprintf("\n WIN!");
			getch();
			return 0;
		}
	}
}