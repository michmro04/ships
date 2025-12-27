#include "board.h"
using namespace std;

Board::Board(){
    //inicialization water on the board
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            grid[i][j] = TileState::WATER;        
        }
    }
}

char Board::convertStateToChar(TileState state){
    switch (state){
        case TileState::WATER: return '~';
        case TileState::SHIP: return 'S';
        case TileState::HIT: return 'X';
        case TileState::MISS: return 'O';
        default: return '?';
    }
}

void Board::printBoard(){
    cout << " " << convertStateToChar(grid[0][0]);
    cout<<"   A B C D E F G H I J" << endl;
    for(int i=0; i<10; i++){
        if (i<9) cout << i+1 << ' ';
        else cout << i+1;
        for (int j = 0; j < 10; j++){
            cout << " " << convertStateToChar(grid[i][j]);
        }
        cout<<endl;
    }

}

bool Board::canPlaceShip(int row, int col, int length, Direcrion dir){

}


bool Board::placeShip(int row, int col, int length, Direcrion dir){
    if(canPlaceShip){
        switch (dir){
        case Direcrion::HORIZONTAL:
            for(int i=0; i<length; i++)
                grid[row][col+i]=TileState::SHIP;
            break;
        case Direcrion::VERTICAL:
            for(int i=0; i<length; i++)
                grid[row+1][col]=TileState::SHIP;
            break;        
    }
}



