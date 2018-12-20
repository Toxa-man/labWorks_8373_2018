#include<iostream>


using namespace std;


int main()
{
    int a;
    int b;
    char c;

    cin>>a;
    
    cin>>c;
    
    cin>>b;

    switch(c)
    {
    case '+':
	cout<<a+b;
	break;
    case '-':
	cout<<a-b;
	break;
    case '*':
	cout<<a*b;
	break;
    case'/':
	if (b==0)
	    cout<<"its impossible";
	else
	    cout<<a/b);
	break;
    default:
	cout<<"enter correct sign";
    }
    return 0;
}
