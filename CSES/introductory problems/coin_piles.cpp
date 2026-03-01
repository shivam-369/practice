#include <iostream>
using namespace std;

int main(){

    int t, a, b, minimum, maximum;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        minimum = min(a, b);
        maximum = max(a, b);
        if(maximum <= 2 * minimum){

            if((a + b) % 3){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}
