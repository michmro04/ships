#ifndef BOARD_H
#define BOARD_H
#include <iostream>
using namespace std;

class Board{
public:
    enum class TileState{
        WATER,  //0
        SHIP,   //1
        HIT,    //2
        MISS,   //3
    };

    enum class Direction{
        HORIZONTAL, //0
        VERTICAL,   //1
    };

private:
    TileState grid[10][10];

public:
    Board();
    void printBoard();
    string convertStateToEmoji(TileState state);

    bool canPlaceShip(int row, int col, int length, Direction dir);
    bool placeShip(int row, int col, int length, Direction dir);
    void autoPlacingShips();

    TileState shoot(int row, int col);

    bool isWin();
};
#endif