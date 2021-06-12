#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char **argv)
{
    int t, xa, xb, Xa, Xb;
    cin >> t;
    while (t--)
    {
        cin >> xa >> xb >> Xa >> Xb;
        cout << ceil(Xa / xa) + ceil(Xb / xb) << endl;
    }
    return 0;
}