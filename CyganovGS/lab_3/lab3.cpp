#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>

using namespace std;

int main(){
	char str_base[256], str_otv[256];
	int c=0, size_base, i=1, p=0, n_sim=0, j=0, kolvo=0;
	int znach[255];
	cout<<"Print your text here, but use only english letters: ";
	gets(str_base);
	char array[128][256];
	size_base=strlen(str_base);
	while(c<size_base){
		n_sim=0;
		znach[kolvo]=0;
		while(((int)(str_base[c])>=65 and (int)str_base[c]<=90) or (int)((str_base[c])>=97 and (int)(str_base[c])<=122)){
			array[kolvo][n_sim]=array[kolvo][n_sim]+str_base[c];
			znach[kolvo]=znach[kolvo]+(int)(str_base[c]);
			c++;
			n_sim++;
		}
		array[kolvo][n_sim+1]='\0';
		kolvo++;
		c++;
	}
	while (i<kolvo){
		j=i;
		while (znach[j]<znach[j-1]){
			p=znach[j];
			znach[j]=znach[j-1];
			znach[j-1]=p;
			for(int k=0;k<256;k++){
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
