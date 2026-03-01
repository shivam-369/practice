#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    string s, palindrome, temp;
    bool odd = false;  
    cin >> s;
    vector<int> counts(26, 0);

    for(int i = 0; i < s.length(); i++)
    {
        counts[(char)s[i] - 65]++;
    }
    for(int i = 0; i < 26; i++){
        if(counts[i] % 2){
            if(odd == true)
            {
                cout << "NO SOLUTION\n";
                return 0;
            }
           palindrome = palindrome + (char)(i + 65); 
           odd = true;
        }
    }
    for(int i = 0; i < 26; i++){
        if(counts[i] != 0){
            temp = "";
            for(int j = 0; j < counts[i] / 2; j++)
            {
                temp += (char)(i + 65);
            }
            palindrome = temp + palindrome + temp;
        }
    }
    cout << palindrome << "\n";
    return 0;
}