#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int t, n, a, b, type1, type2;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        cin >> s;
        type1 = type2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                type1++;
            else
                type2++;
        }

        cout << a * type1 + b * type2 << "\n";
    }
    return 0;
}