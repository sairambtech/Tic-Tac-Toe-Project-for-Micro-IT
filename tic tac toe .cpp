#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = '1' + i * 3 + j;
}

void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool isWin() {
    for (int i = 0; i < 3; ++i) {
        // Check rows and columns
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
            return true;
    }
    // Check diagonals
    return ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer));
}

bool isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool makeMove(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    if (cell < 1 || cell > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move. Try again.\n";
        return false;
    }

    board[row][col] = currentPlayer;
    return true;
}

int main() {
    initializeBoard();

    cout << "=== Tic-Tac-Toe Game ===\n";
    printBoard();

    while (true) {
        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (!makeMove(move)) continue;

        printBoard();

        if (isWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        } else if (isDraw()) {
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}
