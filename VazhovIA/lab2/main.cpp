// 2 arrays, size - at least 7
// 1st array - rand(), sort as you wish but using `while`
// 2nd array - odds from 1st array
#include <iostream>
using namespace std;
const int arrSize = 10;
const int maxRand = 50;
int main()
{
    int arrRnd[arrSize]={0};
    int arrSrt[arrSize]={0};
    int min=maxRand, max=0;
    int sum=0;
    cout << "unsorted random array" << endl;
    //generated
    for (int i=0;i<arrSize;i++)
    {
        arrRnd[i] = rand() % maxRand;
        cout << arrRnd[i] << endl;
    }
    //sorted
    int i = 0;
    while (i < arrSize)
    {
        if (arrRnd[i] < arrRnd[i+1])
        {
            int tmp = arrRnd[i+1];
            arrRnd[i+1] = arrRnd[i];
            arrRnd[i] = tmp;
            i = 0;
        } else
        {
            i++;
        }

    }
    //odds
    int k=0;
    for (int i=0; i<arrSize;i++)
    {
        if (arrRnd[i] % 2 != 0)
        {
            arrSrt[k] = arrRnd[i];
            if (arrSrt[k] < min)
            {
                min = arrSrt[k];
            }
            if (arrSrt[k] > max)
            {
                max = arrSrt[k];
            }
            sum += arrSrt[k];
            k++;
        }
    }

    cout << endl << "sorted\todds" << endl;
    for (int i=0;i<arrSize;i++) {
        cout << arrRnd[i] << "\t" << arrSrt[i] << endl;
    }
    cout << "Average: " << sum/k << " Min: " << min << " Maximum: " << max << endl;
    return 0;
}
