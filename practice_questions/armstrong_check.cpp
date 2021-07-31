#include <iostream>
#include <vector>

using namespace std;

vector<int> gen_digits(int n)
{
    vector<int> digits;
    while (n > 0)
    {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

int main(int argc, char **argv)
{
    int n, ans = 0;
    cin >> n;
    vector<int> digits = gen_digits(n);
    for (int num : digits)
        ans += (num * num * num);

    // cout << "ans " << ans << "\n";

    if (ans == n)
        cout << "It's an armstrong number\n";
    else
        cout << "It's not an armstrong number\n";

    return 0;
}