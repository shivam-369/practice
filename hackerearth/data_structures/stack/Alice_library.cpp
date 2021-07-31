#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char **argv)
{
    string s;
    cin >> s;

    stack<char> s1, s2, s3;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '\\')
            s1.push(s[i]);
        else
        {
            while (s1.top() != '/')
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.pop();

            while (!s2.empty())
            {
                s3.push(s2.top());
                s2.pop();
            }
            if (i != s.length() - 1)
                while (!s3.empty())
                {
                    s1.push(s3.top());
                    s3.pop();
                }
        }
    }
    while (!s3.empty())
    {
        cout << s3.top();
        s3.pop();
    }
    cout << "\n";
    return 0;
}