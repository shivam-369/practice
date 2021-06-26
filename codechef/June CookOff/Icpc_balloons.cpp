#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int t, n, count;
    cin >> t;
    while (t--)
    {
        cin >> n;
        count = 7;
        int *problems = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> problems[i];
        }
        // cout << "hello n: " << n << "\n";
        int i = 0;
        for (; i < n; i++)
        {
            if (count == 0)
            {
                // cout << i << "\n";
                break;
            }
            else
            {
                if (problems[i] <= 7)
                {
                    count--;
                }
            }
        }
        if (count == 0)
            cout << i << "\n";
        delete[] problems;
    }
    return 0;
}