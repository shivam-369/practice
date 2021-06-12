#include <iostream>
#include <math.h>
using namespace std;

#define MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7)

int power(long long x, unsigned int y)
{
    int res = 1; // Initialize result

    x = x % MAX; // Update x if it is more than or
                 // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % MAX;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % MAX;
    }
    return res;
}

int main(int argc, char **argv)
{
    int t, n;
    unsigned long long int ans, temp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 1;
        ans = power(2, n - 1);

        cout << ans % MAX << endl;
    }
    return 0;
}