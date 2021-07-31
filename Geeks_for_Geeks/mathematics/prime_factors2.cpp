#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    while (!(n % 2))
    {
        cout << 2 << " ";
        n /= 2;
    }
    for (int j = 3; j <= sqrt(n); j += 2)
    {
        while (!(n % j))
        {
            cout << j << " ";
            n /= j;
        }
    }
    if (n > 2)
    {
        cout << n << " ";
    }
    cout << "\n";
    return 0;
}