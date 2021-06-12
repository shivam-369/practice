#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<long long>> dp(s1.size() + 1, vector<long long>(s2.size() + 1, 0));
    for (int i = 1; i <= s1.size(); i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= s2.size(); i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]);
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}