#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <iomanip>
using namespace std;

const int M = 50, N = 50;

void MatrixSum(int* M1, int* M2, int* M3, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(M3 + i*N + j) = *(M1 + i*N + j) + *(M2 + i*N + j);
		}
	}
}

void MatrixSubstraction(int* M1, int* M2, int* M3, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			*(M3 + i*N + j) = *(M1 + i*N + j) - *(M2 + i*N + j);
		}
	}
}

void MatrixProduct(int* M1, int m1, int n1, int* M2, int m2, int n2, int* M3)
{
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			int l=0, k=0;
			for (int q = 0; q < n1; q++)
			{
				*(M3 + i*N + j) += *(M1 + i*N + l) * *(M2 + k*M + j);
				l++;
				k++;
			}
		}
	}
}

int main()
{
	char end;
	cout << "MaTrIxCaLc\n\n";
	do 
	{
		system("color E5");
		int m1, n1, m2, n2, m3, n3;
		int MatrixA[M][N], MatrixB[M][N];
		int* p1 = &MatrixA[0][0];
		int* p2 = &MatrixB[0][0];
		cout << "Enter matrix A size (m1 n1)\n";
		cin >> m1 >> n1;
		cout << "Define matrix A\n\n";
		for (int i = 0; i < m1; i++)
		{
			for (int j = 0; j < n1; j++)
			{
				cin >> *(p1 + i*N + j);
			}
		}
		cout<< "\n\nEnter matrix B size (m2 n2)\n";
		cin >> m2 >> n2;
		cout << "Define matrix B\n\n";
		for (int i = 0; i < m2; i++)
		{
			for (int j = 0; j < n2; j++)
			{
				cin >> *(p2 + i*N + j);
			}
		}
		do
		{
			int MatrixRes[M][N] = { 0 };
			int* p3 = &MatrixRes[0][0];
			cout << "\nWhat do u want to do with matrices? Possible operations:\n";
			bool result;
			if (m1 == m2 && n1 == n2 && n1 == m2)
			{
				result = true;
				m3 = m1;
				n3 = n2;
				cout << "1) A+B\n"
					 << "2) A-B\n"
					 << "3) A*B\n"
					 << "4) B*A\n"
					 << "Press code button (1/2/3/4)\n";
				char code = _getch();
				while (code != '1' && code != '2' && code != '3' && code != '4')
				{
					cout << "You pressed the wrong key press another (1 2 3 or 4)\n";
					code = _getch();
				}
				switch (code)
				{
				case('1') :
					cout << "You pressed " << code << " so A+B result:\n\n";
					MatrixSum(p1, p2, p3, m1, n2);
					break;
				case('2') :
					cout << "You pressed " << code << " so A-B result:\n\n";
					MatrixSubstraction(p1, p2, p3, m1, n2);
					break;
				case('3') :
					cout << "You pressed " << code << " so A*B result:\n\n";
					MatrixProduct(p1, m1, n1, p2, m2, n2, p3);
					break;
				case('4') :
					cout << "You pressed " << code << " so B*A result:\n\n";
					MatrixProduct(p2, m2, n2, p1, m1, n1, p3);
				}
			}
			else
			{
				if (n1 == m2 && m1 == n2)
				{
					result = true;
					cout << "1) A*B\n"
						<< "2) B*A\n"
						<< "Press code button (1/2)\n";
					char code = _getch();
					while (code != '1' && code != '2')
					{
						cout << "You pressed the wrong key press another (1 or 2)\n";
						code = _getch();
					}
					switch (code)
					{
					case('1') :
						cout << "You pressed " << code << " so A*B result:\n\n";
						m3 = m1;
						n3 = n2;
						MatrixProduct(p1, m1, n1, p2, m2, n2, p3);
						break;
					case('2') :
						m3 = m2;
						n3 = n1;
						cout << "You pressed " << code << " so B*A result:\n\n";
						MatrixProduct(p2, m2, n2, p1, m1, n1, p3);
					}
				}
				else
				{
					if (m1 == n2 || m2 == n1)
					{
						if (n1 == m2)
						{
							n3 = n2;
							m3 = m1;
							result = true;
							cout << "1) A*B\nThere is only one possible operation so A*B result:\n\n";
							MatrixProduct(p1, m1, n1, p2, m2, n2, p3);
						}
						if (m1 == n2)
						{
							n3 = n1;
							m3 = m2;
							result = true;
							cout << "1)B*A\nThere is only one possible operation so B*A result:\n\n";
							MatrixProduct(p2, m2, n2, p1, m1, n1, p3);
						}
					}
					else
					{
						if (m1 == m2 && n1 == n2)
						{
							m3 = m1;
							n3 = n1;
							result = true;
							cout << "1) A+B\n"
								<< "2) A-B\n"
								<< "Press code button (1/2)\n";
							char code = _getch();
							while (code != '1' && code != '2')
							{
								cout << "You pressed the wrong key press another (1 or 2)\n";
								code = _getch();
							}
							switch (code)
							{
							case('1') :
								cout << "You pressed " << code << " so A+B result:\n\n";
								MatrixSum(p1, p2, p3, m1, n2);
								break;
							case('2') :
								cout << "You pressed " << code << " so A-B result:\n\n";
								MatrixSubstraction(p1, p2, p3, m1, n2);
							}
						}
						else
						{
							result = false;
							cout << "There is no possible operations.\n";
						}
					}
				}
			}
			if (result)
			{
				for (int i = 0; i < m3; i++)
				{
					for (int j = 0; j < n3; j++)
					{
						cout << MatrixRes[i][j]<<"  ";
					}
					cout << endl;
				}
			}
			cout << "\nTo close the program press ESC\n"
				<< "To make another operation with the same matrices press SPACE\n"
				<< "To overrun the program press ANY OTHER KEY\n\n";
			end = _getch();
		} while (end == 32);
	} while (end != 27);
    return 0;
}