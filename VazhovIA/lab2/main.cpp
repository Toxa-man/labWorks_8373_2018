// 2 arrays, size - at least 7
// 1st array - rand(), sort as you wish but using `while`
// 2nd array - odds from 1st array
#include <iostream>
using namespace std;
const int arrSize = 10;
const int maxRand = 30;
int main()
{
    int arrRnd[arrSize];
    int arrSrt[arrSize]={0};
    int min=maxRand, max=0;
    int sum=0;
    cout << "unsorted random array" << endl;
    for (int i=0;i<arrSize;i++)
    {
        arrRnd[i] = rand() % maxRand;
        cout << arrRnd[i] << endl;

        sum += arrRnd[i];
        if (arrRnd[i] < min)
        {
            min = arrRnd[i];
        }
        if (arrRnd[i] > max)
        {
            max = arrRnd[i];
        }
    }

    bool sorted;
    int sortable = 0;
    while (! sorted) //bubble sort
    {
        sorted = true;
        for (int i=0;i<arrSize-1;i++)
        {
            if (arrRnd[i] < arrRnd[i+1])
            {
                sortable = arrRnd[i];
                arrRnd[i] = arrRnd[i+1];
                arrRnd[i+1] = sortable;
                sorted = false;
            }
        }
    }

    int k=0;
    for (int i=0; i<arrSize;i++)
    {
        if (arrRnd[i] % 2 != 0)
        {
            arrSrt[k] = arrRnd[i];
            k++;
        }
    }

    cout << endl << "sorted\todds" << endl;
    for (int i=0;i<arrSize;i++) {
        cout << arrRnd[i] << "\t" << arrSrt[i] << endl;
    }
    cout << "Average: " << sum/arrSize << " Min: " << min << " Maximum: " << max << endl;
    return 0;
}
