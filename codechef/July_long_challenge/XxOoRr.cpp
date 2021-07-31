#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int max_power_two(int n)
{
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);
    return (n + 1) / 2;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n, k, max, max_power, bit_count, ans = 0;
    vector<int> counts(32, 0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        counts.assign(32, 0);
        int *a = new int[n];
        ans = max = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > max)
                max = a[i];
        }
        max_power = max_power_two(max);
        bit_count = log2(max_power) + 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= bit_count; j++)
            {
                if (a[i] & (1 << j))
                {
                    counts[j]++;
                }
            }
        }
        for (int i = 0; i < 32; i++)
        {
            ans += (ceil(float(counts[i]) / float(k)));
        }
        cout << ans << "\n";
        delete[] a;
    }
    return 0;
}