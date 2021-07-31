#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <stack>
using namespace std;

void printSubsequence(string input, string output)
{
    if (input.empty())
    {
        cout << output << " ";
        return;
    }
    else
    {
        printSubsequence(input.substr(1), output);
        printSubsequence(input.substr(1), output + input[0]);
    }
}

int main(int argc, char **argv)
{
    string s;
    cin >> s;
    // set<string> all;
    stack<string> s1, s2;
    string temp = "";
    s1.push(temp);
    for (int i = 0; i < s.length(); i++)
    {
        while (!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp + "");
            s2.push(temp + s[i]);
        }
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << "\n";

    printSubsequence(s, "");
    return 0;
}