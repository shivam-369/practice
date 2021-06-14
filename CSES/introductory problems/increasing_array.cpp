#include <iostream>
using namespace std;
int main()
{
    int n;
    long turns = 0;
    cin >> n;
    int *array = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for(int i = 1; i < n; i++)
    {
        if(array[i] >= array[i - 1]){
            continue;
        }
        turns += (array[i - 1] - array[i]);
        array[i] += (array[i - 1] - array[i]);
    }

    cout << turns << endl;
    return 0;
}