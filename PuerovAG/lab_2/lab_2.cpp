#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int n= 100;

int gen_array(int *a, int n)
{
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
	a[i]=rand()%100;
	cout<<a[i]<<" ";
    }
    return 0;
}

int sort_array(int *a, int n)
{
    int i;
    i=0;
    int j;
    j=0;
    int k;
    while (i<n)
    {
	
	while(j<n-1-i)
	{
	    if (a[j]>a[j+1])
	    {
		k=a[j];
		a[j]=a[j+1];
		a[j+1]=k;
		//	cout<<i<<j<<"   ";
	    }
	    j++;
	}
	i++;
	
    }
    return 0;
}

int main()
{
    int a[n];
    int b[n];
    int i,k,j;
    j=0;
    k=0;
    
    gen_array(a,n);
    
    for(i=0;i<n;i++){
	cout<<" "<<a[i];
    }
    cout<<endl;
    
     sort_array(a,n);

    for(i=0;i<n;i++){
	cout<<" "<<a[i];
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
	if(a[i]%2==1)
	{
	    b[k]=a[i];
	    k++;
	}
	    
    }

    for(i=0;i<k;i++)
    {
	cout<<" "<<b[i];
	j+=b[i];
    }
    cout<<b[0]<<j/k<<b[k-1];
    cout<<endl;

    return 0;
}
