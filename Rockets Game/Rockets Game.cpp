#include <bits/stdc++.h>

using namespace std;

class Game{
private:
    char** board;
    int size; // Size of the board
public:
//    void setsize(int n);
    Game(int n);
    void displayboard();
    bool isValidMove(int row, int col, char direction);
};
/*
void Game::setsize() {
    this->size = n;
}*/

Game::Game(int n) {
    for(int j = 1; j < size - 1; ++j)
        board[0][j] = 'g';
    for(int i = 1; i < size - 1; ++i)
        board[i][0] = 'r';
}

void Game::displayboard() {
    for (int i = 0; i < size; ++i) {
        cout << "\n| ";
        for (int j = 0; j < size; ++j) {
            cout << setw(4) << board[i][j] << " |";  // Print each cell of the board
        }
        cout << "\n------------------------------------------------";
    }
    cout << endl;
}
// Implement checks for valid sliding and jumping moves
bool Game::isValidMove(int row, int col, char direction) {
    // Check if the coordinates are within board boundaries
    if (row <= 0 || row >= size || col <= 0 || col >= size) {
        return false;
    }

    // Check for valid sliding moves
    if (direction == 'L' || direction == 'R') {
        // Check if there's a watermelon to slide
        if (board[row][col] != 'g' || board[row][col] != 'r') {
            return false;
        }
        // Check if the adjacent space is empty or a watermelon (for sliding)
        char adjacent = (direction == 'L') ? board[row][col - 1] : board[row][col + 1];
        if (adjacent != ' ' && adjacent != 'W') {
            return false;
        }
    } else if (direction == 'U' || direction == 'D') {
        // Similar checks for column sliding moves
    } else if (direction == 'J') {
        // Check for valid jumping move
        // ... (implement logic to check for a valid jump based on game rules)
    } else {
        // Invalid direction
        return false;
    }

    return true;
}

//Fill the board to initialize it
/*void fillBoard(int n, char** board){

}*/


// Shift  in the row in the specified direction
void slideRow(char** board, int row, char direction) {
}

// Shift  in the column in the specified direction
void slideColumn(char** board, int col, char direction) {
}

// Remove the jumped-over and update the board
void jump(char** board, int row1, int col1, int row2, int col2) {
}

// Check if the board is empty
bool isBoardEmpty(char** board) {
}

int main() {
    char **board;

    cout<<"Enter the size of the board : ";
    int n; cin>>n;

    while (true) {
//        displayBoard(n, board);

        // Get player input and validate move
        int row, col, direction;
        // ...

        // Make the move (either slide or jump)
        // ...

        // Check for win or loss
        if (isBoardEmpty(board)) {
            cout << "You win!" << endl;
            break;
        }
        // If no valid moves are available, game over
    }
    return 0;
}