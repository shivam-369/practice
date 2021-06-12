#include <iostream>
#include <vector>
using namespace std;

#define MAX (10*10*10*10*10*10*10*10*10 + 7)


int ways(int row, int col, int n, vector < int > &dp, char ** grid)
{   
    if(row >= n or col >= n)
    {
        return 0;
    }
    if(dp[row * n + col] != -1)
    {
        return dp[row * n + col];
    }
    int way = 0;
    way = (way % MAX + ways(row , col + 1 , n, dp, grid) % MAX)% MAX; 
    way = (way % MAX + ways(row + 1, col, n, dp, grid) % MAX)% MAX; 
    dp[row * n + col] = way;
    return way;
}


int main()
{
    int n;
    cin >> n;
    char ** grid = new char *[n];
    vector < int > dp(n * n, -1);
    // dp[0] = 0;
    dp[n * n - 1] = 1;
    for(int i = 0; i < n; i++)
    {
        grid[i] = new char[n];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == '*')
            {
                dp[i * n + j] = 0;
            }
        }
    }
    // cout << dp[(n - 1) * (n - 1)] << endl;
    cout << ways(0, 0, n, dp, grid) << endl;
    
    for(int i = 0; i < n; i++)
    {
        delete[] grid[i];
    }
    return 0;
}