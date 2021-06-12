#include <iostream>
#include <vector>
using namespace std;
#define mod (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7)
int main()
{
    int n, m;
    unsigned long long int count = 0;
    cin >> n >> m;
    int *array = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> array[i];
    }
    vector<vector<long long int>> dp(m + 1, vector<long long int>(n + 1, 0));

    if (array[1] != 0)
    {
        dp[array[1]][1] = 1;
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            dp[i][1] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (array[i] != 0)
        {
            dp[array[i]][i] = (dp[array[i] - 1][i - 1] % mod + dp[array[i]][i - 1] % mod + (array[i] < m ? dp[array[i] + 1][i - 1] : 0) % mod);
            // cout << "inside if " << endl;
            // cout << array[i] << " " << i << " " << dp[array[i]][i] << endl;
            continue;
        }

        for (int j = 1; j <= m; j++)
        {
            dp[j][i] = (dp[j - 1][i - 1] % mod + dp[j][i - 1] % mod + (j < m ? dp[j + 1][i - 1] : 0) % mod);

            // cout << j << " " << i << " " << dp[j][i] << endl;
        }
        // dp[m][i] += (dp[m][i - 1] + dp[m - 1][i - 1]);
    }
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if (array[n] != 0)
    {
        cout << dp[array[n]][n] << endl;
    }
    else
    {
        for (int i = 0; i <= m; i++)
        {
            count += (dp[i][n] % mod);
            count %= mod;
        }
        cout << count << endl;
    }

    return 0;
}