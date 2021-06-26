// for very few test cases getting wrong answers

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n, k, temp;
    map<long long int, long long int> freq;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int *nums = new int[n];
        freq.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        sort(nums, nums + n);
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (nums[i + 1] == nums[i])
            {
                i++;
            }
            freq[nums[i]] = i - j + 1;
        }
        delete[] nums;
        vector<long long int> sums;

        // inserting total value of a integer in sums vector
        for (auto ptr = freq.begin(); ptr != freq.end(); ptr++)
        {
            sums.push_back((ptr->first) * (ptr->second));
        }

        // sorting the sums of individual value
        sort(sums.begin(), sums.end(), greater<long long int>());

        unsigned long long int sum = 0;

        // finding sum of first k numbers with non-negative values
        for (int i = 0; i < k; i++)
        {
            if (sums[i] >= 0)
            {
                sum += sums[i];
            }
            else
            {
                break;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}