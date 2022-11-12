#include <iostream>
#include"Merge.h"

using namespace std;

int main()
{
    int massive[] = { 1,3,5,7,9,2,4,6,8,0 };
    int massive_h[] = { 1,3,5,7,9,2,4,6,8,0 };

    for (int i = 0; i < sizeof(massive) / sizeof(int); i++) cout << massive[i] << " ";
    cout << endl;

    MergeSort(massive, massive_h, 0, 9);

    for (int i = 0; i < sizeof(massive) / sizeof(int); i++) cout << massive[i] << " ";
    cout << endl;

}

