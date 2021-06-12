#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &A)
{
    int count = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[A[i] - 1] - 1 == i && A[i] - 1 != i)
        {
            count++;
            // printf("index - %d value - %d\n", i, A[i]);
        }
    }
    return count / 2;
}

// 58 3 31 26 48 26 3 72 52 40 7 42 6 13 67 56 66 19 9 37 12 19 46 6 42 15 28 33 64 12 14 52 33 60 35 1 56 51 74 57 23 22 19 8 37 27 20 34 64 64 28 22 49 4 13 51 68 4 51 27 71 49 46 21 2 33 16 42 33 25 40 21 59 14 53 52

int main(int argc, char **argv)
{
    int n, ans;
    // cin >> n;
    vector<int> best_friends{58, 3, 31, 26, 48, 26, 3, 72, 52, 40, 7, 42, 6, 13, 67, 56, 66, 19, 9, 37, 12, 19, 46, 6, 42, 15, 28, 33, 64, 12, 14, 52, 33, 60, 35, 1, 56, 51, 74, 57, 23, 22, 19, 8, 37, 27, 20, 34, 64, 64, 28, 22, 49, 4, 13, 51, 68, 4, 51, 27, 71, 49, 46, 21, 2, 33, 16, 42, 33, 25, 40, 21, 59, 14, 53, 52};
    ans = solve(best_friends);
    cout << ans << endl;
    return 0;
}