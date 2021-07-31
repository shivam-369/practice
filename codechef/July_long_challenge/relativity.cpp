#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int t, g, c;
    cin >> t;
    while (t--)
    {
        cin >> g >> c;
        cout << (c * c) / (2 * g) << "\n";
    }
    return 0;
}