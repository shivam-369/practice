#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int t, a, b;
    cin >> t;
    long long int max_limit, min_limit;
    long long ans;
    while (t--)
    {
        cin >> a >> b;
        min_limit = min(a, b);
        max_limit = max(a, b);

        if (a == b)
        {
            ans = 0;
        }
        else if (b > a)
        {
            ans = (b - a) / 2 + 1;
        }
        else
        {
            if ((a - b) % 2)
                ans = (b - a) / 2;
            else
                ans = (b - a) / 2 + 1;
        }

        cout << ans << "\n";
    }
    return 0;
}