#include <iostream>
#include <string.h>
#include <math.h>
#include <numeric>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define ll long long
#define INT_MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10)
#define INT_MIN (-INT_MAX)

// Examples of lps[] construction:
// For the pattern “AAAA”,
// lps[] is [0, 1, 2, 3]

// For the pattern “ABCDE”,
// lps[] is [0, 0, 0, 0, 0]

// For the pattern “AABAACAABAA”,
// lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]

// For the pattern “AAACAAAAAC”,
// lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4]

// For the pattern “AAABAAA”,
// lps[] is [0, 1, 2, 0, 1, 2, 3]

vector<int> get_offset(string ptn)
{
    vector<int> offset(ptn.length(), 0);
    int index = 0;
    for (int i = 1; i < ptn.length(); i++)
    {
        if (ptn[i] == ptn[index])
        {
            index++;
            offset[i] = index;
        }
        else
        {
            if (index != 0)
            {
                i--;
                index = offset[index - 1];
            }
            else
            {
                offset[i] = 0;
            }
        }
    }
    return offset;
}

vector<int> match_pattern(string s, string ptn)
{
    vector<int> indexes;
    int str_index = 0, ptn_index = 0;
    vector<int> offset = get_offset(ptn);
    while (str_index != s.length())
    {
        if (ptn_index == ptn.length())
        {
            indexes.push_back(str_index - ptn.length());
            ptn_index = offset[ptn_index - 1];
        }
        if (ptn[ptn_index] == s[str_index])
        {
            ptn_index++;
            str_index++;
        }
        else
        {
            if (ptn_index > 0)
                ptn_index = offset[ptn_index - 1];
            else
                str_index++;
        }
    }
    return indexes;
}

int main(int argc, char **argv)
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    string s, ptn;
    cin >> s;
    cin >> ptn;
    // int *offset = new int[ptn.length()];
    // offset[0] = 0;

    // for (int i = 0; i < ptn.length(); i++)
    // {
    //     cout << offset[i] << " ";
    // }
    vector<int> indexes = match_pattern(s, ptn);
    for (int i : indexes)
    {
        cout << i << " ";
    }
    cout << "\n";
    // delete[] offset;
    return 0;
}