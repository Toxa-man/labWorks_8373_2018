#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
const int con = 10;
int multipy1(int mat1[con][con], int mat2[con][con], int mat3[con][con], int p1, int p2, int p3)
{
	if (p1 == p2 || p2 == p3)
	{
		for (int k = 0; k < p1; k++)
		{
			for (int i = 0; i < p1; i++)
			{
				for (int j = 0; j < p2; j++)
				{
					mat3[k][i] = mat3[k][i] + mat1[k][j] * mat2[j][i];
				}
			}
		}
	}
	else
	{
		for (int k = 0; k < p1; k++)
		{
			for (int i = 0; i < p2; i++)
			{
				for (int j = 0; j < p3; j++)
				{
					mat3[k][i] = mat3[k][i] + mat1[k][j] * mat2[j][i];
				}
			}
		}
	}
	return mat3[con][con];
}
int ckl(int mat1[con][con], int mat2[con][con], int mat3[con][con], int p1)
{
	for (int k = 0; k < p1; k++)
	{
		for (int i = 0; i < p1; i++)
		{
			mat3[k][i] = mat1[k][i] + mat2[k][i];
		}
	}
	return mat3[con][con];
}
int vich1(int mat1[con][con], int mat2[con][con], int mat3[con][con], int p1)
{
	for (int k = 0; k < p1; k++)
	{
		for (int i = 0; i < p1; i++)
		{
			mat3[k][i] = mat1[k][i] - mat2[k][i];
		}
	}
	return mat3[con][con];
}
int main()
{
	int det, error(1), error1(1), p1, p2, n1, n2;
	int mat1[con][con];
	int mat2[con][con];
	int mat3[con][con] = { 0 };
	while (error != 0)
	{
		if (error1 == 1)
		{
			cout << "Input matrix A size" << endl;
			cout << "Lines:";
			cin >> p1;
			cout << "Columns:";
			cin >> p2;
			cout << endl;
			cout << "Input matrix A:" << endl;
			for (int k = 0; k < p1; k++)
			{
				for (int i = 0; i < p2; i++)
				{
					cin >> setw(10) >> right >> mat1[k][i];
				}
				cout << endl;
			}
			cout << "Input matrix B size" << endl;
			cout << "Lines:";
			cin >> n1;
			cout << "Columns:";
			cin >> n2;
			cout << endl;
			cout << "Input matrix B:" << endl;
			for (int k = 0; k < n1; k++)
			{
				for (int i = 0; i < n2; i++)
				{
					cin >> setw(10) >> right >> mat2[k][i];
				}
				cout << endl;
			}
		}
		if (p1 == p2 && p1 == n1 && p2 == n2)
		{
			cout << "1) A*B" << endl;
			cout << "2) B*A" << endl;
			cout << "3) A+B" << endl;
			cout << "4) A-B" << endl;
			cout << "5) B-A" << endl;
			cout << "Input number:" << endl;
			cin >> det;
			switch (det)
			{
			case 1:
				mat3[con][con] = multipy1(mat1, mat2, mat3, p1, p2, n1);
				break;
			case 2:
				mat3[con][con] = multipy1(mat2, mat1, mat3, p2, p1, n1);
				break;
			case 3:
				mat3[con][con] = ckl(mat1, mat2, mat3, p1);
				break;
			case 4:
				mat3[con][con] = vich1(mat1, mat2, mat3, p1);
				break;
			case 5:
				mat3[con][con] = vich1(mat2, mat1, mat3, p1);
				break;
			}
			for (int k = 0; k < p1; k++)
			{
				for (int i = 0; i < p1; i++)
				{
					cout << setw(10) << right << mat3[k][i];
				}
				cout << endl;
			}
		}
		else
		{
			if (p1 == n2 && p2 == n1)
			{
				cout << "1) A*B" << endl;
				cout << "2) B*A" << endl;
				cout << "Input number:" << endl;
				cin >> det;
				switch (det)
				{
				case 1:
					mat3[con][con] = multipy1(mat1, mat2, mat3, p1, p2, n1);
					for (int k = 0; k < p1; k++)
					{
						for (int i = 0; i < p1; i++)
						{
							cout << setw(10) << right << mat3[k][i];
						}
						cout << endl;
					}
					break;
				case 2:
					mat3[con][con] = multipy1(mat2, mat1, mat3, p2, p1, n2);
					for (int k = 0; k < p2; k++)
					{
						for (int i = 0; i < p2; i++)
						{
							cout << setw(10) << right << mat3[k][i];
						}
						cout << endl;
					}
					break;
				}
			}
			else
			{
				if (p2 == n1)
				{
					cout << " A*B" << endl;
					mat3[con][con] = multipy1(mat1, mat2, mat3, p1, n2, p2);
					for (int k = 0; k < p1; k++)
					{
						for (int i = 0; i < n2; i++)
						{
							cout << setw(10) << right << mat3[k][i];
						}
						cout << endl;
					}
				}
				if (p1 == n2)
				{
					cout << " B*A" << endl;
					mat3[con][con] = multipy1(mat2, mat1, mat3, n1, p2, p1);
					for (int k = 0; k < n1; k++)
					{
						for (int i = 0; i < p2; i++)
						{
							cout << setw(10) << right << mat3[k][i];
						}
						cout << endl;
					}
				}
			}
		}
		for (int k = 0; k < con; k++)
		{
			for (int i = 0; i < con; i++)
			{
				mat3[k][i]=0;
			}
		}
		cout << endl;
		cout << "Do you want to continue?" << endl;
		cout << "Yes - 1" << endl;
		cout << "No - 0" << endl;
		cout << "Your answer:" << endl;
		cin >> error;
		if (error != 0)
		{
			cout << "Do you want to input another matrix?" << endl;
			cout << "Yes - 1" << endl;
			cout << "No - 0" << endl;
			cout << "Your answer:" << endl;
			cin >> error1;
		}
	}
}