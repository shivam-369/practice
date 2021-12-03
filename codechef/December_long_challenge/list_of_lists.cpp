#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char ** argv)
{
    int t, n, max_freq;
    cin >> t;
    vector < int > a;
    map < int, int > counts;
    while(t--)
    {
        cin >> n;
        a.clear();
        counts.clear();
        a.resize(n, 0);

        max_freq = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            counts[a[i]]++;
        }

        for(auto ptr = counts.begin(); ptr != counts.end(); ptr++)
        {
            if(p->second > max_freq)
            {
                max_freq = p->second;
            }
        }

        if(max_freq <= 1)
        {
            cout << -1 << "\n";
        }else{
            cout << (max_freq % 2) + (n - max_freq) + max_freq / 2 << "\n";
        }
    }

    return 0;
}