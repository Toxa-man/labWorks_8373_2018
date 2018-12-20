#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdio.h>
using namespace std;

#define N 1000

struct key_char
    {
	int o;
	char c[N];
    };

int getline(char s[], int lim)
{
    int c, i;

    for(i=0;i<lim-1 && (c=getchar()) !=EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int sort(key_char ob[],int count_kc)    
{
    int i,j;
    key_char m;
    for(i=0;i<count_kc;i++)
    {
	for(j=0;j<count_kc -1-i;j++)
	{

	    if(ob[j].o > ob[j+1].o)
	    {
		
		
		m=ob[j];
		
		ob[j]=ob[j+1];
		ob[j+1]=m;
		
	    }
	    
	    
		
			
	    
	    
	}
    }
    return 0;
}
int main()
{
    int count_kc = 0;
    
    
    char  a[N];
    key_char ob[N];
    key_char m;
    int k,j,i;
    j=0;
    ob[0].o = 0;
    k=0;
    
    getline(a,N);

    

    for(i=0;i<N ;i++)
    {
	if(a[i]!=' ' && a[i] != '\0')
	{
	     ob[j].o += (int)a[i];
	     
	    ob[j].c[k]=a[i];
	    k++;
	}
	else if (a[i] == ' ')
	{
	    ob[j].c[k]=a[i];
	    ob[j].c[k+1]= '\0';
	    
	    cout<<ob[j].o;
	    cout<<endl;
	    k=0;
	    j++;
	    ob[j].o = 0;
	    count_kc++;
	}
	else
	{
	    ob[j].c[k]=a[i];

	    

	    count_kc++;
	    break;
	}
	
    }

      
    sort(ob,count_kc);
 
    for(i=0;i<count_kc;i++)
    {
	for(j=0; ob[i].c[j]!='\0';j++)
	{
	    if(ob[i].c[j] !=' ')
		cout<<ob[i].c[j];
	    else
	    {
		cout<<ob[i].c[j];
		break;
	    }
		
	}
    }
    cout<<endl;
    cout<<count_kc;
    cout<<endl;
    return 0;
}
