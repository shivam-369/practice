#include <iostream>
#include <vector>
using namespace std;
#define MAX (10*10*10*10*10*10*10*10*10 + 7)

int main()
{
    int n, x;
    cin >> n >> x;
    int * coins = new int[n];
    vector < int > dp(x + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    for(int j = 0; j < n; j++)
    {
        for(int i = 1; i <= x; i++)
        {
            if(i < coins[j]) continue;
            dp[i] = (dp[i] % MAX + dp[i - coins[j]] % MAX) % MAX;
        }
    }
    cout << dp[x] << endl;
    return 0;
}