#include <iostream>

using namespace std;

template <typename T>
void swap_vals(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    int *nums = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < (n / 2); i++)
    {
        swap_vals(nums[i], nums[n - 1 - i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
    return 0;
}