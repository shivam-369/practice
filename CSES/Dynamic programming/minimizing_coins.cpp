#include <iostream>
#include <vector>
using namespace std;
#define MAX 10000000


int main()
{
    int n, x;
    cin >> n >> x;
    vector < int> dp(x + 1,  MAX);
    dp[0] = 0;
    int *coins = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
        // dp[coins[i]] = 1;
    }
    for(int i = 1; i <= x; i++)
    {
        for(int j = 0; j < n; j++)
        {   if (i < coins[j]) continue;
            dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    if(dp[x] == MAX) {cout << -1 << endl;}
    else
    {
        cout << dp[x] << endl;
    }
    
    
    return 0;
}