#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <deque>
using namespace std;

int main(int argc, char **argv)
{
    int t, n, max_ele, flag;
    cin >> t;
    map<int, int> frequency;
    // vector < int > elements;
    deque < int > final_list;
    vector < int > sequence;
    while (t--)
    {
        cin >> n;
        flag = max_ele = 0;
        frequency.clear();
        sequence.clear();
        final_list.clear();

        cout << "taking input\n";
        for (int i = 0; i < n; i++)
        {
            cin >> sequence[i];

            if(frequency.find(sequence[i]) != frequency.end())
                frequency[sequence[i]]++;
            else 
                frequency[sequence[i]] = 1;

            if (sequence[i] > max_ele)
            {
                max_ele = sequence[i];
            }
        }

        cout << "sorting\n";
        sort(sequence.begin(), sequence.end());

        if(frequency[max_ele] >= 2){
            flag = 1;
        }

        if(flag == 1)
        {
            cout << -1 << "\n";
            continue;
        }


        for(auto ptr = frequency.begin(); ptr != frequency.end(); ptr++)
        {
            if(ptr->second > 2)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
        {
            cout << -1 << "\n";
            continue;
        }

        cout << "outside answer\n";
        if(flag != 1)
        {
            for(int i = sequence.size() - 1; i >= 0; i--)
            {
                if(i % 2){
                    final_list.push_front(sequence[i]);
                }else {
                    final_list.push_back(sequence[i]);
                }

            }

            for(auto ptr = final_list.begin(); ptr != final_list.end(); ptr++)
            {
                cout << *ptr << " ";
            }
            cout << "\n";


        }
        


        // delete[] sequence;
    }

    return 0;
}