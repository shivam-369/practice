#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(int argc, char **argv)
{
    vector<int> factors;
    int n, limit;
    cin >> n;
    limit = ceil(sqrt(n));
    for (int i = 1; i <= limit; i++)
    {
        if (n % i == 0)
            factors.push_back(i);
    }
    cout << factors.size() << endl;
    for (int i = 0; i < factors.size(); i++)
    {
        cout << factors[i] << " ";
    }
    cout << endl;
    return 0;
}