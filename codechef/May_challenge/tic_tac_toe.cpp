#include <iostream>
#include <math.h>
using namespace std;

int moves[3] = {0, 0, 0};
int winner[2] = {0, 0};

void win(string board[])
{
    winner[0] = winner[1] = 0;
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][0] != '_')
        {
            if (board[i][0] == 'X')
            {
                winner[0]++;
            }
            else
            {
                winner[1]++;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && board[0][i] != '_')
        {
            if (board[0][i] == 'X')
            {
                winner[0]++;
            }
            else
            {
                winner[1]++;
            }
        }
    }
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[1][1] != '_')
    {
        if (board[0][0] == 'X')
        {
            winner[0]++;
        }
        else
        {
            winner[1]++;
        }
    }
    if ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]) && board[0][2] != '_')
    {
        if (board[1][1] == 'X')
        {
            winner[0]++;
        }
        else
        {
            winner[1]++;
        }
    }
}

void moveCount(string board[])
{
    moves[0] = moves[1] = moves[2] = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != '_')
            {
                moves[0]++;
                if (board[i][j] == 'X')
                {
                    moves[1]++;
                }
                else
                {
                    moves[2]++;
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    int t, winCount = 0;
    string board[3];
    cin >> t;
    while (t--)
    {
        board[0].clear();
        board[1].clear();
        board[2].clear();
        winCount = 0;
        cin >> board[0];
        cin >> board[1];
        cin >> board[2];

        moveCount(board);
        win(board);
        if (moves[0] == 9)
        {
            // cout << "inside complete game" << endl;
            if (moves[1] == 5 and moves[2] == 4)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 3 << endl;
            }
        }
        else
        {
            // cout << "INside incomplete board" << endl;
            if (moves[0] % 2)
            {
                // cout << "inside odd" << endl;
                if (moves[1] - moves[2] == 1)
                {
                    if (winner[0] && !winner[1])
                    {
                        cout << 1 << endl;
                    }
                    else if (winner[1])
                    {
                        cout << 3 << endl;
                    }
                    else if (!winner[0] && !winner[1])
                    {
                        cout << 2 << endl;
                    }
                    else
                    {
                        cout << 3 << endl;
                    }
                }
                else
                {
                    cout << 3 << endl;
                }
            }
            else
            {
                // cout << "inside even" << endl;
                if (moves[1] == moves[2])
                {
                    if (winner[1] && !winner[0])
                    {
                        cout << 1 << endl;
                    }
                    else if (winner[0])
                    {
                        cout << 3 << endl;
                    }
                    else if (!winner[1] && !winner[0])
                    {
                        cout << 2 << endl;
                    }
                    else
                    {
                        cout << 3 << endl;
                    }
                }
                else
                {
                    cout << 3 << endl;
                }
            }
        }
        // cout << winner[0] << " " << winner[1] << endl;
    }
    return 0;
}