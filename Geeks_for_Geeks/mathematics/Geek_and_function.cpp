#include <iostream>
using namespace std;

int func(int n)
{
    return n ^ (n % 10);
}

int main()
{
    //code
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (n % 10 == 0)
        {
            k = 0;
        }
        for (int i = 0; i < k; i++)
        {
            if (n < 10)
            {
                n = 0;
                break;
            }
            else if (n % 10 == 0)
            {
                k = 0;
            }
            n = func(n);
        }
        cout << n << "\n";
    }
    return 0;
}