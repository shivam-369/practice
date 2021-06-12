#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n, count = 0;
    cin >> n;
    if (n % 5 == 0)
        count++;
    if (n % 11 == 0)
        count++;
    if (count == 0)
        cout << "NONE" << endl;
    else if (count == 1)
        cout << "ONE" << endl;
    else
        cout << "BOTH" << endl;
    return 0;
}