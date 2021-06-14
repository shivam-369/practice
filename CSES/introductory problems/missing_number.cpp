#include <iostream>
using namespace std;
// #define l long

int main()
{
    long sum = 0;
    long expected;
    int n;
    cin >> n;
    expected = long ((long(n) * long(n + 1)) / 2);
    long num;
    for(int i = 1; i <= n - 1; i++)
    {   
        cin >> num;
        sum += num;
    }
    cout << (expected - sum) << endl;
    return 0;
}
