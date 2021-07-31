#include <iostream>
#include <vector>
using namespace std;

int MissingNumber(vector<int> &array, int n)
{
    // Your code goes here
    long long int expected_sum = ((long long)(n) * (long long)(n + 1)) / 2;
    long long int actual_sum = 0;
    for (int num : array)
    {
        actual_sum += num;
    }

    return expected_sum - actual_sum;
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<int> array(n - 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> array[i];
    }
    cout << MissingNumber(array, n) << "\n";
    return 0;
}