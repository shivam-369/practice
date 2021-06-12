#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *coins = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    set<int> sums;
    set<int> copy;
    set<int>::iterator itr;

    for (int i = 0; i < n; i++)
    {
        copy = sums;

        for (itr = copy.begin(); itr != copy.end(); itr++)
        {
            sums.insert(*itr + coins[i]);
        }
        sums.insert(coins[i]);

        // sums = copy;
        // cout << sums.size() << endl;
    }
    cout << sums.size() << endl;
    for (itr = sums.begin(); itr != sums.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}