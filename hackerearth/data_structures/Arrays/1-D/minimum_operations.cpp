#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;

#define INT_MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10)
#define INT_MIN (-INT_MAX)
#define ll long long

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int *nums = new int[n];
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // This part uses the stack to get to know the top element
    // stack<int> eles;
    // eles.push(nums[0]);
    // for (int i = 1; i < n; i++)
    // {

    //     if (eles.top() != nums[i])
    //     {
    //         eles.push(nums[i]);
    //     }
    // }

    // This part uses simple array traversal
    for (int i = 0; i < n - 1; i++)
    {
        int j = i;
        while (nums[j] == nums[j + 1])
        {
            j++;
            if (j == n - 1)
            {
                break;
            }
        }
        if (j == n - 1)
            break;
        count++;
        if (i != j)
        {
            i = j;
        }
    }
    count++;
    // cout << eles.size() << "\n"
    cout << count << "\n";
    delete[] nums;
    return 0;
}