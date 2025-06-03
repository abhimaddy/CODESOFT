#include <iostream>
#include <vector>

using namespace std;

// Function declarations
void displayBoard(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, char player, int row, int col);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
void switchPlayer(char& player);

int main() {
    char playAgain;
    do {
        // Initialize 3x3 board with empty spaces
        vector<vector<char>> board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';
        bool gameWon = false;
        bool gameDraw = false;

        cout << "Welcome to Tic-Tac-Toe!\n";

        // Game loop
        while (!gameWon && !gameDraw) {
            // Display the board
            displayBoard(board);

            // Get player input
            int row, col;
            cout << "Player " << currentPlayer << "'s turn. Enter row (1-3) and column (1-3): ";
            cin >> row >> col;

            // Adjust for 0-based indexing
            row--;
            col--;

            // Validate and make move
            if (row >= 0 && row < 3 && col >= 0 && col < 3) {
                if (makeMove(board, currentPlayer, row, col)) {
                    // Check for win
                    if (checkWin(board, currentPlayer)) {
                        displayBoard(board);
                        cout << "Player " << currentPlayer << " wins!\n";
                        gameWon = true;
                    }
                    // Check for draw
                    else if (checkDraw(board)) {
                        displayBoard(board);
                        cout << "The game is a draw!\n";
                        gameDraw = true;
                    }
                    // Switch players if game continues
                    if (!gameWon && !gameDraw) {
                        switchPlayer(currentPlayer);
                    }
                } else {
                    cout << "Invalid move! The cell is already taken. Try again.\n";
                }
            } else {
                cout << "Invalid input! Row and column must be between 1 and 3. Try again.\n";
            }
        }

        // Ask to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}

// Display the current state of the board
void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "  -+-+- \n";
    }
    cout << "\n";
}

// Make a move on the board
bool makeMove(vector<vector<char>>& board, char player, int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

// Check if the current player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

// Check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // If any cell is empty, game is not a draw
            }
        }
    }
    return true; // All cells are filled, and no winner
}

// Switch the current player
void switchPlayer(char& player) {
    player = (player == 'X') ? 'O' : 'X';
}