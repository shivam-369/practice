#include<iostream>
using namespace std;

#define MOD_NUM 1000000007


int count_of_possible_strings(int n){
    int ans = 1;

    for(int i = 0; i < n; i++)
    {
        ans = (ans * 2) %  MOD_NUM;
    }

    return ans;
}

int main() {

    int n ;
    cin >> n;

    cout << count_of_possible_strings(n) << endl;

    return 0;
}