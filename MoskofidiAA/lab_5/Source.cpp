#include <iostream>
#include <conio.h>

using namespace std;
const int N = 3;
const int M = 3;

int multiply(int i, int j, int m1[N][M], int m2[N][M])
{
	int m3[N][M];
	m3[i][j] = 0;
	for (int k = 0; k < N; k++)
	{
		m3[i][j] += m1[i][k] * m2[k][i + (j - i)];
	}
	return m3[i][j];
}

int sum(int i, int j, int m1[N][M], int m2[N][M])
{
			return (m1[i][j] + m2[i][j]);
}

int dif(int i, int j, int m1[N][M], int m2[N][M])
{
	return (m1[i][j] - m2[i][j]);
}

int main()
{
	int num;
	char con;
	int m1[N][M];
	int m2[N][M];
	int m3[N][M];
	cout << "Enter matrix #1 (N x M)" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m1[i][j];
		}
	}
	cout << endl;
	cout << "Enter matrix #2 (N x M)" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m2[i][j];
		}
	}
	cout << endl;
	cout << "1) Multiply" << endl;
	cout << "2) Sum" << endl;
	cout << "3) Difference" << endl;
	cout << "What you want to do?" << endl;
	cout << "Enter number of action:" << endl;
	cin >> num;
	switch (num)
	{
	case 1: if (N == M)
			{
				cout << "Matrix #3:" << endl;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						cout << multiply(i, j, m1, m2) << " ";
						m3[i][j] = multiply(i, j, m1, m2);
					} cout << endl;
				}
				cout << endl;
			} else cout << "Enter Matrixes with same number of column and row (M = N)";
	break;
	case 2: cout << "Matrix #3:" << endl;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					cout << sum(i, j, m1, m2) << " ";
					m3[i][j] = sum(i, j, m1, m2);
				} cout << endl;
			}
			cout << endl;
	break;
	case 3: cout << "Matrix #3:" << endl;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					cout << dif(i, j, m1, m2) << " ";
					m3[i][j] = dif(i, j, m1, m2);
				} cout << endl;
			}
			cout << endl;
	break;
	default: cout << "Type right number." << endl;
	break;
	}
	cout << "Do you want to continue?" << endl;
	cout << "Y - contunue / N - exit" << endl;
	cin >> con;
	while (1) {
		if ((con == 'y') || (con == 'Y')) {
			cout << "Enter number of action:" << endl;
			cin >> num;
			switch (num)
			{
			case 1: if (N == M)
					{
						cout << "Matrix #3:" << endl;
						for (int i = 0; i < N; i++) {
							for (int j = 0; j < M; j++) {
								cout << multiply(i, j, m1, m2) << " ";
								m3[i][j] = multiply(i, j, m1, m2);
							} cout << endl;
						}
						cout << endl;
					} else cout << "Enter Matrixes with same number of column and row (M = N)";
			break;
			case 2: cout << "Matrix #3:" << endl;
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < M; j++) {
							cout << sum(i, j, m1, m2) << " ";
							m3[i][j] = sum(i, j, m1, m2);
						} cout << endl;
					}
					cout << endl;
			break;
			case 3: cout << "Matrix #3:" << endl;
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < M; j++) {
							cout << dif(i, j, m1, m2) << " ";
							m3[i][j] = dif(i, j, m1, m2);
						} cout << endl;
					}
					cout << endl;
			break;
			default: cout << "Type right number." << endl;
			break;
			}
		}
		else if ((con == 'n') || (con == 'N')) {
			exit(1);
		}
		cout << "Do you want to continue?" << endl;
		cout << "Y - contunue / N - exit" << endl;
		cin >> con;
	}
}