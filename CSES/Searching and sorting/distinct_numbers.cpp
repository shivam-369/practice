#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, distinct = 1;
    cin >> n;
    int *nums = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            distinct++;
        }
    }
    cout << distinct << endl;
    delete[] nums;
    return 0;
}