#include <iostream>
#include <conio.h>
using namespace std;

void Closhenie(int *mass, int *mass2, int *mass3, int ctr, int stlb, const int size)
{
	for (int i = 0; i < ctr; ++i)
	{
		for (int g = 0; g < stlb; ++g)
		{
			*(mass3 + (i * size) + g) = *(mass + (i * size) + g) + *(mass2 + (i * size) + g);
		}
	}
}

void Vchitanie(int *mass, int *mass2, int *mass3, int ctr, int stlb, const int size)
{
	for (int i = 0; i < ctr; ++i)
	{
		for (int g = 0; g < stlb; ++g)
		{
			*(mass3 + (i * size) + g) = *(mass + (i * size) + g) - *(mass2 + (i * size) + g);
		}
	}
}

void Umnoshenie(int *mass, int *mass2, int *mass3, int ctr1, int stlb1, int ctr2, int stlb2, const int size)
{
	for (int i = 0; i < ctr1;++i)
	{
		for (int g = 0; g < stlb2;++g)
		{
			for (int y = 0; y < stlb1; ++y)
			{
				*(mass3 + (i * size) + g) += (*(mass + (i*size) + y))*(*(mass2 + (y*size) + g));
			}
		}
	}
}
int main()
{
	char exit = '1';
	while (exit!=27)
	{
		setlocale(0, "");
		const int size = 100;
		int matrix_1[size][size];
		int matrix_2[size][size];
		int ctr_matrix_1, ctr_matrix_2, stlb_matrix_1, stlb_matrix_2;
		cout << "Ââåäèòå êîëè÷åñòâî ñòðîê ïåðâîãî ìàññèâà: ";
		cin >> ctr_matrix_1;
		cout << "Ââåäèòå êîëè÷åñòâî ñòîëáöîâ ïåðâîãî ìàññèâà: ";
		cin >> stlb_matrix_1;
		for (int i = 0; i < ctr_matrix_1; ++i)
		{
			cout << "Ââåäèòå " << i + 1 << " ñòðîêó ìàññèâà" << endl;
			for (int g = 0; g < stlb_matrix_1; ++g)
			{
				cin >> matrix_1[i][g];
			}
			cout << endl;
		}
		cout << "Ââåäèòå êîëè÷åñòâî ñòðîê âòîðîãî ìàññèâà: ";
		cin >> ctr_matrix_2;
		cout << "Ââåäèòå êîëè÷åñòâî ñòîëáöîâ âòîðîãî ìàññèâà: ";
		cin >> stlb_matrix_2;
		for (int i = 0; i < ctr_matrix_2; ++i)
		{
			cout << "Ââåäèòå " << i + 1 << " ñòðîêó ìàññèâà" << endl;
			for (int g = 0; g < stlb_matrix_2; ++g)
			{
				cin >> matrix_2[i][g];
			}
			cout << endl;
		}
		int matrix_result[size][size] = { 0 };
		char znak;
		cout << "Âûáåðèòå îïåðàöèþ(+,-,*) ";
		cin >> znak;
		cout << "Ðåçóëüòàò: " << endl;
		switch (znak) {
		case '+':
			if (ctr_matrix_1 == ctr_matrix_2 && stlb_matrix_1 == stlb_matrix_2)
			{
				Closhenie(*matrix_1, *matrix_2, *matrix_result, ctr_matrix_1, stlb_matrix_1, size);
				for (int i = 0; i < ctr_matrix_1; ++i)
				{
					for (int g = 0; g < stlb_matrix_1; ++g)
					{
						cout << matrix_result[i][g] << "  ";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "Íåâîçìîæíî ñëîæèòü";
			}
			break;
		case'-':
			if (ctr_matrix_1 == ctr_matrix_2 && stlb_matrix_1 == stlb_matrix_2)
			{
				Vchitanie(*matrix_1, *matrix_2, *matrix_result, ctr_matrix_1, stlb_matrix_1, size);
				for (int i = 0; i < ctr_matrix_1; ++i)
				{
					for (int g = 0; g < stlb_matrix_1; ++g)
					{
						cout << matrix_result[i][g] << "  ";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "Íåâîçìîæíî âû÷åñòü";
			}
			break;
		case'*':
			if (ctr_matrix_2 == stlb_matrix_1)
			{
				Umnoshenie(*matrix_1, *matrix_2, *matrix_result, ctr_matrix_1, stlb_matrix_1, ctr_matrix_2, stlb_matrix_2, size);
				for (int i = 0; i < ctr_matrix_1; ++i)
				{
					for (int g = 0; g < stlb_matrix_2; ++g)
					{
						cout << matrix_result[i][g] << "  ";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "Íåâîçìîæíî ïåðåìíîæèòü";
			}
			break;
		default:
			cout << "Íåïðàâèëüíûé çíàê";
		}
		cout << endl;
		cout << "Äëÿ ïðîäîëæåíèÿ íàæìèòå ëþáóþ êëàâèøó, äëÿ âûõîäà íàæíèòå ESC";
		exit = _getch();
		cout << endl;
	}
	return 0;
}
