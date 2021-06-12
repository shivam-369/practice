#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

const long mod = pow(10, 9) + 7; 

long ways(int n, vector < long >  & dp)
{
    long ans = 0;
    if(dp[n] != 0)
    {
        return dp[n];
    }
    for(int i = 1; i <= 6; i++)
    {
        if(n - i >= 0)
        {
            ans = (ans % mod + ways(n - i, dp) % mod) % mod;
        }else{ break;}
    }
    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector < long > dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    dp[2] = 2; 
    long ans = ways(n, dp);
    cout << ans << endl;

    return 0;
}