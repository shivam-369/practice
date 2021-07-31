#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int t, x, y;
    float ans;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        if (x + y >= 6)
            cout << 0 << "\n";
        else
            cout << float(6 - x - y) / float(6) << "\n";
    }

    return 0;
}
