#include <iostream>
#include <vector>
#include <map>
using namespace std;

int mirror(int n){
    int answer = 0, remainder;

    while(n > 0){
        remainder = n % 10;
        n /= 10;
        answer = answer * 10 + remainder;
    }
    return answer;
}


int minMirrorPairDistance(vector<int>& nums) {

    long distance = INT_MAX;
        map <int, vector<int>> indexes;
        for(int i = 0; i < nums.size(); i++){
        indexes[nums[i]].push_back(i);
        }

    for(long i = 0; i < nums.size(); i++){
        int mirrorValue = mirror(nums[i]);
        if(indexes.count(mirrorValue)){
            for(int j = 0; j < indexes[mirrorValue].size(); j++){
                if(indexes[mirrorValue][j] > i){
                    distance = min(distance, indexes[mirrorValue][j] - i);
                    break;
                }
            }
        }
        if(distance == 1)
            return distance;
    }
    return distance == INT_MAX ? -1: distance;

}

int main(){

    int n;
    cin >> n;
    vector <int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    return 0;
}