#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX (10*10*10*10*10*10*10*10*10 + 7)

vector < short > digitise(int n)
{   
    short rmdr;
    vector < short > digits;
    while(n > 0)
    {
        rmdr = n % 10;
        n = n / 10;
        if( rmdr != 0 && find(digits.begin(), digits.end(), rmdr) == digits.end())
        {
            digits.push_back(rmdr);
        }
    }
    return digits;
}


int steps(int n, vector < int > &dp)
{
    vector < short > digits = digitise(n);
    int step = MAX;
    if(dp[n] != 0 or n == 0)
    {
        return dp[n];
    }
    for(int i = 0; i < digits.size(); i++)
    {
        step = min(step, 1 + steps(n - digits[i] , dp));
    }
    dp[n] = step;
    return step;
}

int main()
{
    int n;
    cin >> n;
    vector < int > dp(n + 1, 0);
     cout << steps(n, dp) << endl; 
    //  cout << dp[n] << endl;
    // vector < short > digits = digitise(n);
    // for(int i = 0; i < digits.size(); i++)
    // {
    //     cout << digits[i] << endl;
    // }
    // cout << digits.size() << endl;
    return 0;
}