#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP
#include <iostream>

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
    } 

    std::pair<int, int> Get_Position(char piece) {) {
        
    }
};
#endif // CHESSBOARD_HPP