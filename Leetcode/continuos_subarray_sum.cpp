#include <iostream>
#include <vector>
using namespace std;


bool checkSubarraySum(vector<int>& nums, int k) {
        vector <int> sums(nums.size(), 0);
        int maximum = nums[0];
        sums[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            sums[i] = sums[i - 1] + nums[i];
            if(maximum < nums[i])
            {
                maximum = nums[i];
            }      
        }
        
        for(int i = 0; i < nums.size() - 1; i++)
        {
            int temp = (i - 1 < 0 ? 0 :sums[i - 1]) % k;
            int j = i + (maximum != 0 ? max(k / maximum - 1, 1) : 1);
            for(; j < nums.size(); j++){
                if(sums[j] % k == temp)
                {
                    return true;
                }
            }
        }
        return false;
    }



int main() {

    int k, size;
    cin >> k >> size;
    vector<int> nums(size);

    for(int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }

    cout << checkSubarraySum(nums, k) << "\n";

    return 0;
}