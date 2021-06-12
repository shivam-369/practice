#include <iostream>
#include <math.h>
using namespace std;

#define MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7)

int main(int argc, char **argv)
{
    unsigned long long int ans = 1, temp = 1, count = 0;
    // int count = 0;
    // while (ans < MAX)
    // {
    //     ans <<= 1;
    //     count++;
    // }
    // cout << count << " " << ans << endl;
    // cout << ans % MAX << endl;
    while (ans >= temp)
    {
        temp = ans;
        ans <<= 1;
        count++;
    }
    cout << count << " " << temp << " " << ans << endl;
    return 0;
}