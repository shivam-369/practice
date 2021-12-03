#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

int main(int argc, char **argv)
{
    int t, n, k, steps = 0, remainder;
    cin >> t;
    vector<int> mons;
    set<int> types;
    map<int, int> counts;
    while (t--)
    {
        cin >> n >> k;
        steps = 0;
        remainder = 0;
        types.clear();
        counts.clear();
        mons.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> mons[i];
            types.insert(mons[i]);
            // counts[mons[i]]++;
            if (counts.find(mons[i]) != counts.end())
            {
                counts[mons[i]]++;
            }
            else
            {
                counts[mons[i]] = 1;
            }
        }

        for (int type : types)
        {
            // if (remainder >= k)
            // {
            //     steps += (remainder / k);
            //     remainder %= k;
            // }
            if (counts[type] >= k)
            {
                steps++;
            }
            else
            {
                remainder += counts[type];
            }
        }
        steps += ceil(float(remainder) / float(k));
        cout << steps << "\n";
    }
    return 0;
}