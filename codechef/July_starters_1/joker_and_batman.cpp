#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int t, n, m, l, k, data, l_id, count;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> l;
        vector<int> col_lists(n);
        vector<int> strip(l);
        for (int i = 0; i < m; i++)
        {
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                cin >> data;
                col_lists[data - 1] = i;
            }
        }

        for (int i = 0; i < l; i++)
        {
            cin >> strip[i];
        }

        count = 1;

        for (int i = 1; i < l; i++)
        {
            if (col_lists[strip[i] - 1] != col_lists[strip[i - 1] - 1])
                count++;
        }
        cout << count << "\n";
    }

    return 0;
}