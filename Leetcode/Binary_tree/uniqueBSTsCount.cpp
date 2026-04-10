#include <iostream>
#include <vector>
using namespace std;

int numTrees(int n) {
    vector< int> counts(n + 1, 0);
    counts[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i ; j++){
            counts[i] += (counts[j] * counts[i - j - 1]);
        }
    }
    return counts[n];
}

int main()
{

    int n;

    cin >> n;

    cout << numTrees(n) << "\n";

    return 0;
}