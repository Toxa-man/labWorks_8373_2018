// 2 arrays, size - at least 7
// 1st array - rand(), sort as you wish but using `while`
// 2nd array - odds from 1st array
#include <iostream>
using namespace std;
const int arrSize = 10;
const int maxRand = 10;
int main()
{
    int arr1[arrSize];
    int arr2[arrSize]={0};
    cout << "unsorted array" << endl;
    for (int i=0;i<arrSize;i++)
    {
        arr1[i] = rand() % maxRand;
        cout << arr1[i] << endl;
    }

    bool sorted;
    int sortable = 0;
    while (! sorted) //bubble sort
    {
        sorted = true;
        for (int i=0;i<arrSize-1;i++)
        {
            if (arr1[i] < arr1[i+1])
            {
                sortable = arr1[i];
                arr1[i] = arr1[i+1];
                arr1[i+1] = sortable;
                sorted = false;
            }
        }
    }

    int k=0;
    for (int i=0; i<arrSize;i++)
    {
        if (arr1[i] % 2 != 0)
        {
            arr2[k] = arr1[i];
            k++;
        }
    }

    cout << endl << "sorted\todds" << endl;
    for (int i=0;i<arrSize;i++) {
        cout << arr1[i] << "\t" << arr2[i] << endl;
    }
    return 0;
}
