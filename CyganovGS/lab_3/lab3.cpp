#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>

using namespace std;

int main(){
        setlocale(0, "");
        const int size = 256;
        const int half_size=128;
        char str_base[size], str_otv[size];
        int c=0, size_base, i=1, p=0, n_sim=0, j=0, kolvo=0;
        int znach[size-1];
        cout<<"Print your text here, but use only english letters: ";
        gets(str_base);
        char array[half_size][size];
        for(int i=0; i<half_size; i++){
            for(int j=0; j<size; j++){
                array[i][j]='/0';
            }
        }
        size_base=strlen(str_base);
        while(c<size_base){
                n_sim=0;
                znach[kolvo]=0;
                while(((str_base[c])>=65 && str_base[c]<=90) || ((str_base[c])>=97 && (str_base[c])<=122)){
                        array[kolvo][n_sim]=str_base[c];
                        znach[kolvo]=znach[kolvo]+(int)(str_base[c]);
                        c++;
                        n_sim++;
                }
                array[kolvo][n_sim]='\0';
                kolvo++;
                c++;
        }
        while (i<kolvo){
                j=i;
                while (znach[j]<znach[j-1]){
                        p=znach[j];
                        znach[j]=znach[j-1];
                        znach[j-1]=p;
                        for(int k=0;k<size;k++){
                                char uk=array[j][k];
                                array[j][k]=array[j-1][k];
                                array[j-1][k]=uk;
                        }
                        j--;
                }
                i++;
        }
        cout<<"Result: ";
        for (int x=0; x<kolvo; x++){
                cout<<array[x]<<" ";
        }
        cout<<endl;
        system("pause");
        return 0;
}
