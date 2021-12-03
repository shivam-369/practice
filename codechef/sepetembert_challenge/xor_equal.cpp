#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char **argv)
{
    int t, n, x, max_freq, max_freq_val, ops;
    int first_count = 0, second_count = 0, count;
    cin >> t;
    vector<int> a;
    map<int, int> values;

    while (t--)
    {
        cin >> n >> x;
        a.clear();
        a.resize(n);
        max_freq = 0;
        ops = INT32_MAX;
        values.clear();
        count = first_count = second_count = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            values[a[i]]++;
            values[x ^ a[i]]++;
        }

        for (auto ptr = values.begin(); ptr != values.end(); ptr++)
        {
            if ((*ptr).second > max_freq)
            {
                max_freq = (*ptr).second;
                max_freq_val = (*ptr).first;
            }
            else if ((*ptr).second == max_freq)
            {
                first_count = 0;
                second_count = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] == max_freq_val)
                        first_count++;
                    else if (a[i] == (*ptr).first)
                        second_count++;
                }

                max_freq_val = first_count > second_count ? max_freq_val : (*ptr).first;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == max_freq_val)
                count++;
        }
        cout << max_freq << " " << (max_freq - count) << "\n";
    }
    return 0;
}