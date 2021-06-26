#include <iostream>
#include <math.h>
using namespace std;

#define ll long long
#define INT_MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10)
#define INT_MIN (-(10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10))

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    ll n, k, count;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int *nums = new int[n];
        ll sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            sum += nums[i];
        }
        cout << ((sum / (k + 1) - n + 1) > 0 ? sum / (k + 1) - n + 1 : 0) << "\n";
        delete[] nums;
    }
    return 0;
}