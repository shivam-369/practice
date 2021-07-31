#include <iostream>
#include <string.h>
#include <set>
#include <stack>
using namespace std;

stack<string> subsequence(string s)
{
    string temp = "";
    stack<string> s1, s2;
    s1.push(temp);
    for (int i = 0; i < s.size(); i++)
    {
        while (!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp + s[i]);
            s2.push(temp);
        }

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    return s1;
}

bool isPrime(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (!(a % i))
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv)
{
    string s;
    cin >> s;
    long long ans = 0;
    stack<string> sub = subsequence(s);

    while (!sub.empty())
    {
        if (sub.top().length() >= 1)
        {
            if (isPrime(stoi(sub.top(), 0, 2)))
            {
                ans = max(ans, (long long)stoi(sub.top(), 0, 2));
            }
        }
        sub.pop();
    }

    cout << ans << "\n";
    return 0;
}