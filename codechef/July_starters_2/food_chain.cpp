#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char **argv)
{
    long long int t, e, k, ans;
    cin >> t;
    while (t--)
    {
        cin >> e >> k;
        ans = 0;
        while (e > 0)
        {
            ans++;
            e /= k;
        }
        cout << ans << "\n";
    }
    return 0;
}