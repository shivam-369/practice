#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int t, x, a, b;
    cin >> t;
    while (t--)
    {
        cin >> x >> a >> b;
        a += ((100 - x) * b);
        a *= 10;
        cout << a << endl;
    }
    return 0;
}