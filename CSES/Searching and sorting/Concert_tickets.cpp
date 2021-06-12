#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv)
{
    int m, n;
    long int *ticketPrice = new long int[n];
    int *buyed = new int[n];
    long int *customerPrice = new long int[m];

    for (int i = 0; i < n; i++)
    {
        cin >> ticketPrice[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> customerPrice[i];
    }

    sort(ticketPrice, ticketPrice + n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ticketPrice[j] > customerPrice[i] && buyed[j] != 1)
            {
                if (buyed[j - 1] != 1)
                {
                    buyed[j - 1] = 1;
                    cout << buyed[j - 1] << endl;
                    continue;
                }
                else
                {
                }
            }
        }
    }

    return 0;
}