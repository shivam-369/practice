#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    int n, x;
    cin >> n >> x;
    vector < int > price(n + 1, 0);
    vector < int > page(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >>page[i];
    }
    vector < vector < int > > dp(n + 1, vector < int> (x + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<= x; j++)
        {
            if(price[i] > j) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], page[i] + dp[i - 1][j - price[i]]);
        }
    }
     cout << dp[n][x] << endl;

    return 0; 
}