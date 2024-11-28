#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP
#include <iostream>
#include <utility>
class Chessboard {
    public:
        char board[8][8]{
            { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
            { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' }, 
            { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
            { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, 
            { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
            { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, 
            { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
            { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
        };  

        void printBoard() {
            for (int i = 0; i < 8; i++) { // rows
                for (int j = 0; j < 8; j++) { // columns
                    std::cout << board[i][j] << " ";
                }
                std::cout << std::endl;
            }
            return;
        } 
    
        std::vector<std::pair<int, int>> Get_All_Positions(char piece) {
        std::vector<std::pair<int, int>> positions;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == piece) {
                    positions.emplace_back(i, j);
                }
            }
        }
        return positions;
    }
};


struct Move {
    int startX, startY, endX, endY;    // The move itself (start and end positions)
    Chessboard resultingBoard;          // The resulting board after the move

    Move(int sX, int sY, int eX, int eY, const Chessboard& board) {
        startX = sX;
        startY = sY;
        endX = eX;
        endY = eY;
        resultingBoard = board;  // Copy the current board
    }
};

// Function to apply a move to the board and return a new board
Chessboard applyMove(const Chessboard& currentBoard, int startX, int startY, int endX, int endY) {
    Chessboard newBoard = currentBoard;
    newBoard.board[endX][endY] = newBoard.board[startX][startY];  // Move piece
    newBoard.board[startX][startY] = ' ';  // Empty the start position
    return newBoard;
}

std::string StoreMoves(std::vector<Move>& moves) {
    std::string movesString = "";  // Initialize an empty string to store the moves
    for (const Move& move : moves) {
        movesString += std::to_string(move.startX) + " " + std::to_string(move.startY) + " " + std::to_string(move.endX) + " " + std::to_string(move.endY) + " ";  // Append the move to the string
    }
    return movesString;
}
#endif // CHESSBOARD_HPP