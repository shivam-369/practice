#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define mod (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7)
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 2;
        // dp[2] = 8;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = (dp[i] % mod + (dp[j] % mod * dp[i - j] % mod) % mod) % mod;
            }
            // dp[i] = dp[i] % mod +
        }
        cout << dp[n] << endl;
    }

    return 0;
}