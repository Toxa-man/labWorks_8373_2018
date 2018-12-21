#include "stdafx.h"
#include <iostream>
#include <conio.h>
const int size = 100;
void MySummation(int First_matrix_column_size, int First_matrix_line_size, int* matrix1, int Second_matrix_column_size, int Second_matrix_line_size, int* matrix2, int& Output_matrix_column_size, int& Output_matrix_line_size, int* Output)
{
	if (First_matrix_column_size == Second_matrix_column_size && First_matrix_line_size == Second_matrix_line_size)
	{
		Output_matrix_column_size = First_matrix_column_size;
		Output_matrix_line_size = First_matrix_line_size;
		for (int i = 0; i < Output_matrix_line_size; i++)
		{
			for (int j = 0; j < Output_matrix_column_size; j++)
			{
				*(Output + (i * size) + j) = *(matrix1 + (i * size) + j) + *(matrix2 + (i * size) + j);
			}
		}
	}
}
void MySubtraction(int First_matrix_column_size, int First_matrix_line_size, int* matrix1, int Second_matrix_column_size, int Second_matrix_line_size, int* matrix2, int& Output_matrix_column_size, int& Output_matrix_line_size, int* Output)
{
	if (First_matrix_column_size == Second_matrix_column_size && First_matrix_line_size == Second_matrix_line_size)
	{
		Output_matrix_column_size = First_matrix_column_size;
		Output_matrix_line_size = First_matrix_line_size;
		for (int i = 0; i < Output_matrix_line_size; i++)
		{
			for (int j = 0; j < Output_matrix_column_size; j++)
			{
				*(Output + (i * size) + j) = *(matrix1 + (i * size) + j) - *(matrix2 + (i * size) + j);
			}
		}
	}
}
void MyMultiplication(int First_matrix_column_size, int First_matrix_line_size, int* matrix1, int Second_matrix_column_size, int Second_matrix_line_size, int* matrix2, int& Output_matrix_column_size, int& Output_matrix_line_size, int* Output)
{
	if (First_matrix_column_size == Second_matrix_line_size)
	{
		Output_matrix_column_size = Second_matrix_column_size;
		Output_matrix_line_size = First_matrix_line_size;
		for (int i = 0; i < Output_matrix_line_size; i++)
		{
			for (int j = 0; j < Output_matrix_column_size; j++)
			{
				*(Output + (i * size) + j) = 0;
				for (int k = 0; k < First_matrix_column_size; k++)
				{
					*(Output + (i * size) + j) += *(matrix1 + (i * size) + k) * *(matrix2 + (k * size) + j);

				}
			}
		}
	}
}
int main()
{
	int matrix1[size][size];
	int matrix2[size][size];
	int output[size][size];
	int First_matrix_column_size, Second_matrix_column_size, Output_matrix_column_size;
	int First_matrix_line_size, Second_matrix_line_size, Output_matrix_line_size;
	int key;
	bool Posibility_to_calculate = false;
	do
	{
		std::cout << "Insert column size and line size for your first matrix\n";
		std::cin >> First_matrix_column_size >> First_matrix_line_size;
		std::cout << "Insert your values into first matrix\n";
		for (int i = 0; i < First_matrix_line_size; ++i)
		{
			for (int j = 0; j < First_matrix_column_size; ++j)
			{
				std::cin >> matrix1[i][j];
			}
		}
		std::cout << "Insert column size and line size for your second matrix\n";
		std::cin >> Second_matrix_column_size >> Second_matrix_line_size;
		std::cout << "Insert your values into second matrix\n";
		for (int i = 0; i < Second_matrix_line_size; ++i)
		{
			for (int j = 0; j < Second_matrix_column_size; ++j)
			{
				std::cin >> matrix2[i][j];
			}
		}
		do
		{
			std::cout << "Select your action (Only three is available: '1' for summation, '2' for substraction, '3' for multiplication;\n";
			key = _getch();
			switch (key)
			{
			case 49:
				if (First_matrix_column_size == Second_matrix_column_size && First_matrix_line_size == Second_matrix_line_size)
				{
					Posibility_to_calculate = true;
				}
				MySummation(First_matrix_column_size, First_matrix_line_size, *matrix1, Second_matrix_column_size, Second_matrix_line_size, *matrix2, Output_matrix_column_size, Output_matrix_line_size, *output);
				break;
			case 50:
				if (First_matrix_column_size == Second_matrix_column_size && First_matrix_line_size == Second_matrix_line_size)
				{
					Posibility_to_calculate = true;
				}
				MySubtraction(First_matrix_column_size, First_matrix_line_size, *matrix1, Second_matrix_column_size, Second_matrix_line_size, *matrix2, Output_matrix_column_size, Output_matrix_line_size, *output);
				break;
			case 51:
				if (First_matrix_column_size == Second_matrix_line_size)
				{
					Posibility_to_calculate = true;
				}
				MyMultiplication(First_matrix_column_size, First_matrix_line_size, *matrix1, Second_matrix_column_size, Second_matrix_line_size, *matrix2, Output_matrix_column_size, Output_matrix_line_size, *output);
				break;
			default:
				std::cout << "Wrong action\n";
			}
			if (Posibility_to_calculate)
			{
				std::cout << "Result is\n";
				for (int i = 0; i < Output_matrix_line_size; ++i)
				{
					for (int j = 0; j < Output_matrix_column_size; ++j)
					{
						std::cout << output[i][j] << ' ';
						if (j == Output_matrix_column_size - 1)
						{
							std::cout << '\n';
						}
					}
				}
				Posibility_to_calculate = false;
			}
			else
			{
				std::cout << "Imposible to calculate!\n";
			}
			std::cout << "Do you want to choice another action? (press ESC for no/press any other button for yes)\n";
			key = _getch();
			if (key != 27)
			{
				std::cout << "Your first matrix\n";
				for (int i = 0; i < First_matrix_line_size; ++i)
				{
					for (int j = 0; j < First_matrix_column_size; ++j)
					{
						std::cout << matrix1[i][j] << ' ';
						if (j == First_matrix_column_size - 1)
						{
							std::cout << '\n';
						}
					}
				}
				std::cout << "Your second matrix\n";
				for (int i = 0; i < Second_matrix_line_size; ++i)
				{
					for (int j = 0; j < Second_matrix_column_size; ++j)
					{
						std::cout << matrix2[i][j] << ' ';
						if (j == Second_matrix_column_size - 1)
						{
							std::cout << '\n';
						}
					}
				}
			}
		} while (key != 27);
		std::cout << "Do you want to calculate another matrices? (press ESC for no(exit from programm)/press any other button for yes)";
		key = _getch();
		std::cout << '\n';
	} while (key != 27);
	return 0;
}
