#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define INT_MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10)
#define INT_MIN (-INT_MAX)
#define ll long long

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, k, m, ans;
    ll num;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> m >> k;
        cin >> s;

        if (s[0] == '0')
        {
            s = s.substr(1, m);
        }
        // if (s.length() < 1)
        // {
        //     cout << "no string\n";
        //     continue;
        // }
        cout << "first call\n";
        cout << s << " this is string\n";
        num = stoi(string(s));
        cout << "first call ended\n";
        ans = num % k;
        for (int i = 0; i < s.length(); i++)
        {
            cout << s.substr(0, i) + s.substr(i + 1, s.length()) << "\n";
            num = stoi(s.substr(0, i) + s.substr(i + 1, s.length()));
            if (num % k > ans)
            {
                ans = num % k;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}