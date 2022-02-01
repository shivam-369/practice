#include <iostream>
using namespace std;

int main(int argc, char ** argv)
{
    int t, count_0, count_1;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        count_0 = count_1 = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0'){
                count_0++;
            }else{
                count_1++;
            }
        }

        if(count_0 != count_1){
            cout << min(count_0, count_1) << endl;
        }else if(s.length() > 2){
            cout << count_0 - 1 << endl;
        }else{
            cout << 0 << endl;
        }

    }

    return 0;
}