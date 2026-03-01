#include <iostream>
#include<math.h>
using namespace std;


int zeros_back(int n)
{
    int count = 0, index = 1, power;
    power = pow(5, index);
    while(power <= n)
    {
        count += (n / power);
        index++ ;
        power = pow(5, index);
    }

    return count;
}


int main() {

    int n;
    cin >> n;

    cout << zeros_back(n) << endl;

    return 0;
}