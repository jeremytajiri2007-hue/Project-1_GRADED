```cpp

// Name: Jeremy Tajiri
// Course: CISC 192 - C++ Programming
// Date: 11/16/2025
// Assignment: Tic-Tac-Toe Game

#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    int moveCount;

    void switchPlayer() {
        if(currentPlayer == 'X') currentPlayer = 'O';
        else currentPlayer = 'X';
    }

public:
    TicTacToe() {
        currentPlayer = 'X';
        moveCount = 0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                board[i][j] = ' ';
    }

    void displayBoard() {
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

    bool isValidMove(int row, int col){
        if(row<0 || row>2 || col<0 || col>2) return false;
        if(board[row][col] != ' ') return false;
        return true;
    }

    void makeMove(int row,int col){
        if(isValidMove(row,col)){
            board[row][col] = currentPlayer;
            moveCount++;
        } else {
            cout << "Hey that spot's taken or invalid!\n";
        }
    }

    bool checkWinner(){
        for(int i=0;i<3;i++){
            if(board[i][0]==currentPlayer && board[i][1]==currentPlayer && board[i][2]==currentPlayer) return true;
            if(board[0][i]==currentPlayer && board[1][i]==currentPlayer && board[2][i]==currentPlayer) return true;
        }
        if(board[0][0]==currentPlayer && board[1][1]==currentPlayer && board[2][2]==currentPlayer) return true;
        if(board[0][2]==currentPlayer && board[1][1]==currentPlayer && board[2][0]==currentPlayer) return true;
        return false;
    }

    bool isDraw(){
        if(moveCount>=9) return true;
        else return false;
    }

    void playGame(){
        int row, col;
        bool gameOver = false;

        cout << "Let's play Tic-Tac-Toe!\n";
        displayBoard();

        while(!gameOver){
            cout << "Player " << currentPlayer << ", pick row and col (1-3): ";
            cin >> row >> col;
            row--; col--;

            if(isValidMove(row,col)){
                makeMove(row,col);
                displayBoard();

                if(checkWinner()){
                    cout << "Player " << currentPlayer << " wins!!!\n";
                    gameOver = true;
                } else if(isDraw()){
                    cout << "It's a draw I guess...\n";
                    gameOver = true;
                } else {
                    switchPlayer();
                }

            } else {
                cout << "Nope, try another spot.\n";
            }
        }
    }
};

int main(){
    TicTacToe game;
    game.playGame();
    return 0;
}
