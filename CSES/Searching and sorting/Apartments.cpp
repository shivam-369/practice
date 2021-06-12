#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define ll long long
int main()
{
    ll n, m, k, count = 0;
    cin >> n >> m >> k;
    ll *desired = new ll[n];
    ll *actual = new ll[m];
    for (int i = 0; i < n; i++)
    {
        cin >> desired[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> actual[i];
    }
    sort(desired, desired + n);
    sort(actual, actual + m);
    ll i, j;
    i = j = 0;
    while (i < n and j < m)
    {
        if (abs(desired[i] - actual[j]) <= k)
        {
            count += 1;
            i++;
            j++;
        }
        else if (desired[i] > actual[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << count << endl;
    return 0;
}