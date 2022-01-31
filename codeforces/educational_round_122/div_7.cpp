#include <iostream>
using namespace std;


int main(int argc, char ** aergv)
{
    int t, n, remainder_7, remainder_10, multiple_10;
    cin >> t;
    while(t--)
    {
        cin >> n;
        remainder_7 = n % 7;
        remainder_10 = n % 10;
        multiple_10 = n / 10;
        if(remainder_10 - remainder_7 < 0){
            remainder_10 += (7 - remainder_7);
        }else{
            remainder_10 -= remainder_7;
        }
        cout << (multiple_10 * 10 + remainder_10) << endl;

    }

    return 0;
}