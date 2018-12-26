#include <iostream>
#include <windows.h>
using namespace std;

int coun_neib(int *b_l_1, int a, int b, int y, int z, int size) {
	int counter = 0;
	for (int i = a; i < y; i++) {
		for (int j = b; j < z; j++) {
			if (*(b_l_1 + i * size + j) == 1) {
				counter++;
			}
		}
	}
	return counter;
}

int main() {
	int const space = 100;
	int const size = 10;
	int life_1[space], life_2[space], *b_l_1, check = 0, check_nulls = 0;
	b_l_1 = &life_1[0];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			life_1[i * size + j] = rand() % 2;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (life_1[i * size + j] == 1) {
				cout << "X" << " ";
			}
			else {
				cout << "-" << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	while (check != space && check_nulls != space) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				int a = 0, b = 0, y = 0, z = 0;
				if ((i == 0 && j == 0) || (i == size - 1 && j == size - 1) || i + size - 1 == j || i == j + size - 1) {
					a = i;
					b = j;
					if (i != 0) {
						a--;
					}
					if (j != 0) {
						b--;
					}
					y = a + 2;
					z = b + 2;
				}
				else if (i != 0 && j != 0 && i != size - 1 && j != size - 1) {
					a = i - 1;
					b = j - 1;
					y = a + 3;
					z = b + 3;
				}
				else if ((i == 0 && j != 0 && j != size - 1) || (i == size - 1 && j != 0 && j != size - 1)) {
					a = i;
					b = j;
					if (i != 0) {
						a--;
					}
					if (j != 0) {
						b--;
					}
					y = a + 2;
					z = b + 3;
				}
				else if (j == 0 || j == size - 1) {
					a = i;
					b = j;
					if (i != 0) {
						a--;
					}
					if (j != 0) {
						b--;
					}
					y = a + 3;
					z = b + 2;
				}
				int neib = coun_neib(b_l_1, a, b, y, z, size);
				if (life_1[i * size + j] == 0) {
					if (neib == 3) {
						life_2[i * size + j] = 1;
					}
					else {
						life_2[i * size + j] = 0;
					}
				}
				else if (life_1[i * size + j] == 1) {
					if (neib == 3 || neib == 4) {
						life_2[i * size + j] = 1;
					}
					else {
						life_2[i * size + j] = 0;
					}
				}
			}
		}
		cout << endl;
		check = 0;
		check_nulls = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (life_1[i * size + j] == life_2[i * size + j]) {
					check++;
				}
				if (life_2[i * size + j] == 0) {
					check_nulls++;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				life_1[i * size + j] = life_2[i * size + j];
				life_2[i * size + j] = 0;
			}
		}
		Sleep(1500);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (life_1[i * size + j] == 1) {
					cout << "X" << " ";
				}
				else {
					cout << "-" << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
