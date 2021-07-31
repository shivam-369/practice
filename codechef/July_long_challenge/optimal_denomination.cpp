#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int *salaries = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> salaries[i];
        }

        delete[] salaries;
    }
    return 0;
}