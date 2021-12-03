#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    unsigned long long int t, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        if (x % 2)
        {
            cout << "NO\n";
        }
        else
        {
            if (y % 2)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
    }

    return 0;
}