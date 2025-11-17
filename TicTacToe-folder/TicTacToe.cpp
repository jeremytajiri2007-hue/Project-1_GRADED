```cpp

// Name: Jeremy Tajiri
// Course: CISC 192 - C++ Programming
// Date: 11/16/2025
// Assignment: Tic-Tac-Toe Game (Class-Based)

#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];   // 3x3 game board
    char currentPlayer; // 'X' or 'O'
    int moveCount;      // count of moves made

    void switchPlayer() { // switch player turn
        if(currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }

public:
    TicTacToe() { // constructor
        currentPlayer = 'X';
        moveCount = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                board[i][j] = ' '; // empty board
            }
        }
    }

    void displayBoard() { // show the board
        cout << "\n";
        for(int i=0;i<3;i++){
            cout << " ";
            for(int j=0;j<3;j++){
                cout << board[i][j];
                if(j<2) cout << " | ";
            }
            cout << "\n";
            if(i<2) cout << "---+---+---\n";
        }
        cout << "\n";
    }

    bool isValidMove(int row, int col){ // check move
        if(row>=0 && row<3 && col>=0 && col<3){
            if(board[row][col]==' ') return true;
        }
        return false;
    }

    void makeMove(int row,int col){ // put move on board
        if(isValidMove(row,col)){
            board[row][col] = currentPlayer;
            moveCount++;
        } else {
            cout << "Oops, that move is not allowed!\n";
        }
    }

    bool checkWinner(){ // check for win
        // check rows and cols
        for(int i=0;i<3;i++){
            if(board[i][0]==currentPlayer && board[i][1]==currentPlayer && board[i][2]==currentPlayer)
                return true;
            if(board[0][i]==currentPlayer && board[1][i]==currentPlayer && board[2][i]==currentPlayer)
                return true;
        }
        // check diagonals
        if(board[0][0]==currentPlayer && board[1][1]==currentPlayer && board[2][2]==currentPlayer)
            return true;
        if(board[0][2]==currentPlayer && board[1][1]==currentPlayer && board[2][0]==currentPlayer)
            return true;

        return false;
    }

    bool isDraw(){ // check draw
        if(moveCount>=9) return true;
        return false;
    }

    void playGame(){ // main game loop
        int row, col;
        bool gameOver = false;

        cout << "Welcome to TicTacToe!\n";
        displayBoard();

        while(!gameOver){
            cout << "Player " << currentPlayer << " enter row and col (1-3): ";
            cin >> row >> col;
            row--; col--; // convert to 0-based index

            if(isValidMove(row,col)){
                makeMove(row,col);
                displayBoard();

                if(checkWinner()){
                    cout << "Player " << currentPlayer << " won!!!\n";
                    gameOver = true;
                } else if(isDraw()){
                    cout << "Its a draw!\n";
                    gameOver = true;
                } else {
                    switchPlayer();
                }

            } else {
                cout << "Not a valid move, try again\n";
            }
        }
    }
};

int main(){
    TicTacToe game;
    game.playGame();
    return 0;
}
