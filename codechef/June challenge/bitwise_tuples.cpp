#include <iostream>
using namespace std;

#define MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7)

long long int power(long long int x, long long int y)
{
    long long int ans = 1;
    if (y == 0)
        return 1;
    else
        y %= MAX;
    x %= MAX;
    while (y > 0)
    {
        if (y % 2)
        {
            ans = (ans % MAX) * (x % MAX) % MAX;
        }
        y >>= 1;
        x = (x % MAX) * (x % MAX) % MAX;
    }
    return ans;
}

long long int power(int y)
{
    long long int ans = 1;
    long long int x = 2;
    if (y == 0)
        return ans;
    else
        y %= MAX;
    while (y > 0)
    {
        if (y % 2)
        {
            ans = ((ans % MAX) * x) % MAX;
        }
        y = y >> 1;
        x = ((x % MAX) * (x % MAX)) % MAX;
    }
    return ans;
}

int main(int argc, char **argv)
{
    int t, n, m;
    cin >> t;
    long long int max_limit;
    while (t--)
    {
        cin >> n >> m;
        max_limit = power(n) % MAX - 1;
        cout << power(max_limit, m) << endl;
    }
    return 0;
}