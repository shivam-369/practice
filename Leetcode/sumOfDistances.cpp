#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<long long> distance(vector<int>& nums) {
        
    vector <long long> arr(nums.size(), 0);
    unordered_map <int, vector<int>> indexes;

    for(int i = 0; i < nums.size(); i++){
        indexes[nums[i]].push_back(i);
    }

    for(int i = 0; i < nums.size(); i++){
        if(arr[i] == 0){
            for(int j : indexes[nums[i]]){
                arr[i] += (abs(j - i));
            }
            for(int j = 1; j < indexes[nums[i]].size(); j++){
                arr[indexes[nums[i]][j]] = arr[indexes[nums[i]][j - 1]] + abs(indexes[nums[i]][j - 1] - indexes[nums[i]][j]) * j;
                arr[indexes[nums[i]][j]] -= (abs(indexes[nums[i]][j - 1] - indexes[nums[i]][j]) * (indexes[nums[i]].size() - j));
            }
        }
    }

    return arr;

}


int main(){

    int n;
    cin >> n;

    vector <int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector <long long> answer = distance(nums);

    for(int i = 0; i < n; i++){
        cout << answer[i] << " ";
    }
    cout << "\n";
    return 0;
}
