#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv)
{
    int t, k, n, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> k;
        if (x % k == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        else if (abs(x - n - 1) % k == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }

    return 0;
}