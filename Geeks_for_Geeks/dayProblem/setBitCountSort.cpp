#include <iostream>
#include <vector>
#include <map>
using namespace std;


int setBitCount(int num){
    int count = 0;
    
    while(num > 0){
        if(num & 1){
            count++;
        }
        num >>= 1;
        
    }
    return count;
}


vector<int> sortBySetBitCount(vector<int>& arr) {
    // code here
    vector <int> answer(arr.size());
    int index = 0;
    map <int, vector<int>, greater<int>> setCounts;
    
    for(int i = 0; i < arr.size(); i++){
        setCounts[setBitCount(arr[i])].push_back(arr[i]);
    }
    
    for(auto p : setCounts){
        for(int i = 0; i < p.second.size(); i++)
            answer[index++] = p.second[i];
    }
    
    return answer;
}

int main(){
    int n;
    cin >> n;
    vector <int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector <int> answer = sortBySetBitCount(arr);

    for(int i = 0; i < n; i++){
        cout << answer[i] << " ";
    }

    cout << endl;
    return 0;
}