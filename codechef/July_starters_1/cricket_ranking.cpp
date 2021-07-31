#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int t, r1, r2, w1, w2, c1, c2, count;
    cin >> t;
    while (t--)
    {
        cin >> r1 >> w1 >> c1;
        cin >> r2 >> w2 >> c2;
        count = 0;

        if (r1 > r2)
            count++;

        if (w1 > w2)
            count++;

        if (c1 > c2)
            count++;

        if (count >= 2)
            cout
                << "A\n";
        else
            cout << "B\n";
    }
    return 0;
}