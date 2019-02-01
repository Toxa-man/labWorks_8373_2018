
void Subtract(int* Firstmatrix, int* SecondMtrx, int* AnswerMtrx)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			*(AnswerMtrx + i * SIZE + j) = *(Firstmatrix + i * SIZE + j) - *(SecondMtrx + i * SIZE + j);
		}
	}
}

void Sum(int* FirstMtrx, int* SecondMtrx, int* AnswerMtrx)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			*(AnswerMtrx + i * SIZE + j) = *(FirstMtrx + i * SIZE + j) + *(SecondMtrx + i * SIZE + j);
		}
	}
}
void Show(int* matrix, int row, int column)
{
	cout << endl << "Result matrix is: " << endl << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << *(matrix + i * SIZE + j) << " ";
		}
		cout << endl;
	}
}
void Multiplication(int* Firstmatrix, int* SecondMtrx, int* AnswerMtrx, int column)
{

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			*(AnswerMtrx + i * SIZE + j) = 0;
			for (int p = 0; p < column; p++)
			{
				*(AnswerMtrx + i * SIZE + j) += (*(Firstmatrix + i * SIZE + p) * *(SecondMtrx + p * SIZE + j));
			}
		}
	}
}


int main()
{
	char exit;
	do
	{
		system("cls");
		int row1, column1, row2, column2, Firstmatrix[SIZE][SIZE], SecondMtrx[SIZE][SIZE], AnswerMtrx[SIZE][SIZE];

		cout << "Enter the number of rows and columns of first matrix: " << endl
			<< "Rows: ";
		cin >> row1;
		cout << "Columns: ";
		cin >> column1;
		cout << endl;

		cout << "Write a matrix number 1: " << endl << endl;
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < column1; j++)
			{
				cin >> Firstmatrix[i][j];
			}
		}
		cout << endl;

		cout << "Enter the number of rows and columns of second matrix: " << endl
			<< "Rows: ";
		cin >> row2;
		cout << "Columns: ";
		cin >> column2;
		cout << endl;

		cout << "Write a matrix number 2: " << endl << endl;
		for (int i = 0; i < row2; i++)
		{
			for (int j = 0; j < column2; j++)
			{
				cin >> SecondMtrx[i][j];
			}
		}
		cout << endl;
		do
		{
			if (column1 == row2 && row1 != column2)
			{
				cout << endl << "check matrix dimensions" << endl ;
				Multiplication(*Firstmatrix, *SecondMtrx, *AnswerMtrx, column1);
				Show(*AnswerMtrx, row1, column2);
			}
			if (row1 == row2 && column1 == column2)
			{
				int sign;
				cout << "atcion" << endl;
				cout << "1 - multiplication" << endl;
				cout << "2 - summation" << endl;
				cout << "3 - subtraction" << endl;
				cout << "->";
				cin >> sign;

				while (!(sign == 1 || sign == 2 || sign == 3))
				{
					cout << "I don't know this. Please enter correct sign" << endl
						<< "Sign: ";
					cin >> sign;
				}
				switch (sign)
				{
				case 1:
					Multiplication(*Firstmatrix, *SecondMtrx, *AnswerMtrx, column1);
					Show(*AnswerMtrx, row1, column2);
					break;
				case 2:
					Sum(*Firstmatrix, *SecondMtrx, *AnswerMtrx);
					Show(*AnswerMtrx, row1, column1);
					break;
				case 3:
					Subtract(*Firstmatrix, *SecondMtrx, *AnswerMtrx);
					Show(*AnswerMtrx, row1, column1);
					break;
				}
			}
			if (!((column1 == row2 && row1 != column2) || (row1 == row2 && column1 == column2)))
			{
				cout << endl << "It's impossible to do something with this matrixes..." << endl << endl
					<< "Press the 'ESC' to exit this program," << endl
					<< "or other button to enter the new matrixes." << endl << endl;
			}
			else
			{
				cout << endl << "Press the 'ENTER', if you want to do another action with matrixes," << endl
					<< "'ESC' to exit this program," << endl
					<< "or other button to enter the new matrixes." << endl << endl;
			}
			exit = _getch();

		} while (exit == 13);

	} while (exit != 27);

	return 0;
}
