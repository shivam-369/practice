#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


 bool hasDuplicate(vector<int>& nums) {

    sort(nums.begin(), nums.end());

    for(int i = 1; i < nums.size(); i++){

        if(nums[i] == nums[i - 1]){
            return true;
        }
    }
    return false;
}

int main() {

    int n;
    cin >> n;
    vector <int> nums(n);

    for(int i = 0; i < n; i++){

        cin >> nums[i];
    }

    cout << hasDuplicate(nums) << endl;

    return 0;
}