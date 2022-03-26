// Tic Tac Toe AI by Steven Weinstein on 3-25-2022
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;

int choosemove_AI()
{
    srand(time(NULL));
    int move = rand() % 9 + 1;
    return move;
}
