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

bool Board::canPlaceShip(int row, int col, int length, Direction dir){
    //board's borders
    if(row<0 || row>9 || col<0 || col>9) return false;

    if(dir == Direction::HORIZONTAL){
        if((col+length)>10) return false;
    }else{    //dir == Direction::VERTICAL
        if((row+length)>10) return false;
    }
    
    //other ships collisions
    for(int i=0; i<length; i++){
        if(dir == Direction::HORIZONTAL){
            if(grid[row][col+i] != TileState::WATER) return false;
        } else {
            if(grid[row+i][col] != TileState::WATER) return false;
        }
    }
    return true;
}


bool Board::placeShip(int row, int col, int length, Direction dir){
    if(canPlaceShip(row, col, length, dir)){
        switch (dir){
        case Direction::HORIZONTAL:
            for(int i=0; i<length; i++)
                grid[row][col+i]=TileState::SHIP;
            break;
        case Direction::VERTICAL:
            for(int i=0; i<length; i++)
                grid[row+i][col]=TileState::SHIP;
            break;
        }   
        return true;        
    }
    return false;
}



