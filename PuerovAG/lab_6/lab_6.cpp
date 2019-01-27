#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
const int size=100;
const int sizest=1000;
const double p=3.1;
const double e=2.7;

using namespace std;
/*
int elf(int a)
{*/
    
int fact( int a)
{
    int i,b;
    b=1;
    
    if(0>a)
    {
	cout<<"fact dont corect"<<endl;
	exit(1);
    }
    for(i=1;i<a+1;i++)
    {
	b=b*i;

    }
    
    return b;
}
double st(double a ,double b)
{
    int i;
    double c;
    c=1; 
    if(b>0)
    {
	for(i=1;i<b+1;i++)
	    c=a*a;

	return c;
    }
    if(b==0)
	return 1;
    if(0>b)
    {
	for(i=1;i<-b+1;i++)
	    c=c*(1/a);
	return c;
	
    }
    
}

int getline(char s[], int lim)
  {
    int c,i;

    for(i=0;i<lim-1 && (c=getchar()) !=EOF && c != '\n' ; i++)
    {


        s[i] = c;
	
	
	   
    }
    if (c == '\n') {
        s[i] = c;		
	i++;
    }
    s[i] = '\0';
    return i;
  }


	      

int prior(char c)
{
    switch(c)
    {
    case '^':
	return 5;
    case '!':
	return 5;
	
    case '*':
	return 4;
	
    case'/':
	return 4;
	
    case'+':
	return 3;
	
    case'-':
	return 3;
	
    case')':
	return 2;
	
    case'(':
	return 1;
	
    default:
	return 0;

    }
}

void push(char *stack, int s, char c)
{
    memmove(stack + 1, stack , s*(sizeof(char)));
   
    *stack = c;
    
}



void push_d(double *stack, int s, double c)
{
    memmove(stack + 1, stack , s*(sizeof(double)));
   
    *stack = c;
    
}



    
char pop(char *stack, int s)
{
    char c;
    
    c = *stack;
    
    memmove(stack, stack + 1, s*sizeof(char));
	   
    return c;
}



double pop_d(double *stack, int s)
{
    double c;
    
    c = *stack;
    
    memmove(stack, stack + 1, s*sizeof(double));
	   
    return c;
}







int convertropz(char *str_in,char *str_out,char *stack,int str_size) 
{
    int i,k=0;
    char c;
    
    int stack_size=0 ;
   

    for(i = 0; i < str_size; i++)
    {
	c=*(str_in + i);

        
	if(prior(c) == 0 && c !='\n' )
	{
	    *(str_out + k) = c;
	    k++;
	    if((prior(c) == 0) && prior(*(str_in + i +1)))
	    {
		*(str_out + k)=' ';
	    k++;
	    }
	}
	
	if(c=='(')
	{
	    push(stack,stack_size++,c);
	    
	    
	}
	
	if(c==')')
	{
	    while(*stack != '(')
	    {
		*(str_out + k) = pop(stack,stack_size--);
		
		k++;
	    }
	}
	if(prior(c)>2)
	{
	    /* if(prior(*(str_in + i -1)) == 0)
	    {
		*(str_out + k)=c;
		k++;
	    }
	    else */
//	    {
		while(prior(c) <= prior(*stack))
		{
		    *(str_out + k)=pop(stack,stack_size--);
		
		
		
		    k++;
		}
		push(stack,stack_size++,c);
	    
	    	    
	    }
//	}
    
    }
    
    while(stack_size)
    {
	c = pop(stack,stack_size--);
	
	
	if(c !='(')
	{
	    *(str_out + k) = c;
	    
	    k++;
	}
    }
       
    *(str_out + k  ) = '\n';
    return k;    
}



char getop(char s_in[], char s[], int *ind)
{
    int i;
    char c;
    int k = 0;
    
    while ((s[0] = c = s_in[k++]) == ' ' || c == '\t')
    {
	;
    }
    
    
    s[1] = '\0';
    /* if(c=='p')
    {
	return 3.14;
    }
    if(c=='e')
    {
	return 2.7;
    }*/
    if (!isdigit(c) && c != '.')
    {	
	*ind += k;
        return c;    
    }

    
    i = 0;

    if (isdigit(c)) 
        while (isdigit(s[++i] = c = s_in[k++]))
	{
	    ;       
	}

    
    if (c =='.') 
	while (isdigit(s[++i] = c = s_in[k++]))
            ;

    s[i] = '\0';

    
    *ind += (k - 1);
    

    return '0';

}


float calc(char str_out[],double stack[],char s[] ,int size)
{
    
    double tmp, tmp2;
    int k=0;
    float x;
    int  stack_size = 0;
    

    while(getop(str_out + k, s, &k) != '\n'  )
    {
	
	
//	cout<<"stack[0]="<<stack[0]<<endl;
	switch(s[0])
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
//	case 'p':
//	case 'e':
	    x = atof(s);
	    
	    
	    push_d(stack,stack_size++,x) ;
	   
	    break;
	case '-':
	    tmp=pop_d(stack,stack_size--);
	    tmp2 =  pop_d(stack,stack_size--);
	    push_d(stack,stack_size++,tmp2 - tmp);
	    
	    break;
	    
	case'+':
	    tmp=pop_d(stack,stack_size--);
	    tmp2=pop_d(stack,stack_size--);
	    push_d(stack, stack_size++, tmp+tmp2);

	    
	    break;
	case '*':
	    tmp=pop_d(stack,stack_size--);

	    
	    
	    tmp2=pop_d(stack,stack_size--);
	    push_d(stack,stack_size++,tmp2*tmp);
	    
	    break;
		      
	case'/':
	      tmp=pop_d(stack,stack_size--);
	     if(tmp==0)
		
	    {
		cout<<" you div 0"<<endl;
		exit(1);
		return 0;
	    }
	    else
	    {
		//	tmp=pop_d(stack,stack_size--);
		tmp2=pop_d(stack,stack_size--);
		push_d(stack,stack_size++,tmp2/tmp);
	    }
	    break;
	    
	case '!':
	    tmp=pop_d(stack,stack_size--);
	    tmp=fact(tmp);
	    push_d(stack,stack_size++,tmp);
	    break;

	case '^':
	    tmp=pop_d (stack,stack_size--);
	    tmp2=pop_d(stack,stack_size--);
	    tmp=st(tmp2,tmp);
	    push_d(stack,stack_size++,tmp);
	    break;
	    
	case 'p':
	    push_d(stack,stack_size++,p);
	    break;
	case 'e':
	    push_d(stack,stack_size++,e);
	    break;
	default:
	    
	    cout<<"enter correct value"<<endl;
	    
	    exit(1);
         
	}
//	cout<<"stack[0]="<<stack[0]<<endl;
    }
    return stack[0];
}




int main()
{
    char str_in[size];
    char str_out[size];
    char stack[sizest];
    double stack2[sizest];
    char s[size];
    int i,str_size;
    int ind = 0;
    double tmp;
    double res;
   // cout<<"p=3.14 e=2.7"<<endl;

    
    str_size = getline(str_in,size);
    
//    


      str_size =  convertropz(str_in,str_out,stack,str_size);
      
       /*for(i=0;i<str_size;i++)
	{
	    cout<<"str_out[i]="<<str_out[i]<<" ";
	    
	}
	cout<<endl;*/
      
     
      
      

     res =  calc(str_out,stack2,s,str_size);
     cout<<endl;

     cout<<"res ="<<res;

     cout<<endl;


return 0;
}
