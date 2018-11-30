#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
const int con = 100;
void multipy1(int mat1[con][con], int mat2[con][con], int p1, int p2, int p3)
{
	int mat3[con][con] = { 0 };
	if (p1 == p2 || p2==p3)
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
		for (int k = 0; k < p1; k++)
		{
			for (int i = 0; i < p2; i++)
			{
				cout << setw(10) << right << mat3[k][i];
			}
			cout << endl;
		}
	}
	
}
void ckl(int mat1[con][con], int mat2[con][con], int p1)
{
	int mat3[con][con];
	for (int k = 0; k < p1; k++)
	{
		for (int i = 0; i < p1; i++)
		{
			mat3[k][i]= mat1[k][i]+mat2[k][i];
		}
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
void vich1(int mat1[con][con], int mat2[con][con], int p1)
{
	int mat3[con][con];
	for (int k = 0; k < p1; k++)
	{
		for (int i = 0; i < p1; i++)
		{
			mat3[k][i] = mat1[k][i] - mat2[k][i];
		}
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
int main()
{
	int det, error(1), error1(1), p1,p2, n1,n2;
	int mat1[con][con];
	int mat2[con][con];
	int mat3[con][con];
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
				multipy1(mat1, mat2, p1, p2, n1);
				break;
			case 2:
				multipy1(mat2, mat1, p2, p1, n1);
				break;
			case 3:
				ckl(mat1, mat2, p1);
				break;
			case 4:
				vich1(mat1, mat2, p1);
				break;
			case 5:
				vich1(mat2, mat1, p1);
				break;
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
					multipy1(mat1, mat2, p1, p2, n1);
					break;
				case 2:
					multipy1(mat2, mat1, p2, p1, n2);
					break;
				}
			}
			else
			{
				if (p2 == n1)
				{
					cout << " A*B" << endl;
					multipy1(mat1, mat2, p1, n2, p2);
				}
				if (p1 == n2)
				{
					cout << " B*A" << endl;
					multipy1(mat2, mat1, n1, p2, p1);
				}
			}
		}
		cout << endl;
		cout << "Do you want to continue?" << endl;
		cout << "Yes - 1" << endl;
		cout << "No - 0" <<endl;
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