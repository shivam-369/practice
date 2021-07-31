#include <iostream>
#include <vector>
using namespace std;

long long int solution(vector<int> length, int start, int partitions)
{
    long long int ans = INT64_MAX;

    return ans;
}

int main(int argc, char **argv)
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ans += arr[i];
    }

    delete[] arr;
    return 0;
}