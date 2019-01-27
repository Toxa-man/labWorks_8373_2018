
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


int st(int a,int c)
{
    int i,b;
    if(a>0)
    {
	for(i=1;i<c+1;i++)
	{
	    a=a*a;
	}
    }
    else if(a=0)
    {
	a=1;
    }
    else if(a<0)
    {
	for(i=1;i<c+1;i++)
	{
	    b=1;
	    b=(1/a)*b;
	}
    }
    return a;
}


float sq(int a)
{
    float t,k;
    k=a/2;
   do
    {
	t=k;
	k=(t+(a/t))/2;
    }while((t-k)!=0);
	
    return k ;
    
}


bool  prp(int a)
{
    int i;
    bool k=false;
    
    for(i=1;i<a;i++)
    {
	if(a%i==0)
	    {
		k=true;
	    }
    }
    return k;
}




int main()
{
    int n,i,a;
    
    cin>>a>>n;
    
    cout<<"fact="<< fact(a)<<endl;
    
    cout<<"st="<<st(a,n)<<endl;
    
    cout <<"sq="<<sq(a)<<endl;
    
    cout<<"prp="<<prp(a)<<endl;
    

    return 0;
    
}

