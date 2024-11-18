#include <iostream>
#include <vector>
#include <string>   
#include <algorithm>
#include <Chessboard.hpp>


int genPawnMoves(bool turn, int x, int y) { // false = white, true = black
    // Fuck my life
    Chessboard board;
    int direction;
    if (turn == true) {
        direction = -1;
        std::string collor = "black";
    }
    else {
        direction = 1;  
        std::string collor = "white";	
    }
    // move one forward
    if (board.board[x + direction][y] == ' ') { // if square empty
        board.board[x + direction][y] = board.board[x][y]; // moves piece from old square to new square and renames the new square as the old square aka 'rook'
        board.board[x][y] = ' '; // clears old square
    }

    // move 2 forward if first move
    
    if (x == 1 || x == 6) {
            if (board.board[x + direction * 2][y] == ' ') { // if square empty
            board.board[x + direction * 2][y] = board.board[x][y]; // moves piece from old square to new square and renames the new square as the old square aka 'rook'
            board.board[x][y] = ' '; // clears old square
        }
    }
    // capture right
    
    // capture left
    return 0;
}

int genKnightMoves() {
    
    return 0;
}

int genBishopMoves() {
    return 0;
}

int genRookMoves() {
    return 0;
}
int genQueenMoves() {
    return 0;
}

int genKingMoves() {
    return 0;
}


int genALLMoves() {
    return 0;
} // I just fucking ended this kids whole carreer blud is cooked, take the fucking LLLL. 