#include <iostream>

#define INT_MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10)
#define INT_MIN (-INT_MAX)

using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    int max = INT_MIN;
    int min = INT_MAX;
    int *nums = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (nums[i] > max)
        {
            max = nums[i];
        }
        if (nums[i] < min)
        {
            min = nums[i];
        }
    }
    cout << max << " " << min << "\n";
    delete[] nums;
    return 0;
}