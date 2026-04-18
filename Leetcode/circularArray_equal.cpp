#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

    vector <int> answer(queries.size(), -1);

    map <int, vector<int>> indexes;

    for(int i = 0; i < nums.size(); i++){
        indexes[nums[i]].push_back(i);
    }

    for(int i = 0; i < queries.size(); i++){
        
        int num = nums[queries[i]];
        auto ptr = lower_bound(indexes[num].begin(), indexes[num].end(), queries[i]);
        
        int index = ptr - indexes[num].begin();
        cout << "index " << index  << " for value " << num << "\n"; 
        if(indexes[num].size() == 1)
            continue;
        if(index == 0 ){
            answer[i] = min(indexes[num][1] - queries[i], (int)nums.size() - abs(indexes[num][indexes[num].size() - 1] ) + indexes[num][0]);

        }else if(index == indexes[num].size() - 1){
            answer[i] = min(queries[i] - indexes[num][index - 1], (int)nums.size() - queries[i] + indexes[num][0]);
        }else{
            answer[i] = min( queries[i] - indexes[num][index - 1], indexes[num][index + 1] - queries[i]);
        }      
    }

    return answer;
}


int main(){

    int n, m;
    cin >> n >> m;
    vector <int> nums(n), queries(m);

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    for(int i = 0; i < m; i++){
        cin >> queries[i];
    }

    vector <int> answer = solveQueries(nums, queries);

    return 0;
}