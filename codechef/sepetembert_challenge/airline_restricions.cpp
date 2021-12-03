#include <iostream>
using namespace std;

int main(int argc, char **argv)
{

    int t, a, b, c, d, e;
    bool ans1, ans2;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> d >> e;
        ans1 = ans2 = false;

        if (a + b <= d)
        {
            ans1 = true;
            if (c <= e)
                ans2 = true;
        }
        if (!(ans1 && ans2))
        {
            if (b + c <= d)
            {
                ans1 = true;
                if (a <= e)
                    ans2 = true;
            }
        }
        if (!(ans1 && ans2))
        {
            if (a + c <= d)
            {
                ans1 = true;
                if (b <= e)
                    ans2 = true;
            }
        }
        if (ans1 && ans2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}