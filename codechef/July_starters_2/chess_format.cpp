#include <iostream>
using namespace std;

int main(int artc, char **argv)
{
    int t, a, b, type;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a + b < 3)
            type = 1;
        else if (a + b >= 3 && a + b <= 10)
            type = 2;
        else if (a + b >= 11 && a + b <= 60)
            type = 3;
        else
            type = 4;

        cout << type << "\n";
    }
    return 0;
}