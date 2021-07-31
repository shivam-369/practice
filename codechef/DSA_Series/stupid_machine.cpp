// Till now answer is wrong

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int t, n, last_index;
    long long ans = 0, extra;
    cin >> t;
    vector<int> capacity;
    vector<int> index;
    while (t--)
    {
        cin >> n;
        capacity.resize(n);
        index.resize(n);

        last_index = n - 1;
        index[0] = 0;
        extra = ans = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> capacity[i];
            if (i == 0)
                continue;
            index[i] = (capacity[i] < capacity[index[i - 1]] ? i : index[i - 1]);
        }

        while (last_index != 0)
        {
            ans += ((last_index - 0 + 1) * capacity[index[last_index]] - extra * (last_index - 0 + 1));
            // capacity[index[last_index]] = 0;
            extra += (capacity[index[last_index]] - extra);
            last_index = index[last_index] - 1;
        }
        ans += (capacity[0] - extra ? capacity[0] - extra : 0);
        cout << ans << "\n";
    }
    return 0;
}