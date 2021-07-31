#include <iostream>
#include <map>

using namespace std;

int main(int argc, char **argv)
{
    int n, l, r;
    cin >> n;
    int *nums = new int[n];
    l = r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (l > nums[i])
            l = nums[i];
        if (r < nums[i])
            r = nums[i];
    }
    int *freq = new int[r - l + 1];
    for (int i = 0; i < r - l + 1; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        freq[nums[i] - l]++;
    }

    while (freq[0] != 0)
    {
        cout << l << " ";
    }

    for (int i = 1; i < r - l + 1; i++)
    {
        while (freq[i] > 0)
        {
            cout << l + i << " ";
            freq[i]--;
        }
    }

    cout << "\n";

    delete[] nums;
    return 0;
}