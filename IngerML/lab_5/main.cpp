#include <iostream>
using namespace std;
void Print(int *Matrix3, int col1, int row1, int col2, int row2, const int siez)
{
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
		{
			cout << *(Matrix3 + i * siez + j) << "\t";
		}
		cout << endl;
	}
}
void PrintUmnoj(int *Matrix3, int col1, int row1, int col2, int row2, const int siez)
{
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
		{
			for(int k = 0; k < row2; k++)
			{
			if (k%2 == 1)
				{
					cout <<*(Matrix3 + i * siez + j) << "\t" ;
				}
			}
		}
		cout << endl;
	}
}
void Sclad(int *Matrix1, int *Matrix2, int *Matrix3, int col1, int row1, int col2, int row2, const int siez)
{
	if (row1 == row2 && col1 == col2)
	{
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				*(Matrix3 + i * siez + j) = *(Matrix1 + i * siez + j) + *(Matrix2 + i * siez + j);

			}
		}
	}
	else { cout << "������ ���������� ������� ������ ��������"; }
}



void Raznost(int *Matrix1, int *Matrix2, int *Matrix3, int col1, int row1, int col2, int row2, const int siez)
{

	if (row1 == row2 && col1 == col2)
	{
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col1; j++)
			{
				*(Matrix3 + i * siez + j) = *(Matrix1 + i * siez + j) - *(Matrix2 + i * siez + j);

			}
		}
	}
}
void Umnoj(int *Matrix1, int *Matrix2, int *Matrix3, int col1, int row1, int col2, int row2, const int siez)
{
	if (col1 == row2)
	{
		int n = col1;
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				for (int k = 0; k < row2; k++)
				*(Matrix3 + i * siez + j) += *(Matrix1 + i * siez + k) * *(Matrix2 + k * siez + j);
			}
				
		}
	}
	else { cout << "��� ��������� ������ ���������� ����� ������ ������ ���� ����� ���������� �������� ������"; }
}

int Func()
{

	setlocale(LC_ALL, "rus");
	const int siez = 20;
	int Matrix3[siez][siez];
	for (int i = 0; i < siez; i++)
	{
		for (int j = 0; j < siez; j++)
			Matrix3[i][j] = 0;
	}
	cout << "����� ����� ������ �������: "; //���� ���������� ����� 1 �������
	int row1; // ����, ������, �����
	cin >> row1;
	cout << "����� �������� ������ �������:"; //���� ���������� �������� 1 �������
	int col1; // �������, �������
	cin >> col1;
	cout << "������� ������� A. ����� ����� ������, ����� ����� enter" << endl;
	int Matrix1 [siez][siez];
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
			cin >> Matrix1[i][j];
	}
		cout << "����� ������� A \n";
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
			cout << Matrix1[i][j] << "\t";
		cout << endl;
	}
	cout << "����� ����� ������ �������: ";
	int row2;
	cin >> row2;
	cout << "����� �������� ������ �������:";
	int col2;
	cin >> col2;
	cout << "������� ������� B. ����� ����� ������, ����� ����� enter" << endl;
	int Matrix2[siez][siez];
	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
			cin >> Matrix2[i][j];
	}
	cout << "����� ������� B \n";
	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < col2; j++)
			cout << Matrix2[i][j] << "\t";
		cout << endl;
	}
	cout << "������� ��������. '+', '-' ��� '*' : " << endl;
	char znac;
	cin >> znac;
	switch (znac)
	{
	case '+':
		cout << "�����: " << endl;
		Sclad(*Matrix1, *Matrix2, *Matrix3, col1, row1, col2, row2, siez);
		Print(*Matrix3, col1, row1, col2, row2, siez);
		break;
	case '-':
		cout << "��������: " << endl;
		Raznost(*Matrix1, *Matrix2, *Matrix3, col1, row1, col2, row2, siez);
		Print(*Matrix3, col1, row1, col2, row2, siez);
		break;
	case '*':
		cout << "������������: " << endl;
		Umnoj(*Matrix1, *Matrix2, *Matrix3, col1, row1, col2, row2, siez);
		PrintUmnoj(*Matrix3, col1, row1, col2, row2, siez);
		break;
	}
	
	cout << "�� ������ ��������� ���������? ���� ��, ������� '1' ���� ��� ������� '0'. ���� �� ������� 0, ����� ������� ����� ������� 3 ����";
	cout << endl;
	int otvet;
	cin >> otvet;
	if (otvet == 1)
	{Func();}
	system("pause");
	return 0;
}
int main()
{
	Func();
	system("pause");
	return 0;
}
