#include <iostream>
#include <math.h>
using namespace std;

void tower_of_hanoi(int n, int first, int second, int third)
{
    if(n == 1){
        cout << first << " " << third << "\n";
    }else{
        tower_of_hanoi(n - 1, first, third, second);
        cout << first << " " << third << "\n";
        tower_of_hanoi(n - 1, second, first, third);
    }
}



int main() {
    int n;
    cin >> n;

    cout << pow(2, n) - 1 << "\n";

    tower_of_hanoi(n, 1, 2, 3);

    return 0;
}