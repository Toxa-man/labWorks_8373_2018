#include <iostream>
//#include <string.h>
using namespace std;
int main()
{
float a,b;
char c;
cout << "число1:";
cin >> a;
cout << "операция:";
cin >> c;
cout << "число2:";
cin >> b;

switch(c)
  {
  case '+':
      cout << a+b;
    break;
  case '-':
      cout << a-b;
    break;
  case '*':
      cout<<a*b;
    break;
  case'/':
    if (b==0)
	cout << "нельзя делить на 0";
    else cout << a/b;
    break;
    
  default:
      break;
  }
cout<<endl;
return 0;
}

