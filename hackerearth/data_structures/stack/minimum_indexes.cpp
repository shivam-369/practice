#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int sumOfDigits(int n)
{
    int sum = 0, digit;
    while (n > 0)
    {
        digit = n % 10;
        sum += digit;
        n /= 10;
    }

    return sum;
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, query_index;
    stack<int> s1, s2;
    cin >> n >> q;

    vector<int> ans(n, -1);
    int *nums = new int[n];

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    s1.push(0);

    for (int i = 1; i < n; i++)
    {
        while (nums[s1.top()] > nums[i])
        {
            s2.push(s1.top());
            s1.pop();
            if (s1.empty())
                break;
        }

        while (!s2.empty())
        {
            if (sumOfDigits(nums[s2.top()]) < sumOfDigits(nums[i]))
                ans[s2.top()] = i;
            else
                s1.push(s2.top());

            s2.pop();
        }

        s1.push(i);
    }

    while (q--)
    {
        cin >> query_index;
        cout << ans[query_index] << "\n";
    }

    delete[] nums;
    return 0;
}