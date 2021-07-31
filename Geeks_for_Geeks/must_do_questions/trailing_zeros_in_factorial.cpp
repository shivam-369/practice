#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    long long int count = 0;
    cin >> n;
    int i = 5;
    while (i <= n)
    {
        count += n / i;
        i *= 5;
    }
    cout << count << endl;
    return 0;
}