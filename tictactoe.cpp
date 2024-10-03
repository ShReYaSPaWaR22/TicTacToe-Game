#include <iostream>
using namespace std;

// TicTacToe class to encapsulate the game logic
class TicTacToe {
private:
    char board[3][3];  // Game board
    char currentPlayer;  // Current player ('X' or 'O')

public:
    // Constructor to initialize the board and set the first player
    TicTacToe() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';  // Empty board cells
            }
        }
        currentPlayer = 'X';  // Player 'X' starts the game
    }

    // Function to draw the Tic-Tac-Toe board
    void drawBoard() const {
        cout << "-------------\n";
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " | ";
            }
            cout << "\n-------------\n";
        }
    }

    // Function to switch to the next player
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Function to make a move
    bool makeMove(int row, int col) {
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            return false;
        }
        board[row][col] = currentPlayer;  // Place player's mark on the board
        return true;
    }

    // Function to check for a win
    bool checkWin() const {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    // Function to check if the game is a draw
    bool isDraw() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;  // There's still an empty spot
                }
            }
        }
        return true;  // No empty spots, it's a draw
    }

    // Function to return the current player
    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;  // Create a TicTacToe object
    int row, col;
    cout << "Welcome to Tic-Tac-Toe!\n";

    // Game loop
    while (true) {
        game.drawBoard();  // Display the current state of the board
        cout << "Player " << game.getCurrentPlayer() << ", enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        // Make the move
        if (game.makeMove(row, col)) {
            // Check for a win
            if (game.checkWin()) {
                game.drawBoard();
                cout << "Player " << game.getCurrentPlayer() << " wins!\n";
                break;  // End the game after a win
            }

            // Check for a draw
            if (game.isDraw()) {
                game.drawBoard();
                cout << "It's a draw!\n";
                break;  // End the game after a draw
            }

            // Switch to the other player
            game.switchPlayer();
        }
    }

    return 0;
}
