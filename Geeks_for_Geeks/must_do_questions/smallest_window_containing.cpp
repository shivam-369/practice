#include <iostream>
#include <map>
using namespace std;

// #define INT

int main(int argc, char **argv)
{
    int length = INT32_MAX, front = 0;
    map<char, int> count;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (count.find(s[i]) != count.end())
        {
            count[s[i]]++;
        }
        else
        {
            count[s[i]] = 1;
        }
        while (count.size() == 3)
        {
            length = min(length, i + 1 - front);
            count[s[front]]--;
            if (count[s[front]] == 0)
                count.erase(s[front]);
            front++;
        }
    }
    while (count.size() == 3)
    {
        length = min(int(s.length()) - front, length);
        count[s[front]]--;
        if (count[s[front]] == 0)
            count.erase(s[front]);
        front++;
    }
    cout << (length < INT32_MAX ? length : -1) << "\n";
    return 0;
}