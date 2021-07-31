#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char ** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int t, n, q, l, r, odds, evens; 
    long long int ans;   
    cin >> t;
    
    while(t--)
    {
        cin >> n >> q;
        vector < long long int > nums(n);
        vector < long long int > oddCount(n);
        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        if(nums[0] % 2)
            oddCount[0] = 1;
        else
            oddCount[0] = 0;
        
        for(int i = 1; i < n; i++)
        {
            if(nums[i] % 2)
            {
                oddCount[i] = oddCount[i - 1] + 1;
            }else{
                oddCount[i] = oddCount[i - 1];
            }
        }

        while(q--)
        {
            cin >> l >> r;
            ans = 0;
            odds = oddCount[r - 1] - oddCount[l - 1] + (nums[l - 1] % 2);
            evens = r - l + 1 - odds;

            ans += (((odds * (odds - 1)) / 2) * evens);

            ans += ((evens * (evens - 1) * (evens - 2)) / 6);

            cout << ans << "\n";
        }
    }
    return 0;
}