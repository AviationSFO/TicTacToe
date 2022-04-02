// CLI Tic Tac Toe by Steven Weinstein on 4-1-2022
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "macros.h"
#include "minimax.cpp"
#define BOARD_SIZE 3

using namespace std;

// declare board as a global variable
int board[BOARD_SIZE][BOARD_SIZE] = {
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY}};

// displays board in cli
void printboard()
{
    system("clear");
    string str;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != 2)
            {
                if (board[i][j] == EMPTY)
                {
                    printf("\033[90;1m%d\033[0m | ", i * 3 + j + 1);
                }
                else if (board[i][j] == X)
                {
                    printf("%s | ", HUMAN);
                }
                else if (board[i][j] == O)
                {
                    printf("%s | ", AI);
                }
            }
            else
            {
                if (board[i][j] == EMPTY)
                {
                    printf("\033[90;1m%d\033[0m", i * 3 + j + 1);
                }
                else if (board[i][j] == X)
                {
                    printf("%s", HUMAN);
                }
                else if (board[i][j] == O)
                {
                    printf("%s", AI);
                }
            }
        }
        if (i != 2)
        {
            cout << endl
                 << "---------" << endl;
        }
        else
        {
            cout << endl
                 << endl;
        }
    }
}

// get a move from the player
void getmove(int plynum)
{
    int loc;
    int col;
    int row;
    string plychr;
    bool valid = false;
    if (plynum == X)
        plychr = HUMAN;
    else
        plychr = AI;

    while (!valid)
    {
        cout << "Player " << plychr << ", enter a number between 1 and 9" << endl;
        cout << "Enter a location: ";
        cin >> loc;

        switch (loc)
        {
        case 1:
        {
            col = 0;
            row = 0;
            valid = true;
            break;
        }
        case 2:
        {
            col = 1;
            row = 0;
            valid = true;
            break;
        }
        case 3:
        {
            col = 2;
            row = 0;
            valid = true;
            break;
        }
        case 4:
        {
            col = 0;
            row = 1;
            valid = true;
            break;
        }
        case 5:
        {
            col = 1;
            row = 1;
            valid = true;
            break;
        }
        case 6:
        {
            col = 2;
            row = 1;
            valid = true;
            break;
        }
        case 7:
        {
            col = 0;
            row = 2;
            valid = true;
            break;
        }
        case 8:
        {
            col = 1;
            row = 2;
            valid = true;
            break;
        }
        case 9:
        {
            col = 2;
            row = 2;
            valid = true;
            break;
        }
        default:
        {
            cout << "Invalid location. Try again." << endl;
            continue;
        }
        }
        if (board[row][col] != X && board[row][col] != O)
        {
            board[row][col] = plynum;
            valid = true;
            break;
        }
        else
        {
            cout << "That location is already taken. Try again." << endl;
            valid = false;
            continue;
        }
    }
}
bool checkwin(int player)
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

int main()
{
    bool running = true;
    cout << "You are X's. Opponent is O's." << endl;
    printboard();

    int AI_move = 0;
    int turn = 0;
    while (turn <= 9)
    {
        getmove(X);
        printboard();
        running = !checkwin(X);
        if (!running)
        {
            cout << "You win!" << endl;
            break;
        }
        turn++;

        if (turn == 10)
        {
            cout << "Tie game." << endl;
            break;
        }
        AI_move = -1;
        do
        {
            AI_move = minimax(board, O);
        } while (AI_move == -1);
        board[(AI_move - 1) / 3][(AI_move - 1) % 3] = O;
        printboard();

        running = !checkwin(O);
        if (!running)
        {
            cout << "You lose." << endl;
            break;
        }
        turn++;
        if (turn == 10)
        {
            cout << "Tie game." << endl;
            break;
        }
    }
    return 0;
}
