#include<iostream>


using namespace std;

int fact(int n)
{
    int i;
    int b;
    b=1;
    for(i=1;i<n+1;i++)
    {
	b=b*i;
    }
    return b;
}


float st(int a,int c)
{
    int i;
	int k;
	k = 1;
	if (c == 0)
		return 1;
	
	if (c > 0)
	{
		for (i = 1; i < c + 1; i++)
			a = a * a;
		return a;
		
	}
	if(0>c)
	{
		for (i = 1; i < -c + 1; i++)
			k = (1 / a);
		return k;
	}
    return a;
}


float sq(int a)
{
    return 1+((a-1)/2)-((a-1)*(a-1)/4);
}


int prp(int a)
{
    int k,i;
    k=0;
    for(i=0;i<a;i++)
    {
	if(a%i==0)
	    {
		k=1;
	    }
    }
    return k;
}




int main()
{
    int n,i,a;
    
    cin>>a>>n;
    
    cout<< fact(a)<<endl;
    
    cout<<st(a,n)<<endl;
    
    cout <<sq(a)<<endl;
    
    cout<<prp(a)<<endl;
    

    return 0;
    
}
