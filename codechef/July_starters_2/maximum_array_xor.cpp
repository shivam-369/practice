#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int t, n, k;
    unsigned long long limit;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        limit = (1 << n) - 1;
        // cout << "limit " << limit << "\n";
        cout << (unsigned long long)(2) * limit * (unsigned long long)(min((limit + 1) / 2, (unsigned long long)(k))) << "\n";
    }
    return 0;
}
