#include <iostream>
#include "board.h"
#include "player.h"
#include "ship.h"

using namespace std;
int main(){
    srand(time(NULL));

    Board board;
    board.printBoard();

    board.autoPlacingShips();
    board.printBoard();


    return 0;
}

