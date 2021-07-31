#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    vector<int> nums(n);
    stack<int> great_frequency;
    map<int, int> frequency;
    vector<int> great_freq_eles(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (frequency.find(nums[i]) != frequency.end())
            frequency[nums[i]]++;
        else
            frequency[nums[i]] = 1;
    }

    great_frequency.push(0);
    for (int i = 1; i < n; i++)
    {
        while (frequency[nums[i]] > frequency[nums[great_frequency.top()]])
        {

            int temp_index = great_frequency.top();
            great_frequency.pop();
            great_freq_eles[temp_index] = nums[i];
            if (great_frequency.empty())
                break;
        }
        great_frequency.push(i);
    }

    for (int freq : great_freq_eles)
    {
        cout << freq << " ";
    }
    cout << endl;
    return 0;
}