#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<int> factors;
    map<int, int> freq_count;
    int *nums = new int[n / 2 + 1];
    nums[0] = nums[1] = -1;
    for (int i = 2; i <= n / 2 + 1; i++)
    {
        nums[i] = 0;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (nums[i])
            continue;
        for (int j = 2; i * j <= n / 2; j++)
        {
            nums[i * j]++;
        }
    }
    for (int i = 2; i <= n / 2 + 1; i++)
    {
        if (nums[i] == 0)
        {
            if (!(n % i))
            {
                factors.push_back(i);
                int temp = n / i;
                freq_count[i] = 1;
                while (!(temp % i))
                {
                    freq_count[i]++;
                    temp = temp / i;
                }
            }
        }
    }
    if (factors.size() != 0)
    {
        for (int factor : factors)
        {
            cout << factor << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << n << "\n";
        freq_count[n] = 1;
    }
    for (auto ptr = freq_count.begin(); ptr != freq_count.end(); ptr++)
    {
        while (ptr->second)
        {
            cout << ptr->first << " ";
            (ptr->second)--;
        }
    }
    return 0;
}