#include "board.h"
#include <cstdlib>
#include <algorithm>
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

    //other ships collisions or neighborhood using frame
    int rowStart = max(0,row-1);
    int colStart = max(0,col-1);

    int rowEnd, colEnd;

    if(dir==Direction::HORIZONTAL){
        rowEnd = min(9, row+1);
        colEnd = min(9, col+length);
    } else{
        rowEnd = min(9, row+length);
        colEnd = min(9, col+1);
    }

    for(int r=rowStart; r<=rowEnd; r++){
        for(int c=colStart; c<=colEnd; c++){
            if(grid[r][c] != TileState::WATER) return false;
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

void Board::autoPlacingShips(){
    int ships = 10; //numbers of ships

    for(int i=0; i<ships; i++){
        bool success = false;
        while(!success){
            int genRow = rand()%10;
            int genCol = rand()%10;
            
            Direction dir;
            int a = rand()%2;
            if(a==0) dir=Direction::HORIZONTAL;
            else dir=Direction::VERTICAL;
            
            int size;
            if(i<1) size = 4;   //4S ship
            else if(i<3) size = 3;    //3S ship
            else if(i<6) size = 2;    //2S ship
            else if(i<10) size = 1;    //1S ship
            
            if(placeShip(genRow, genCol, size, dir)) success=true;
        }
    }
}





