#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    stack<int> eles;
    vector<int> nums(n);
    vector<int> great_element(n, -1);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    eles.push(0);

    int index = 1;
    while (index < n)
    {
        if (nums[index] > nums[eles.top()])
        {
            while (nums[eles.top()] < nums[index])
            {
                int temp_index = eles.top();
                eles.pop();
                great_element[temp_index] = nums[index];
                if (eles.empty())
                    break;
            }
                }
        eles.push(index);
        index++;
    }

    for (auto num : great_element)
    {
        cout << num << " ";
    }
    cout << "\n";
    return 0;
}