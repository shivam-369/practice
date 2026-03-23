#include <iostream>
#include <set>
#include <math.h>
using namespace std;

set <long> primefactors(long n){

    set <long> factors;
    long number = abs(n);
    for(long i = 2; i <= abs(n); i++){

        while((number % i) == 0 && number > 1){
            number /= i;
            factors.insert(i);
        }
    }
    cout << factors.size() << " size of set\n";
    return factors;
}

bool isPrime(long n){

    n = abs(n);
    int sqRoot = sqrt(n);
    for(int i = 2; i <= sqRoot; i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

bool isUgly(int n) {

    // set <long> factors = primefactors(n);

    if(n <= 0){
        return false;
    }

    if(n == 1)
    {
        return true;
    }

    while(n % 2 == 0){
        n /= 2;
    }
    while(n % 3 == 0)
    {
        n /= 3;
    }

    while(n % 5 == 0){
        n /= 5;
    }
    if(n > 1){
        return false;
    }
    return true;
}

int main() {

    int n;

    cin >> n;

    cout << isUgly(n) << "\n";

    return 0;
}