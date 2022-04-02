#include <iostream>
#include <cstdlib>
#include <string>
#include "macros.h"

int bi, bj;

using namespace std;

bool has_player_won(int player, int board[3][3])
{
    return board[0][0] == player && board[0][1] == player && board[0][2] == player ||
           board[1][0] == player && board[1][1] == player && board[1][2] == player ||
           board[2][0] == player && board[2][1] == player && board[2][2] == player ||
           board[0][0] == player && board[1][0] == player && board[2][0] == player ||
           board[0][1] == player && board[1][1] == player && board[2][1] == player ||
           board[0][2] == player && board[1][2] == player && board[2][2] == player ||
           board[0][0] == player && board[1][1] == player && board[2][2] == player ||
           board[0][2] == player && board[1][1] == player && board[2][0] == player;
}

bool is_board_full(int board[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == EMPTY)
            {
                return false;
            }
        }
    }

    return true;
}

int score(int player, bool set_move, int board[3][3])
{
    if (has_player_won(player, board))
        return 1;
    else if (has_player_won(-player, board))
        return -1;
    else if (is_board_full(board))
        return 0;

    int i, j, best = -1;
    for (i = 2; i >= 0; i--)
    {
        for (j = 2; j >= 0; j--)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = player;
                int amount = -score(-player, false, board);
                best = max(best, amount);
                board[i][j] = EMPTY;

                if (set_move && amount == best)
                {
                    bi = i;
                    bj = j;
                }
            }
        }
    }
    return best;
}

int minimax(int board[3][3], int player)
{
    bi = -2;
    bj = -2;
    score(player, true, board);

    if (bi != -2 && bj != -2)
    {
        return (bi * 3 + bj) + 1;
    }

    return -1;
}
