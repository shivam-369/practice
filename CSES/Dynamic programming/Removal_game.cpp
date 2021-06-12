#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *scores = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }
    vector<vector<long long int>> dp(n + 1, vector<long long>(n + 1, 0));
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            long long int j = i + len - 1;
            long long int x, y, z;
            x = (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0);
            y = (i + 2 <= j ? dp[i + 2][j] : 0);
            z = (i <= j - 2 ? dp[i][j - 2] : 0);
            dp[i][j] = max(scores[i] + min(x, y), scores[j] + min(x, z));
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}