#include <iostream>
#include <vector>
using namespace std;

int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
    int distance = 0;
    for(int i = 0; i < nums1.size(); i++){

        for(int j = i + distance; j < nums2.size(); j++){
            if(nums1[i] <= nums2[j]){
                distance = j - i;
            }else{
                break;
            }
        }
    }
    return distance;
}


int main(){

    int n, m;
    cin >> n >> m;

    vector <int> nums1(n), nums2(m);

    for(int i = 0; i < n; i++){
        cin >> nums1[i];
    }

    for(int i = 0; i < m; i++){
        cin >> nums2[i];
    }

    cout << maxDistance(nums1, nums2);

    return 0;
}