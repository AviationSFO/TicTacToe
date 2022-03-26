// CLI Tic Tac Toe by Steven Weinstein on 3-25-2022
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "tttai.cpp"
using namespace std;

// declare board as a global variable
string board[3][3] = {
    {"\033[90;1m1\033[0m", "\033[90;1m2\033[0m", "\033[90;1m3\033[0m"},
    {"\033[90;1m4\033[0m", "\033[90;1m5\033[0m", "\033[90;1m6\033[0m"},
    {"\033[90;1m7\033[0m", "\033[90;1m8\033[0m", "\033[90;1m9\033[0m"}};

// AI for Tic Tac Toe checklist

// 1. if i have two-in-a-row place a third and win
// 2. if opponent has two-in-a-row place a third to block
// 3. if no corners, go in corner
// 4. go in center
// 5. go in corner
// 6. go on edge


// displays board in cli
void printboard()
{
    system("clear");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != 2)
            {
                cout << board[i][j] << " | ";
            }
            else
            {
                cout << board[i][j];
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
    if (plynum == 0)
        plychr = "\033[91;1mX\033[0m";
    else
        plychr = "\033[32;1mO\033[0m";

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
        if (board[row][col] != "X" && board[row][col] != "O")
        {
            board[row][col] = plychr;
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
bool checkwin(string player)
{
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player)
    {
        cout << player << " WINS!" << endl;
        return false;
    }
    else if (board[1][0] == player && board[1][1] == player && board[1][2] == player)
    {
        cout << player << " WINS!" << endl;
        return false;
    }
    else if (board[2][0] == player && board[2][1] == player && board[2][2] == player)
    {
        cout << player << " WINS!" << endl;
        return false;
    }
    else if (board[0][0] == player && board[1][0] == player && board[2][0] == player)
    {
        cout << player << " WINS!" << endl;
        return false;
    }
    else if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
    {
        cout << player << " WINS!" << endl;
        return false;
    }
    else if (board[0][2] == player && board[1][2] == player && board[2][2] == player)
    {
        cout << player << " WINS!" << endl;
        return false;
    }
    else if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        cout << player << " WINS!" << endl;
        return false;
    }
    else if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
    {
        cout << player << " WINS!" << endl;
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    bool running = true;
    cout << "You are X's. Opponent is O's." << endl;
    printboard();

    int AI_move = 0;

    for (int turn = 1; turn <= 9; turn++)
    {
        getmove(0);
        printboard();
        running = checkwin("\033[91;1mX\033[0m");
        if (!running)
            break;
        turn++;

        if (turn == 10)
        {
            cout << "Tie game." << endl;
            break;
        }

        bool AI_legal = false;

        while (!AI_legal)
        {
            AI_move = choosemove_AI();
            
            if (board[AI_move / 3][AI_move % 3] != "\033[91;1mX\033[0m" && board[AI_move / 3][AI_move % 3] != "\033[32;1mO\033[0m")
            {
                board[AI_move / 3][AI_move % 3] = "\033[32;1mO\033[0m";
                AI_legal = true;
                break;
            }
            else
            {
                AI_legal = false;
                continue;
            }
        }
        printboard();

        running = checkwin("\033[32;1mO\033[0m");
        if (!running)
            break;
    }
    return 0;
}
