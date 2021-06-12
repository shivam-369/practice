#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ll n, x, count = 0;
    cin >> n >> x;
    ll *weights = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    sort(weights, weights + n);
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (weights[i] + weights[j] <= x)
        {
            count++;
            i++;
            j--;
        }
        else
        {
            count++;
            j--;
        }
    }
    if (i == j)
    {
        count++;
    }
    cout << count << endl;
    return 0;
}
