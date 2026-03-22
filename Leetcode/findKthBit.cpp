#include <iostream>
#include <math.h>
using namespace std;

// 0111001  0110001

    char findKthBit(int n, int k) {
        

        if(k == 1){
            return '0';
        }

        if( k == ((1 << (n - 1)))){
            return '1';
        }else{
            if(k > (1 << (n - 1))){
                if(findKthBit(n - 1, (1 << n) - k) == '0')
                {
                    return '1';
                }else{
                    return '0';
                }
            }else{
                return findKthBit(n - 1, k);
            }
        }


    }


int main(){

    int n, k;

    cin >> n >> k;

    cout << findKthBit(n, k) << "\n";

    return 0;
}