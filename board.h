#ifndef BOARD_H
#define BOARD_H
#include <iostream>

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
    char convertStateToChar(TileState state);

    bool canPlaceShip(int row, int col, int length, Direction dir);
    bool placeShip(int row, int col, int length, Direction dir);
};
#endif