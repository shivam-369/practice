#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, char **argv)
{
    int n;
    stack<int> index;
    cin >> n;

    vector<int> prices(n);
    vector<int> span(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    index.push(0);
    span[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] < prices[i - 1])
        {
            index.push(i);
            span[i] = 1;
        }
        else
        {
            while (prices[index.top()] <= prices[i])
            {
                index.pop();
                if (index.empty())
                    break;
            }
            span[i] = i - index.top();
            index.push(i);
        }
    }
    // index
    for (int s : span)
    {
        cout << s << " ";
    }
    cout << "\n";
    return 0;
}