#include <iostream>
using namespace std;

struct medals
{
    int gold, silver, bronze;
};

int main(int argc, char **argv)
{
    int t;
    cin >> t;
    medals c1, c2;
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    while (t--)
    {
        cin >> c1.gold >> c1.silver >> c1.bronze >> c2.gold >> c2.silver >> c2.bronze;

        if (c1.gold + c1.silver + c1.bronze > c2.gold + c2.silver + c2.bronze)
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }

    return 0;
}