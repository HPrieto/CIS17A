/*
 * File:   main.cpp(Remastered)
 * Author: Heriberto Prieto
 * Created on April 27, 2017, 5:26 PM
 * Included Concepts:
    - Line 19: Classes
    - Inheritance
    - Operator Overloading
    - Polymorphism
    - Templates
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

/* Contains required properties for a game of Connect Four */
class ConnectFour {
private:
    int columns;
    int rows;
    int turns;
    char **board;
public:
    //Class Constructor
    ConnectFour();
    //Class Destructor
    ~ConnectFour();
    //Columns Accessor
    int getCols()
        { return this->columns; }
    //Rows Accessor
    int getRows()
        { return this->rows; }
    //Turns accessor
    int getTurns()
        { return this->turns; }
    //Decrements number of turns
    void turnTkn()
        { this->turns -= 1; }
    //Increments number of turns
    void turnRdo()
        { this->turns += 1; }
    //Something happens
    void dropChp(int,int);
    //Prints contents of Connect Four Table/Board
    void prntBrd();
    //Checks for winner
    int gameWon();
};

/* Constructor: Allocates memory for 2DArray/Connect Four Game Board */
ConnectFour::ConnectFour() {
    //Initialize Variables
    this->columns = 7;
    this->rows    = 6;
    this->turns   = 42;
    //Allocate Board Memory
    this->board = new char*[this->rows];
    for (int r = 0; r < this->rows; r++)
        this->board[r] = new char[this->columns];
    //Sets 'new' board
    for (int r = 0; r < this->rows; r++)
        for (int c = 0; c < this->columns; c++)
            this->board[r][c] = ' ';
}

/* Class Destructor: Frees memory */
ConnectFour::~ConnectFour() {
    for (int r = 0; r < this->rows; r++)
        delete []this->board[r];
    delete []this->board;
}

/* Places value at given column, lowest value row without value */
void ConnectFour::dropChp(int place,int player) {
    for (int r = this->rows - 1; r >= 0; r--)
        if (this->board[r][place - 1] == ' ') {
            (player == 1) ? this->board[r][place - 1] = 'X':
                            this->board[r][place - 1] = '0';
            break;
        }
}

/* Prints Connect Four Board/2D Array */
void ConnectFour::prntBrd() {
    cout<<"----------------------------------"<<endl;
    for (int r = 0; r < this->rows; r++) {
        for (int c = 0; c < this->columns; c++)
            cout<<this->board[r][c]<<" || ";
        cout<<endl;
    }
    cout<<endl;
}

/* Game Winning Logic, returns player that won. */
int ConnectFour::gameWon() {
    for (int r = 0; r < this->rows; r++)
        for (int c = 0; c < this->columns; c++)
            if (this->board[r][c] != ' ') {
                //Bottom Half Vertical Win
                if (r > 2)
                if (this->board[r][c] == this->board[r - 1][c]) 
                if (this->board[r - 1][c] == this->board[r - 2][c]) 
                if (this->board[r - 2][c] == this->board[r - 3][c])
                return this->board[r][c];
                //Top Half Vertical Win
                if (r < 3)
                if (this->board[r][c] == this->board[r + 1][c]) 
                if (this->board[r + 1][c] == this->board[r + 2][c]) 
                if (this->board[r + 2][c] == this->board[r + 3][c])
                return this->board[r][c];
                //Reverse Diagonal Win
                if (r < 3 && c < 4)
                if (this->board[r][c] == this->board[r + 1][c + 1]) 
                if (this->board[r + 1][c + 1] == this->board[r + 2][c + 2]) 
                if (this->board[r + 2][c + 2] == this->board[r + 3][c + 3])
                return this->board[r][c];
                //Diagonal Win
                if (r < 3 && c < 4)
                if (this->board[r][c] == this->board[r + 1][c - 1]) 
                if (this->board[r + 1][c - 1] == this->board[r + 2][c - 2]) 
                if (this->board[r + 2][c - 2] == this->board[r + 3][c - 3])
                return this->board[r][c];
                //Horizontal Win
                if (c < 4)
                if (this->board[r][c] == this->board[r][c + 1]) 
                if (this->board[r][c + 1] == this->board[r][c + 2]) 
                if (this->board[r][c + 2] == this->board[r][c + 3])
                return this->board[r][c];
            }
    return 0;
}

/* Initialize Program Methods */
void fillBrd(ConnectFour *);
void prntBrd(ConnectFour *);
void rsetBrd(ConnectFour *);
void dropChp(ConnectFour *,int,int);
int  gameWon(ConnectFour *);
void endGame(ConnectFour *);

int main(int argc,char** argv) {
	//Seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    int won = 0;//False while four have not been connected
    int place;  //Position where chip will be dropped
    int player; //Depending on turn, keeps track of player turns
    ConnectFour *game = new ConnectFour();
    while (game->getTurns() >= 0 && !won) {
        //Output to player(s)
        cout<<"Turns left: "<<game->getTurns()<<endl;
        cout<<"Choose a column from 1 - 7 and drop a chip."<<endl;
        game->prntBrd();
    	(game->getTurns() % 2 == 0)?cout<<"Player 1's turn:"<<endl:cout<<"Player 2's turn:"<<endl;
        cin.clear();
    	cin>>place;
        player = (game->getTurns()%2==0)?1:2;
    	//"Drop Chip" into array based on players decision
    	if (place > 0 && place < 8) game->dropChp(place,player); else game->turnRdo();
        //Check if player won
        won = game->gameWon();
        //Announce winner
        if (won != 0) cout<<"Player: "<<won<<" wins!"<<endl; else game->turnTkn();
    }
    //Print Game Board
    game->prntBrd();
}