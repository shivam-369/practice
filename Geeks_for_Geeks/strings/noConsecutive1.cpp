#include <iostream>
#include <vector>
using namespace std;

// int count = 1;
vector <int> countOfStrings;

int countStrings(int n) {
        // code here
       return countOfStrings[n - 1];
    }

int main() {

    int n;

    cin >> n;

    countOfStrings.resize(n);

    countOfStrings[0] = 2;
    if(n > 1){
        countOfStrings[1] = 3;
        for(int i = 2; i < n; i++){
            countOfStrings[i] = countOfStrings[i - 1] + countOfStrings[i - 2];
        }
    }

    cout << countStrings(n) << "\n";

    return 0;
}