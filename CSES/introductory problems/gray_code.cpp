#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){

    int n;
    string temp;
    cin >> n;
    vector<string> codes(pow(2, n));
    codes[0] = "0";
    codes[1] = "1";
    for(int i = 2; i < codes.size(); i *= 2)
    {
        for(int j = 0; j < i; j++)
        {
            temp = codes[j];
            codes[j] = "0" + temp;
            codes[2 * i - 1 -j] = "1" + temp;
        }      
    }
    for(int i = 0; i < codes.size(); i++)
    {
        cout << codes[i] << "\n";
    }
    return 0;
}