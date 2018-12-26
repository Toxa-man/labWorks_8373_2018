#include <windows.h>
#include <iostream>
#include <ctime>

using namespace std;

const int NCOLS = 8;
const int NROWS = 8;
const int NBOMBS= 5;

void reset(int A[][NCOLS],int B[][NCOLS]);
void printArray(int A[][NCOLS]);
void BombPlace(int A[][NCOLS]);
void squareSetter(int A[][NCOLS]);
void reciever(int A[][NCOLS], int B[][NCOLS]);
void clearField(int A[][NCOLS],int B[][NCOLS], int x, int y);
void champ(int Metal[][NCOLS]);


int _tmain(int argc, _TCHAR* argv[])
{    srand(time(0));
    int board[NROWS][NCOLS];
    int mask[NROWS][NCOLS];
    char again;
    do{
    reset(board, mask);
    printArray(mask);
    BombPlace(board);
    squareSetter(board);

    reciever(mask, board);
    cout << "Would you like to play again?"<<endl;
    cin >> again;
    }while(again == 'y');
    return 0;
}
void BombPlace(int A[][NCOLS]){
    int counter = 0;
    int i = 0, j = 0;

    while(counter < NBOMBS)
        {
    i = rand()%NROWS;
    j = rand()%NCOLS;
    if(A[i][j] == 0)
        {
         A[i][j] = -1;
         counter ++;
        }
    }
}

void squareSetter(int A[][NCOLS])
{
 int c;
    for(int i = 0; i< NROWS;i++)
    {
        c = 0;
        for(int j = 0; j < NCOLS; j++)
        {c=0;
            if (i < NROWS - 1)

            if (A[i + 1][j] == -1)
               c++;

         if(j < NCOLS-1){

            if(A[i][j+1]==-1)
                 c++;

          if(i<NROWS-1)

            if(A[i+1][j+1]==-1)
                             c++;

                }
             if(i>0)
            {
                if(A[i-1][j]== -1)
                                 c++;

              if(j<NCOLS-1)

                if(A[i-1][j+1]==-1)
                  c++;
                }
          if(j>0)
            {  if(i<NROWS-1)

                {if(A[i+1][j-1]==-1)
                    c++;
                }

                 if(A[i][j-1]==-1)
                    {c++;}
            }
            if(i>0 && j>0)
            {
                if(A[i-1][j-1]==-1)
                                c++;

            }
            if(A[i][j] != -1)
                A[i][j]= c;
                   }

    }

}


void printArray(int A[][NCOLS])
{cout << endl;
    for(int i = 0; i < NROWS; i++)
    {for(int j = 0; j < NCOLS; j++)
            cout << A[i][j] << "  ";
        cout << "\n"<< endl;}
    cout << "\n\n\n" << endl;
}
void reset(int A[][NCOLS], int B[][NCOLS]){
    for(int i = 0 ;i < NROWS; i++)
        for(int j = 0 ;j < NCOLS; j++)
            A[i][j] =0;
    for(int i = 0 ;i < NROWS; i++)
        for(int j = 0 ;j < NCOLS; j++)
            B[i][j] = 9;
}

void reciever(int A[][NCOLS], int B[][NCOLS]){
    int x, y, metal =0;

    do
    {
    cout << "Enter coordinate" << endl;
    cin >> x >> y;
if(B[x][y] == 0)
    clearField(A, B, x, y);
if (B[x][y] == -1)
    {cout << "GAME OVER!" << endl;
     printArray(B);
     break;
    }
else
    {if(A[x][y] = 9)
        metal ++;
     A[x][y] = B[x][y];
     printArray(A);
    }
champ(A);
    }while(true);
}

void champ(int Metal[][NCOLS]){
    int Detector = 0;
    for(int i = 0; i < NROWS; i++)
        for(int j = 0; j < NCOLS; j++)
    if (Metal[i][j] == 9)
        Detector++;
    if (Detector == NBOMBS)
        cout << "Super Sweeping!" << endl;
}

void clearField(int A[][NCOLS], int B[][NCOLS], int x, int y){

    int i = x, j = y;
for(i; i < NROWS; i++)
{if(B[i][j] > 0)
break;
        for(j ;j < NCOLS; j++)
        {
    if(B[i][j] > 0)
    {A[i][j] = B[i][j];break;}
if(j < NCOLS-1)
    A[i][j+1] = B[i][j+1];
if(i < NROWS-1 && j < NCOLS-1)
    A[i+1][j+1] = B[i+1][j+1];
if(i < NROWS - 1)
    A[i+1][j] = B[i+1][j];
        }
}
for(i = x; i >= 0; i--)
{if(B[i][j] > 0)
break;
    for(j = y; j >= 0; j--)
        {
    if(B[i][j] > 0)
    {B[i][j] = B[i][j];break;}
    if(j > 0)
        A[i][j-1] = B[i][j-1];
    if( i > 0 && j > 0)
        A[i-1][j-1] = B[i-1][j-1];
    if(i > 0)
        A[i-1][j] = B[i-1][j];
    }
}
for(i = x; i < NROWS; i++)
{if(B[i][j] > 0)
break;
    for(j = y;j >= 0; j--)
        {
            if(B[i][j] > 0)
                {A[i][j] = B[i][j];break;}
            if(i < NROWS - 1)
                {A[i+1][j] = B[i+1][j];
                 A[i+1][j-1] = B[i+1][j-1];}
            A[i][j-1] = B[i][j-1];
        }
}
for(i = x; i > 0; i--)
{if(B[i][j] > 0)
break;
    for(j = y;j < NCOLS; j++)
        {
            if(B[i][j] > 0)
                {A[i][j] = B[i][j];break;}
            A[i-1][j] = B[i-1][j];
            if(j<NCOLS-1)
                {A[i-1][j+1] = B[i-1][j+1];
                 A[i][j+1] = B[i][j+1];}
        }
}
}

	return 0;

