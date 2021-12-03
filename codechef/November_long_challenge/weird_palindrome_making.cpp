#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int t, n, count;
    cin >> t;
    while (t--)
    {
        cin >> n;
        count = 0;

        int *frequency = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> frequency[i];

            if (frequency[i] % 2)
                count++;
        }

        cout << (count / 2) << "\n";
        delete[] frequency;
    }

    return 0;
}