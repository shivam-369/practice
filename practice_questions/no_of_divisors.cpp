#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    map<int, int> factor_freq;
    if (n <= 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    if (n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    if (n % 2 == 0)
        factor_freq[2] = 0;

    while (!(n % 2))
    {
        factor_freq[2]++;
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i)
            continue;
        factor_freq[i] = 0;
        while (!(n % i))
        {
            factor_freq[i]++;
            n /= i;
        }
    }
    if (factor_freq.size() == 0 || n > 2)
        factor_freq[n] = 1;

    long long ans = 1;

    for (auto factor : factor_freq)
    {
        ans *= (factor.second + 1);
    }
    cout << ans << '\n';
    return 0;
}