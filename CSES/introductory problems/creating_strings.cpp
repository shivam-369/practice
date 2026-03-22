#include <iostream>
#include <set>
using namespace std;

set<string> buildString(string s){
    set <string> strings;

    if(s.length() == 1){
        strings.insert(s);
    }else{
        set<string> tempSet;
        for(int i = 0; i < s.length(); i++){
            s = s.substr(1) + s[0];
            tempSet = buildString(s.substr(1));
            for(string tempStr : tempSet){
                strings.insert(s[0] + tempStr);
            }
        }
    }

    return strings;
}

int main(){
    string s;
    cin >> s;

    set <string> answer = buildString(s);

    cout << answer.size() << "\n";
    for(string tempStr: answer){
        cout << tempStr << "\n";
    }

    return 0;
}
