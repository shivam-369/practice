#include <iostream>
using namespace std;

bool isSafe(int x, int y, int **board, int n)
{
    for (int i = x; i >= 0; i--)
    {
        if (board[i][y] == 1)
        {
            return 0;
        }
    }
    for (int i = y; i >= 0; i--)
    {
        if (board[x][i] == 1)
        {
            return 0;
        }
    }
    int i = x, j = y;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return 0;
        }
        i--;
        j--;
    }
    i = x;
    j = y;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
        {
            return 0;
        }
        i--;
        j++;
    }
    return 1;
}

bool placeQueens(int n, int qpsr, int **board, int x, int y)
{
    if (qpsr == n)
    {
        return 1;
    }
    else
    {
        for (int i = y; i < n; i++)
        {
            if (isSafe(x, i, board, n))
            {
                board[x][i] = 1;

                if (placeQueens(n, qpsr + 1, board, x, i + 1) == 1)
                    return 1;

                board[x][i] = 0;
            }
        }
        for (int i = x + 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isSafe(i, j, board, n))
                {
                    board[i][j] = 1;

                    if (placeQueens(n, qpsr + 1, board, i, j) == 1)
                    {
                        return 1;
                    }
                    else
                    {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    int **board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    int col;
    for (col = 0; col < n; col++)
    {
        if (placeQueens(n, 0, board, 0, col))
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
            col = -1;
            break;
        }
    }
    if (col != -1)
    {
        cout << "Not possible" << endl;
    }
    return 0;
}