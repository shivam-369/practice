#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    long int t, D, d, P, Q, timesIncrement;
    unsigned long long ans = 0, production;
    cin >> t;
    while (t--)
    {
        cin >> D >> d >> P >> Q;
        timesIncrement = D / d;
        production = P + timesIncrement * Q;
        if (timesIncrement < 0)
            timesIncrement = 0;
        ans = ((timesIncrement) * (P + production - Q) / 2);
        ans *= d;

        D -= (timesIncrement * d);
        if (D > 0)
            ans += (production * D);
        // else if (D == 0)
        // {
        //     ans -= (Q * d);
        // }

        cout << ans << endl;
    }
    return 0;
}