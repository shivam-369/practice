#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        int *isTrain = new int[n + 1];
        int *destination = new int[m];
        int *right = new int[n + 1];
        int * left = new int[n + 1];
        right[0] = left[0] = right[1] = 0;
        isTrain[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &isTrain[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &destination[i]);
        }
        if(isTrain[1] == 1)
        {
            right[1] = 0;
        }else{
            right[1] = -1;
        }
        for(int i = 2; i <= n; i++)
        {
            if(isTrain[i] == 1)
            {
                right[i] = 0;
            }else{
                if(right[i - 1] == -1)
                    right[i] = -1;
                else 
                    right[i] = right[i - 1] + 1;
            }
        }
        if(isTrain[n] == 2)
        {
            left[n] = 0;
        }else{
            left[n] = -1;
        }
        for(int i = n - 1; i >= 2; i--)
        {
            if(isTrain[i] == 2)
            {
                left[i] = 0;
            }else{
                if(left[i + 1] == -1)
                    left[i] = -1;
                else
                    left[i] = left[i + 1] + 1;
            }
        }
        for(int i = 0 ; i < m; i++)
        {
            if(destination[i] == 1)
            {
                printf("%d ", 0);
                continue;
            }
            if(left[destination[i]] != -1)
            {
                if(right[destination[i]] != -1)
                    printf("%d ", min(left[destination[i]], right[destination[i]]));
                else
                    printf("%d ", left[destination[i]]);
            }else if(left[destination[i]] == -1)
            {
                if(right[destination[i]] != -1)
                {
                    printf("%d ", right[destination[i]]);
                }else{
                    printf("%d ", -1);
                }
            }
        }
        printf("\n");
        delete[] isTrain;
        delete[] destination, delete[] right, delete[] left;
    }
    return 0;
}