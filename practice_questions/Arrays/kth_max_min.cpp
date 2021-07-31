#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
    int n, k;
    cin >> n >> k;
    int *nums = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    cout << nums[k - 1] << " " << nums[n - k];
    delete[] nums;
    return 0;
}