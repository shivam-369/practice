#include <iostream>
#include <vector>
using namespace std;

int Greatest_Power_less_than_or_equal(int num)
{
    num = num | (num >> 1);
    num = num | (num >> 2);
    num = num | (num >> 4);
    num = num | (num >> 8);
    num = num | (num >> 16);
    return (num + 1) >> 1;
}

int is_power_of_2(int n)
{
    return n && !(n & (n - 1));
}

int main(int argc, char **argv)
{
    int t, n, count;
    vector<int> num_list;
    cin >> t;
    while (t--)
    {
        cin >> n;
        count = 0;
        num_list.clear();
        if (is_power_of_2(n + 1) && n != 1)
        {
            cout << 0 << "\n";
            continue;
        }
        else if (n == 2)
        {
            cout << 2 << " " << 2 << " " << 1 << "\n";
            continue;
        }
        int temp = Greatest_Power_less_than_or_equal(n);
        int base = temp;
        temp = 0;
        int temp2;
        for (int i = base; i <= n; i++)
        {
            temp ^= i;
        }
        if (temp <= n && temp != 0)
        {
            count++;
            num_list.push_back(temp);
        }
        else if (temp != 0)
        {
            while (temp > n)
            {
                temp2 = Greatest_Power_less_than_or_equal(temp);
                num_list.push_back(temp2);
                temp ^= temp2;
                count++;
            }
            count++;
            num_list.push_back(temp);
        }
        cout << num_list.size() << " ";
        for (int i = 0; i < num_list.size(); i++)
        {
            cout << num_list[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}