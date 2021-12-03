#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(int argc, char **argv)
{
    int t;
    int difficulty[4];
    map<int, int> s1;
    // set<int> s1;
    cin >> t;
    while (t--)
    {
        s1.clear();
        // cout << s1.size() << " size\n";
        for (int i = 0; i < 4; i++)
        {
            cin >> difficulty[i];
            s1[difficulty[i]]++;
        }

        if (s1.size() >= 3)
        {
            cout << 2 << "\n";
        }
        else if (s1.size() == 2)
        {
            for (auto ptr : s1)
            {
                if (ptr.second > 2 || ptr.second <= 1)
                {
                    cout << 1 << "\n";
                }
                else
                {
                    cout << 2 << "\n";
                }
                break;
            }
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    return 0;
}