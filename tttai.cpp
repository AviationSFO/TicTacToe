// Tic Tac Toe AI by Steven Weinstein on 3-25-2022
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;

int choosemove_AI(string board[3][3])
{
    srand(time(NULL));
    int row;
    int col;

    bool legal = false;


    // completes 3 in a row
    if (board[0][0] == "\033[32;1mO\033[0m" && board[0][2] == "\033[32;1mO\033[0m")
    {
        if (board[0][1] == "\033[90;1m2\033[0m")
        {
            return 1;
        }
    }

    if (board[2][0] == "\033[32;1mO\033[0m" && board[2][2] == "\033[32;1mO\033[0m")
    {
        if (board[2][1] == "\033[90;1m8\033[0m")
        {
            return 7;
        }
    }

    if (board[0][0] == "\033[32;1mO\033[0m" && board[2][0] == "\033[32;1mO\033[0m")
    {
        if (board[1][0] == "\033[90;1m4\033[0m")
        {
            return 3;
        }
    }

    if (board[0][2] == "\033[32;1mO\033[0m" && board[2][2] == "\033[32;1mO\033[0m")
    {
        if (board[0][1] == "\033[90;1m6\033[0m")
        {
            return 5;
        }
    }

    if (board[0][0] == "\033[32;1mO\033[0m" && board[1][1] == "\033[32;1mO\033[0m")
    {
        if (board[2][2] == "\033[90;1m9\033[0m")
        {
            return 8;
        }
    }


    // going in corners
    if (board[1][1] != "\033[91;1mX\033[0m" && board[1][1] != "\033[32;1mO\033[0m")
    {
        return 4;
    }
    else if (board[0][0] != "\033[91;1mX\033[0m" && board[0][0] != "\033[32;1mO\033[0m")
    {
        return 0;
    }
    else if (board[2][2] != "\033[91;1mX\033[0m" && board[2][2] != "\033[32;1mO\033[0m")
    {
        return 8;
    }
    else if (board[2][0] != "\033[91;1mX\033[0m" && board[2][0] != "\033[32;1mO\033[0m")
    {
        return 6;
    }
    else if (board[0][2] != "\033[91;1mX\033[0m" && board[0][2] != "\033[32;1mO\033[0m")
    {
        return 2;
    }
    else if (board[0][1] != "\033[91;1mX\033[0m" && board[0][1] != "\033[32;1mO\033[0m")
    {
        return 1;
    }
    else if (board[2][1] != "\033[91;1mX\033[0m" && board[2][1] != "\033[32;1mO\033[0m")
    {
        return 7;
    }
    else
    {
        do
        {
            row = rand() % 3;
            col = rand() % 3;
            if (board[row][col] != "\033[91;1mX\033[0m" && board[row][col] != "\033[32;1mO\033[0m")
            {
                legal = true;
                break;
            }
            else
            {
                legal = false;
                continue;
            }

        } while (!legal);
    }

    int loc = (row) * 3 + (col);
    return loc;
}
