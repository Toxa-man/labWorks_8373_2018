#include <iostream>
#include <conio.h>

using namespace std;
const int N = 3;

int multiply ( int m1[N][N], int m2[N][N])
{
    int m3[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m3[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                m3[i][j] += m1[i][k] * m2[k][i+(j-i)];
            }
        }
    }
    cout << "Matrix #3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            cout << m3[i][j] << " " ;
        } cout << endl;
    }
    cout << endl;
    return 0;
}

int sum (int m1[N][N], int m2[N][N])
{
    int m3[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
    cout << "Matrix #3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            cout << m3[i][j] << " " ;
        } cout << endl;
    }
    cout << endl;
    return 0;
}

int dif (int m1[N][N], int m2[N][N])
{
    int m3[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m3[i][j] = m1[i][j] - m2[i][j];
        }
    }
    cout << "Matrix #3:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            cout << m3[i][j] << " " ;
        } cout << endl;
    }
    cout << endl;
    return 0;
}

int main()
{
    int num;
    char con;
    int code;
    int m1[N][N];
    int m2[N][N];
    cout << "Enter matrix #1" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            // cout << "Enter element[" << i << "][" << j << "]:" << endl;
            cin >> m1[i][j];
        }
    }
    cout << endl;
    cout << "Enter matrix #2" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            // cout << "Enter element[" << i << "][" << j << "]:" << endl;
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
    if(num == 1)
        multiply(m1, m2);
    else if(num == 2)
        sum(m1,m2);
    else if(num == 3)
        dif(m1,m2);
    else
        cout<<"Type right number." << endl;
    cout << "Do you want to continue?" << endl;
    cout << "Y - contunue / N - exit" << endl;
    cin >> con;
    code = static_cast<int>(con);
    while (1) { // 78     110
        if ((code == 89) || (code == 121)) {
            cout << "Enter number of action:" << endl;
            cin >> num;
            if(num == 1)
                multiply(m1, m2);
            else if(num == 2)
                sum(m1,m2);
            else if(num == 3)
                dif(m1,m2);
            else
                cout<<"Type right number." << endl;
        } else if ((code == 78) || (code == 110)) {
                    return 0;
               }
         cout << "Do you want to continue?" << endl;
         cout << "Y - contunue / N - exit" << endl;
         cin >> con;
         code = static_cast<int>(con);
    }
}
