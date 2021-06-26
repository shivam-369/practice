#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char **argv)
{
    int t, n, m, ans;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        ans = 0;
        string s;
        while (n--)
        {
            cin >> s;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '0')
                {
                    ans ^= 0;
                }
                else
                {
                    ans ^= 1;
                }
            }
        }
        if (ans == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}