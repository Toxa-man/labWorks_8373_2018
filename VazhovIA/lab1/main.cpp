#include <iostream>
#include <cmath>

#ifdef __linux__
#include <termios.h>
#elif _WIN32
#include <conio.h>
#endif

using namespace std;
static struct termios oldSetts, nwSetts;

void initTermios()
{
  tcgetattr(0, &oldSetts);
  nwSetts = oldSetts;
  nwSetts.c_lflag &= ~ICANON;
  nwSetts.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &nwSetts);
}

void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &oldSetts);
}

char getch_() 
{
  char ch;
  initTermios();
  ch = getchar();
  resetTermios();
  return ch;
}

int main()
{
    float left, right, result;
    char sign;
    cout << "Enter expression, e.g. 2+2" << endl;
    cin >> left >> sign >> right;

    switch (sign)
    {
    case '+':
        result = left + right;
        break;
    case '-':
        result = left - right;
        break;
    case '*':
        result = left * right;
        break;
    case '/':
        if (right == 0) {
            cout << "Division by zero is forbidden" << endl;
            #ifdef __linux__
            cin.ignore(1,'\n');
            char a = getch_();
            #elif _WIN32
            _getch();
            #endif
            exit(2);
            break;
        }
        result = left / right;
        break;
    default:
        cout << "Wrong sign" << endl;
        return 1;
        break;
    }
    cout << result << endl;
    #ifdef __linux__
    cin.ignore(1,'\n');
    char a = getch_();
    #elif _WIN32
    _getch();
    #endif
    return 0;
}
