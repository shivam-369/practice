#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
// #include <priority_queue>

using namespace std;

long long minCost(long long int arr[], int n)
{
    long long cost = 0, temp_cost = 0;

    priority_queue<long long, vector<long long>, std::greater<long long>> length;
    for (int i = 0; i < n; i++)
    {
        length.push(arr[i]);
    }
    while (length.size() > 1)
    {
        temp_cost = 0;
        temp_cost += length.top();
        length.pop();
        temp_cost += length.top();
        length.pop();
        length.push(temp_cost);
        cost += temp_cost;
    }
    return cost;
}

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;

    long long int *arr = new long long int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << minCost(arr, n) << "\n";
    return 0;
}