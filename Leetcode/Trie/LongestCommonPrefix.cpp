#include <iostream>
#include <vector>
using namespace std;

 string longestCommonPrefix(vector<string>& strs) {

    string commonPrefix = "";

    char curr;
    int smallest_length = INT_MAX;
    if(strs.size() > 0){
        for(int i = 0; i < strs.size(); i++){
            smallest_length = min(smallest_length, (int)strs[i].length());
        }

        for(int index = 0; index < smallest_length; index++){
            curr = strs[0][index];

            for(int i = 1; i < strs.size(); i++){
                if(strs[i][index] != curr){
                    return commonPrefix;
                }
            }
            commonPrefix += curr;
        }
    }
        
    return commonPrefix;
    
}

int main(){

    int n;
    cin >> n;
    vector <string> strs(n);

    for(int i = 0; i < n; i++){
        cin >> strs[i];
    }

    cout << longestCommonPrefix(strs) << "\n";
    return 0;
}