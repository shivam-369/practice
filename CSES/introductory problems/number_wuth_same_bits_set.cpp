#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int LargestSmall(int n)
{
    int answer = 0;
    int temp = 1;
    while(temp <= n){

        if(((n & temp) == false) && (n & (temp << 1))){
            answer = n ^ temp;
            answer = answer ^ (temp << 1);
            int tempCount = 0, pointer = 1;

            while(pointer < temp){
                if(pointer & answer){
                    tempCount++;
                }
                pointer <<= 1;
            }
            temp >>= 1;
            while(tempCount)
            {
                answer |= temp;
                temp >>= 1;
                tempCount--;
            }
            while(temp > 0){
                if(temp & answer){
                    answer ^= temp;
                }
                temp >>= 1;
            }
            break;
        }

        temp <<= 1;
    }

    return answer;
}


int SmallestLarge(int n)
{
    int count = 0;
    int answer = 0;
    int temp = 1;

    while(temp <= n){
        if((n & temp) && !(n & (temp << 1))){
            answer = n ^ temp;
            answer = answer ^ (temp << 1);
            int pointer = temp >> 1;

            while(pointer > 0){
                if(pointer & answer){
                    count++;
                }
                pointer >>= 1;
            }

            pointer = 1;
            while(count){
                answer |= pointer;
                pointer <<= 1;
                count--;
            }
            while(pointer < temp){
                if(answer & pointer){
                    answer = answer ^ pointer;
                }
                pointer <<= 1;
            }

            break;
        }
        temp <<= 1;
    }

    return answer;
}

int main() {

    // 11001

    int n;
    vector <int> answers(2);
    cin >> n;

    answers[0] = SmallestLarge(n);
    answers[1] = LargestSmall(n);

    for(int num: answers){
        cout << num << "\n";
    }

    return 0;
}