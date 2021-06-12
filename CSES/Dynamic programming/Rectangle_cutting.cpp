#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7)
int main()
{
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, MAX));
    for (int i = 1; i <= b; i++)
    {
        dp[1][i] = i - 1;
    }
    for (int i = 1; i <= a; i++)
    {
        dp[i][1] = i - 1;
    }
    for (int i = 0; i <= min(a, b); i++)
    {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
            }
            for (int k = 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}