#include <iostream>
#include <conio.h>
#include<string.h>
#include<stdio.h>

using namespace std;

void sum_of_matrix(int* a, int* b, int* c, int size){
    for(int i=0; i<size; i++){
        for(int p=0; p<size; p++){
            *(c+size*i+p)=*(b+size*i+p)+*(a+size*i+p);
        }
    }
}

void dif_of_matrix(int* a, int* b, int* c, int size){
    for(int i=0; i<size; i++){
        for(int p=0; p<size; p++){
            *(c+size*i+p)=*(a+size*i+p)-*(b+size*i+p);
        }
    }
}

void mult_of_matrix(int* a, int* b, int* c, int size){
    for(int s=0; s<size; s++){
        for(int j=0; j<size; j++){
            for(int p=0; p<size; p++){
                *(c+s*size+j)+=(*(a+s*size+p) * *(b+p*size+j));
            }
        }
    }
}



int main()
{   const int n=2;
    int matr1[n][n]={{1,2},{3,4}};
    int matr2[n][n]={{5,6},{7,8}};
    cout<<"This is the first matrix:"<<endl;
    for(int i=0; i<n; i++){
        for(int p=0; p<n; p++){
            cout<<matr1[i][p]<<" ";
        }
        cout<<endl;
    }
    cout<<"This is the second matrix:"<<endl;
    for(int i=0; i<n; i++){
        for(int p=0; p<n; p++){
            cout<<matr2[i][p]<<" ";
        }
        cout<<endl;
    }
    char button=1;
    char choise;
    while(button!=27){
        int matr3[n][n]={{0,0},{0,0}};
        bool b=true;
        while(b){
            cout<<"Enter the desired operation: ";
            cin>>choise;
            switch(choise){
                case '+': sum_of_matrix((int*)matr1, (int*)matr2, (int*)matr3, n);
                    b=false;
                    break;
                case '-':dif_of_matrix((int*)matr1, (int*)matr2, (int*)matr3, n);
                    b=false;
                    break;
                case '*': mult_of_matrix((int*)matr1, (int*)matr2, (int*)matr3, n);
                    b=false;
                    break;
                default: cout<<"Incorrect value"<<endl;
            }
        }
        cout<<"This is the result:"<<endl;
        for(int i=0; i<n; i++){
            for(int p=0; p<n; p++){
                cout<<matr3[i][p]<<" ";
            }
            cout<<endl;
        }
        cout<<"Press 'esc' to exit or press another button to continue working"<<endl;
        button=_getch();
    }
    system("pause");
    return 0;
}
