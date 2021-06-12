#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    unsigned long long int a = (pow(2, 63) - 1);
    cout << log10(a) << endl;
    cout << a % 10 << endl;
    return 0;
}