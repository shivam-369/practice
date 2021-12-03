#include <iostream>
#include <math.h>
using namespace std;

int modulo_search(int n, int p, int k)
{
    int target = p % k;
    int remainder = n % k;
    int ans = 0;
    int curr_remain = 0;
    while (curr_remain != target)
    {
        ans += n / k;
        if (curr_remain <= remainder)
            ans += 1;

        curr_remain++;
    }

    curr_remain = target;
    while (curr_remain < p)
    {
        ans += 1;
        curr_remain += k;
    }

    return ans;
}

int main(int argc, char **argv)
{
    int t, n, p, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> p >> k;

        cout << modulo_search(n, p, k) << "\n";
    }

    return 0;
}