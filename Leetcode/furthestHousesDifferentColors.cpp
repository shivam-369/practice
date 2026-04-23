#include <iostream>
#include <vector>
using namespace std;


int maxDistance(vector<int>& colors) {
    int distance = 0;
    for(int i = colors.size() - 1; i > 0; i--){

        if(colors[i] != colors[0]){
            distance = max(distance, i);
            break;
        }
    }
    for(int i = 0; i < colors.size() - 1; i++){
        if(colors[i] != colors[colors.size() - 1]){
            distance = max(distance, (int)colors.size() - 1 - i );
            break;
        }
    }
    return distance;
}


int main(){

    int n;
    cin >> n;
    vector <int> colors(n);

    for(int i = 0; i < n; i++){
        cin >> colors[i];
    }

    cout << maxDistance(colors);

    return 0;
}