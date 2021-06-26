#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int n, q, val;
    cin >> n >> q;
    vector<int> roots(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> roots[i];
    }
    sort(roots.begin(), roots.end());
    while (q--)
    {
        cin >> val;
        auto index = lower_bound(roots.begin(), roots.end(), val);
        if (*index == val)
        {
            cout << "0\n";
        }
        else
        {
            if ((roots.end() - index) % 2)
            {
                cout << "NEGATIVE\n";
            }
            else
            {
                cout << "POSITIVE\n";
            }
        }
    }

    return 0;
}