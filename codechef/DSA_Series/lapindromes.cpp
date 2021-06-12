#include <iostream>
#include <map>

using namespace std;

int main(int argc, char **argv)
{
    int t, flag;
    string s;
    cin >> t;
    map<char, int> m;
    while (t--)
    {
        cin >> s;
        m.clear();
        flag = 0;
        for (int i = 0; i < s.length() / 2; i++)
        {
            if (m.find(s[i]) != m.end())
            {
                m[s[i]]++;
            }
            else
            {
                m[s[i]] = 1;
            }
        }
        for (int i = s.length() / 2 + (s.length() % 2 == 0 ? 0 : 1); i < s.length(); i++)
        {
            if (m.find(s[i]) != m.end())
            {
                m[s[i]]--;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            for (auto itr = m.begin(); itr != m.end(); itr++)
            {
                if (itr->second != 0)
                {
                    cout << "NO" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 0;
                }
            }
        }
        if (flag == 0)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}