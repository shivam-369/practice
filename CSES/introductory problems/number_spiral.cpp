#include <iostream>
using namespace std;
int main()
{
    long long int t, y, x;
    unsigned long long ans;
    cin >> t;
    while (t--)
    {
        cin >> y >> x;
        if (y % 2 != 0)
        {
            if (y >= x)
            {
                ans = (y - 1) * (y - 1) + x;
            }
            else if (x % 2 != 0 && x > y)
            {
                ans = x * x + 1 - y;
            }
            else if (x % 2 == 0 && x > y)
            {
                ans = (x - 1) * (x - 1) + y;
            }
        }
        else
        {
            if (y >= x)
            {
                ans = y * y - x + 1;
            }
            else if (x % 2 != 0 && x > y)
            {
                ans = x * x + 1 - y;
            }
            else if (x % 2 == 0 && x > y)
            {
                ans = (x - 1) * (x - 1) + y;
            }
        }
        cout << ans << endl;
    }
    return 0;
}