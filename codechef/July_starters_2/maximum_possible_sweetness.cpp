// Till now solution is incomplete (TLE)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool compare(long long a, long long b)
{
    return a > b;
}

int main(int argc, char **argv)
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    long long int n, d, data;
    long long sweetness, temp_ans;
    cin >> t;
    map<long long, vector<long long>> sweet;
    vector<pair<long long, long long>> temp;
    vector<long long> ans;
    while (t--)
    {
        cin >> n >> d;
        temp.resize(n);
        sweet.clear();
        ans.clear();
        sweetness = 0;
        temp_ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> temp[i].first;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> temp[i].second;
        }
        for (int i = 0; i < n; i++)
        {
            sweet[temp[i].first].push_back(temp[i].second);
        }

        for (auto ptr = sweet.begin(); ptr != sweet.end(); ptr++)
        {
            // cout << "sorting\n";
            sort((*ptr).second.begin(), (*ptr).second.end(), compare);
        }

        // for (auto ptr = sweet.begin(); ptr != sweet.end(); ptr++)
        // {
        //     cout << (*ptr).first << " ";
        // }
        // cout << "\n";
        // cout << "outside sorting\n";
        for (auto ptr = sweet.begin(); ptr != sweet.end(); ptr++)
        {
            auto ptr2 = sweet.begin();
            ptr--;
            temp_ans = 0;

            while ((*ptr2).first <= d - (*ptr).first && ptr2 != sweet.end())
            {
                cout << "inside while\n";
                temp_ans = max(temp_ans, (*ptr).second[0] + (*ptr2).second[0]);
                ptr2++;
            }

            ans.push_back(temp_ans);
        }

        // for (int i = 0; i < ans.size(); i++)
        // {
        //     if (sweetness < ans[i])
        //         sweetness = ans[i];
        // }

        // cout << sweetness << "\n";
    }
    return 0;
}