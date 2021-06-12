#include <iostream>
using namespace std;

#define MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7)

unsigned long long int res = 0;

int power(unsigned long int y, long long x = 2)
{
    int res = 1; // Initialize result

    x = x % MAX; // Update x if it is more than or
                 // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % MAX;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % MAX;
    }
    return res;
}

unsigned long long int strToNum(string str)
{
    unsigned long long ans = 0, temp;
    int len = str.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            temp = power(len - 1 - i) % MAX;
            // temp %= MAX;
        }
        else
        {
            temp = 0;
        }
        ans = (ans % MAX + temp % MAX) % MAX;
    }
    return ans;
}

string genString(int x, int y)
{
    string ans = "";
    if (x % y == 0)
    {
        // ans += "1";
        // for (int i = 1; i < x; i++)
        // {
        //     ans += "0";
        // }
        res = power(x);
    }
    else
    {
        string temp = genString(y, x % y);
        res = strToNum(temp);
        int size = temp.length();
        unsigned int times_to_repeat = x / size;
        res = ((res % MAX) * ((power(times_to_repeat, power(size)) % MAX - 1) % MAX) / (power(size) % MAX - 1)) % MAX;
        // while (size < x)
        // {

        //     size += temp.length();
        // }
        size = x % size;
        res = (((res % MAX) * (power(size) % MAX)) % MAX + strToNum(temp.substr(0, size)) % MAX) % MAX;
        // if (ans.length() > x)
        // {
        //     ans = ans.substr(0, x);
        // }
    }
    return ans;
}

int main(int argc, char **argv)
{
    int t, x, y;
    string result;
    unsigned long long ans;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        res = 0;
        result = genString(x, y);
        // cout << result << endl;
        // ans = stoi(result, 0, 2);
        // ans = strToNum(result);
        // cout << ans % MAX << endl;
        cout << res % MAX << endl;
    }
    return 0;
}