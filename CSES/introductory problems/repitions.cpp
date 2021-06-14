#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int global_max = 1;
    int current_max = 1;
    for(int i = 1; i < s.length(); i++)
    {
        if(s[i] == s[i - 1])
        {
            current_max++;
        }else if(global_max < current_max)
        {  
                global_max = current_max;
                current_max = 1;
                // i++;

        }else {
            current_max = 1;
        }
    }
    if(global_max < current_max)
    {
        global_max = current_max;
    }
    cout << global_max << endl;
    return 0;
}