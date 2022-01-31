#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char ** argv)
{
    int t, n, m, temp;
    string s; 

    cin >> t;

    while(t--)
    {
        cin >> n >> m;
        s.clear();

        temp = min(n, m);

        if(temp != 0)
        {
            if(n > m)
            {
                for(int i = 0; i <= temp; i++)
                {
                    s += "01";
                }

                for(int i = m + 1; i < n; i++)
                {
                    s += "010";
                }
                
                s += "0";

            }else if(m > n)
            {
                for(int i = 0; i <= temp; i++)
                {
                    s += "10";
                }

                for(int i = n + 1; i < m; i++)
                {
                    s += "110";
                }

                s += "1";

            }else{

                for(int i = 0; i <= n; i++)
                {
                    s += "10";
                }
            }
        }else{
            if(n == 0)
            {
                for(int i = 0; i < m; i++)
                {
                    s += "101";
                }
            }else if(m == 0)
            {
                for(int i = 0; i < n; i++)
                {
                    s += "010";
                }
            }
        }
        cout << s.length() << "\n";
        cout << s << "\n";
    }

    return 0;
}