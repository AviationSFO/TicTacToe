// Tic Tac Toe AI by Steven Weinstein on 3-25-2022
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

#define X "\033[91;1mX\033[0m"
#define O "\033[32;1mO\033[0m"

using namespace std;

int choosemove_AI(string board[3][3])
{
    srand(time(NULL));
    int row = rand() % 3;
    int col = rand() % 3;

    bool legal = false;

    // completes 3 in a row for win
    if (board[0][1] == O && board[1][1] == O)
    {
        if (board[2][1] == "\033[90;1m8\033[0m")
        {
            return 7;
        }
    }

    else if (board[0][0] == O && board[0][2] == O)
    {
        if (board[0][1] == "\033[90;1m2\033[0m")
        {
            return 1;
        }
    }

    else if (board[2][0] == O && board[2][2] == O)
    {
        if (board[2][1] == "\033[90;1m8\033[0m")
        {
            return 7;
        }
    }

    else if (board[0][0] == O && board[2][0] == O)
    {
        if (board[1][0] == "\033[90;1m4\033[0m")
        {
            return 3;
        }
    }

    else if (board[0][2] == O && board[2][2] == O)
    {
        if (board[1][2] == "\033[90;1m6\033[0m")
        {
            return 5;
        }
    }

    else if (board[0][0] == O && board[1][1] == O)
    {
        if (board[2][2] == "\033[90;1m9\033[0m")
        {
            return 8;
        }
    }

    else if (board[0][0] == O && board[0][2] == O)
    {
        if (board[0][1] == "\033[90;1m2\033[0m")
        {
            return 1;
        }
    }

    else if (board[1][0] == O && board[1][2] == O)
    {
        if (board[1][1] == "\033[90;1m5\033[0m")
        {
            return 4;
        }
    }

    else if (board[0][2] == O && board[1][1] == O)
    {
        if (board[2][0] == "\033[90;1m7\033[0m")
        {
            return 6;
        }
    }

    else if (board[1][1] == O && board[2][1] == O)
    {
        if (board[0][1] == "\033[90;1m7\033[0m")
        {
            return 6;
        }
    }

    else if (board[0][0] == O && board[1][0] == O)
    {
        if (board[2][0] == "\033[90;1m7\033[0m")
        {
            return 6;
        }
    }

    else if (board[1][2] == O && board[2][2] == O)
    {
        if (board[0][2] == "\033[90;1m3\033[0m")
        {
            return 2;
        }
    }

    else if (board[1][0] == O && board[1][1] == O)
    {
        if (board[1][2] == "\033[90;1m6\033[0m")
        {
            return 5;
        }
    }

    else if (board[1][1] == O && board[1][2] == O)
    {
        if (board[1][0] == "\033[90;1m4\033[0m")
        {
            return 3;
        }
    }

    else if (board[0][1] == O && board[1][1] == O)
    {
        if (board[2][1] == "\033[90;1m8\033[0m")
        {
            return 7;
        }
    }

    else if (board[2][0] == O && board[1][1] == O)
    {
        if (board[0][2] == "\033[90;1m3\033[0m")
        {
            return 2;
        }
    }

    else if (board[0][0] == O && board[0][1] == O)
    {
        if (board[0][2] == "\033[90;1m3\033[0m")
        {
            return 2;
        }
    }

    else if (board[0][2] == O && board[1][1] == O)
    {
        if (board[2][0] == "\033[90;1m7\033[0m")
        {
            return 6;
        }
    }

    else if (board[1][0] == O && board[1][1] == O)
    {
        if (board[1][2] == "\033[90;1m6\033[0m")
        {
            return 5;
        }
    }

    else if (board[2][0] == O && board[2][1] == O)
    {
        if (board[2][2] == "\033[90;1m9\033[0m")
        {
            return 8;
        }
    }

    // defends an opponent win
    else if (board[0][1] == X && board[1][1] == X)
    {
        if (board[2][1] == "\033[90;1m8\033[0m")
        {
            return 7;
        }
    }

    else if (board[0][0] == X && board[0][2] == X)
    {
        if (board[0][1] == "\033[90;1m2\033[0m")
        {
            return 1;
        }
    }

    else if (board[2][0] == X && board[2][2] == X)
    {
        if (board[2][1] == "\033[90;1m8\033[0m")
        {
            return 7;
        }
    }

    else if (board[0][0] == X && board[2][0] == X)
    {
        if (board[1][0] == "\033[90;1m4\033[0m")
        {
            return 3;
        }
    }

    else if (board[0][2] == X && board[2][2] == X)
    {
        if (board[1][2] == "\033[90;1m6\033[0m")
        {
            return 5;
        }
    }

    else if (board[0][0] == X && board[1][1] == X)
    {
        if (board[2][2] == "\033[90;1m9\033[0m")
        {
            return 8;
        }
    }

    else if (board[0][0] == X && board[0][2] == X)
    {
        if (board[0][1] == "\033[90;1m2\033[0m")
        {
            return 1;
        }
    }

    else if (board[1][0] == X && board[1][2] == X)
    {
        if (board[1][1] == "\033[90;1m5\033[0m")
        {
            return 4;
        }
    }

    else if (board[0][2] == X && board[1][1] == X)
    {
        if (board[2][0] == "\033[90;1m7\033[0m")
        {
            return 6;
        }
    }

    else if (board[1][1] == X && board[2][1] == X)
    {
        if (board[0][1] == "\033[90;1m7\033[0m")
        {
            return 6;
        }
    }

    else if (board[0][0] == X && board[1][0] == X)
    {
        if (board[2][0] == "\033[90;1m7\033[0m")
        {
            return 6;
        }
    }

    else if (board[1][2] == X && board[2][2] == X)
    {
        if (board[0][2] == "\033[90;1m3\033[0m")
        {
            return 2;
        }
    }

    else if (board[1][0] == X && board[1][1] == X)
    {
        if (board[1][2] == "\033[90;1m6\033[0m")
        {
            return 5;
        }
    }

    else if (board[1][1] == X && board[1][2] == X)
    {
        if (board[1][0] == "\033[90;1m4\033[0m")
        {
            return 3;
        }
    }

    else if (board[0][1] == X && board[1][1] == X)
    {
        if (board[2][1] == "\033[90;1m8\033[0m")
        {
            return 7;
        }
    }

    else if (board[2][0] == X && board[1][1] == X)
    {
        if (board[0][2] == "\033[90;1m3\033[0m")
        {
            return 2;
        }
    }

    else if (board[0][0] == X && board[0][1] == X)
    {
        if (board[0][2] == "\033[90;1m3\033[0m")
        {
            return 2;
        }
    }

    else if (board[0][2] == X && board[1][1] == X)
    {
        if (board[2][0] == "\033[90;1m7\033[0m")
        {
            return 6;
        }
    }

    else if (board[1][0] == X && board[1][1] == X)
    {
        if (board[1][2] == "\033[90;1m6\033[0m")
        {
            return 5;
        }
    }

    else if (board[2][0] == X && board[2][1] == X)
    {
        if (board[2][2] == "\033[90;1m9\033[0m")
        {
            return 8;
        }
    }


    // going in corners
    if (board[1][1] != X && board[1][1] != O)
    {
        return 4;
    }
    else if (board[0][0] != X && board[0][0] != O)
    {
        return 0;
    }
    else if (board[2][2] != X && board[2][2] != O)
    {
        return 8;
    }
    else if (board[2][0] != X && board[2][0] != O)
    {
        return 6;
    }
    else if (board[0][2] != X && board[0][2] != O)
    {
        return 2;
    }
    else if (board[0][1] != X && board[0][1] != O)
    {
        return 1;
    }
    else if (board[2][1] != X && board[2][1] != O)
    {
        return 7;
    }
    else
    {
        do
        {
            row = rand() % 3;
            col = rand() % 3;
            if (board[row][col] != X && board[row][col] != O)
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

    int loc = (row)*3 + (col);
    return loc;
}
