/*
 * File:   main.cpp(Remastered)
 * Author: Heriberto Prieto
 * Created on April 27, 2017, 5:26 PM
 * Included Concepts:
    - Line 58: Memory allocation
    - Line 26: Functions with structures, used as input and output
    - Pointers with arrays and arrays of structures, internally as well as externally.
    - Use of character arrays as well as string objects.
    - Reading and wrting to binary files.
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/* Contains required properties for a game of Connect Four */
struct ConnectFour {
    int columns;
    int rows;
    int turns;
    int **board;
};

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
    game->columns = 7;
    game->rows    = 6;
    game->turns   = 42;
    fillBrd(game);                
    while (game->turns >= 0 && !won) {
        //Output to player(s)
        cout<<"Turns left: "<<game->turns<<endl;
        cout<<"Choose a column from 1 - 7 and drop a chip."<<endl;
        prntBrd(game);
    	(game->turns % 2 == 0)?cout<<"Player 1's turn:"<<endl:cout<<"Player 2's turn:"<<endl;
        cin.clear();
    	cin>>place;
        player = (game->turns%2==0)?1:2;
    	//"Drop Chip" into array based on players decision
    	if (place > 0 && place < 8) dropChp(game,place,player); else game->turns++;
        //Check if player won
        won = gameWon(game);
        //Announce winner
        if (won != 0) cout<<"Player: "<<won<<" wins!"<<endl; else game->turns--;
    }
    //Print Game Board
    prntBrd(game);
    //Deallocate memory
    endGame(game);
}

/* Allocates memory for 2DArray/Connect Four Game Board */
void fillBrd(ConnectFour *game) {
	//Initialize 2DArray
	game->board = new int*[game->rows];
	for (int r = 0; r < game->rows; r++)
		game->board[r] = new int[game->columns];
    //Set board to all zeros
    rsetBrd(game);
}

/* Prints Connect Four Board/2D Array */
void prntBrd(ConnectFour *game) {
	cout<<"----------------------------------"<<endl;
	for (int r = 0; r < game->rows; r++) {
		for (int c = 0; c < game->columns; c++)
			cout<<game->board[r][c]<<" || ";
		cout<<endl;
	}
	cout<<endl;
}

/* Resets values of 2D Array/Connect Four Board to 0 */
void rsetBrd(ConnectFour *game) {
	for (int r = 0; r < game->rows; r++)
		for (int c = 0; c < game->columns; c++)
			game->board[r][c] = 0;
}

/* Places value at given column, lowest value row without value */
void dropChp(ConnectFour *game,int place,int player) {
	for (int r = game->rows - 1; r >= 0; r--)
        if (game->board[r][place - 1] == 0) {
            game->board[r][place - 1] = player;
            break;
        }
}

/* Game Winning Logic, returns player that won. */
int gameWon(ConnectFour *game) {
    for (int r = 0; r < game->rows; r++)
        for (int c = 0; c < game->columns; c++)
            if (game->board[r][c] != 0) {
                //Bottom Half Vertical Win
                if (r > 2)
                if (game->board[r][c] == game->board[r - 1][c]) 
                if (game->board[r - 1][c] == game->board[r - 2][c]) 
                if (game->board[r - 2][c] == game->board[r - 3][c])return game->board[r][c];
                //Top Half Vertical Win
                if (r < 3)
                if (game->board[r][c] == game->board[r + 1][c]) 
                if (game->board[r + 1][c] == game->board[r + 2][c]) 
                if (game->board[r + 2][c] == game->board[r + 3][c])return game->board[r][c];
                //Reverse Diagonal Win
                if (r < 3 && c < 4)
                if (game->board[r][c] == game->board[r + 1][c + 1]) 
                if (game->board[r + 1][c + 1] == game->board[r + 2][c + 2]) 
                if (game->board[r + 2][c + 2] == game->board[r + 3][c + 3])return game->board[r][c];
                //Diagonal Win
                if (r < 3 && c < 4)
                if (game->board[r][c] == game->board[r + 1][c - 1]) 
                if (game->board[r + 1][c - 1] == game->board[r + 2][c - 2]) 
                if (game->board[r + 2][c - 2] == game->board[r + 3][c - 3])return game->board[r][c];
                //Horizontal Win
                if (c < 4)
                if (game->board[r][c] == game->board[r][c + 1]) 
                if (game->board[r][c + 1] == game->board[r][c + 2]) 
                if (game->board[r][c + 2] == game->board[r][c + 3])return game->board[r][c];
            }
    return 0;
}

/* Deallocates 2D Array memory/End of Game */
void endGame(ConnectFour *game) {
	for (int r = 0; r < game->rows; r++)
        delete []game->board[r];
    delete []game->board;
}