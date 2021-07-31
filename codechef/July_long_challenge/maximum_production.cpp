#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int t, x, y, d, z;
    cin >> t;
    while (t--)
    {
        cin >> d >> x >> y >> z;
        if (y * d + (7 - d) * z > 7 * x)
        {
            cout << y * d + (7 - d) * z << "\n";
        }
        else
        {
            cout << 7 * x << "\n";
        }
    }
    return 0;
}