#include <iostream>
using namespace std;


long long wrong_positions(int row, int col, int size){
    long long wrongs = 0;
    if(row + 2 < size)
    {
        if(col + 1 < size)
            wrongs++ ;
        if(col - 1 >= 0)
            wrongs++ ;
    }
    if(row - 2 >= 0)
    {
        if(col + 1 < size)
            wrongs++ ;
        if(col - 1 >= 0)
            wrongs++ ;
    }
    if(col + 2 < size)
    {
        if(row + 1 < size)
            wrongs++;
        if(row - 1 >= 0)
            wrongs++ ;
    }
    if(col - 2 >= 0)
    {
        if(row + 1 < size)
            wrongs++ ;
        if(row - 1 >= 0)
            wrongs++ ;
    }
    return wrongs;
}


long long possible_positions(long n){

    long long count = 0, wrongs = 0;
    if(n != 1){
       
        count = (n * n - 1) * (n * n);
        for(int row = 0; row <  min((long)2, n / 2); row++)
        {
            for(int col = 0; col < n / 2; col++)
            {
                if(row >= 2 && col >= 2)
                {
                    wrongs += 8;
                    continue;
                }
                wrongs += wrong_positions(row, col, n);   
            }
        }
        for(int row = 2; row < n / 2; row++)
        {
            for(int col = 0; col < min((long)2, n / 2); col++)
            {
                wrongs += wrong_positions(row, col, n);
            }
        }
        wrongs += (max((long)0, (n/ 2 - 2)) * max((long)0, (n/ 2 - 2)) * 8) ;

        if(n % 2)
        {
            int row = n / 2 ;
            int col;
            for(col = 0; col < n / 2; col++) {
                wrongs += wrong_positions(row, col, n);
            }
            count -= wrong_positions(row, col, n);
        }
        count -= ( 4 * wrongs);
    }

    return count;

}


int main()
{
    long k;

    cin >> k;

    for(long row = 1; row <= k; row++)
    {
        cout << possible_positions(row) / 2 << endl;
    }

    return 0;
}