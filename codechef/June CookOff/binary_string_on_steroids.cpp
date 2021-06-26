#include <iostream>
#include <vector>
using namespace std;

#define INT_INFINITY (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10)

int main(int argc, char **argv)
{
    int t, n, total_zero, total_one, ans;
    string s;
    vector<int> factors;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        total_one = total_zero = 0;
        factors.clear();
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '1')
            {
                total_one++;
            }
            else
            {
                total_zero++;
            }
            if (!(n % i))
            {
                factors.push_back(i);
            }
        }
        ans = INT_INFINITY;
        for (auto factor : factors)
        {
            vector<int> zero(factor, 0), one(factor, 0);
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                    zero[i % factor]++;
                else
                    one[i % factor]++;
            }
            for (int i = 0; i < factor; i++)
            {
                ans = min(ans, zero[i] + (total_one - one[i]));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}