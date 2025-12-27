#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include "board.h"
#include "player.h"
#include "ship.h"

using namespace std;

void getUserMove(int &row, int &col){
    char colChar;
    int rowNum;

    while(true){
        if(cin >> colChar >> rowNum){
            colChar = toupper(colChar);
            col = colChar - 'A';
            row = rowNum - 1;

            if(row>=0 && row<=9 && col>=0 && col<=9){
                break;
            } else{
                cout<<"Shoot off the board - try again!"<<endl;
            }
        } else{
            cout<<"Input error. Type for example A5"<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}


int main(){
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));

    Board playerBoard;
    Board computerBoard;

    cout<<"💥💥💥 S H I P S    G A M E 💥💥💥"<<endl;
    cout<<"Placing ships..."<<endl;
    playerBoard.autoPlacingShips();
    computerBoard.autoPlacingShips();

    bool gameOver = false;
    bool playerTurn = true; //Player start

    //main loop
    while(!gameOver){
        cout<<"----------------------------------------"<<endl;
        cout<<"            Enemy board"<<endl;
        computerBoard.printBoard(false);
        cout<<"            Your board"<<endl;
        playerBoard.printBoard(true);

        if(playerTurn){     //player's turn 
            cout<<"Your turn! Give the coordinates to shoot: ";
            int r, c;
            getUserMove(r,c);

            Board::TileState result = computerBoard.shoot(r,c);
            if(result==Board::TileState::HIT){
                cout<<">>> HIT! You heve one more shoot! <<<"<<endl;

                if(computerBoard.isWin()){
                    cout<<"You win!! Congratulations!" << endl;
                    gameOver = true;
                }
            } else if(result ==Board::TileState::MISS){
                cout<<">>> MISS! <<<"<<endl;
                playerTurn = false; //changing the player
            } else {
                cout<<"You've already shooted here!"<<endl;
                playerTurn = false;
            }
        } else {    //computer's turn
            cout<<"Computers's turn..."<<endl;
            Sleep(3);
            
            int r = rand()%10;
            int c = rand()%10;

            char colChar = 'A' + c;
            cout<<"Computer shooted in " << colChar << r+1 <<endl;
            
            Board::TileState result = playerBoard.shoot(r,c);

            if(result==Board::TileState::HIT){
                cout<<">>> Computer hits you! <<<"<<endl;

                if(playerBoard.isWin()){
                    cout<<"You lost! Computer destroyed your ships!"<<endl;
                    gameOver = true;
                }
            } else if( result == Board::TileState::MISS){
                cout<<"Computer missed his shoot!"<<endl;
                playerTurn = true;
            } else {
                cout<<"Computer shooted in the same place."<<endl;
                playerTurn = true;
            }
        }
    }
    cout<<"Game Over. Press ENTER to exit."<<endl;
    cin.ignore(); cin.get(); 
    return 0;
}

