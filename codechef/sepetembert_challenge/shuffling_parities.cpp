#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int t, n, odd_count, even_count, ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        odd_count = even_count = ans = 0;
        int *a = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if ((i + 1) % 2)
            {
                if (a[i] % 2)
                    odd_count++;
                else
                    ans++;
            }
            else
            {
                if (a[i] % 2)
                    ans++;
                else
                    even_count++;
            }
        }
        cout << ans + 2 * min(odd_count, even_count) << "\n";
        delete[] a;
    }

    return 0;
}