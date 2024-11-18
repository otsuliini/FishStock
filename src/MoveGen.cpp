#include <iostream>
#include <vector>
#include <string>   
#include <algorithm>
#include <Chessboard.hpp>


std::vector<std::string> genPawnMoves(bool turn, int startx, int starty) { // false = white, true = black
    // Fuck my life
    Chessboard board;
    int direction;
    std::vector<std::string> moves;
    if (turn == true) {
        direction = -1;
        std::string collor = "black";
    }
    else {
        direction = 1;  
        std::string collor = "white";	
    }
    // move one forward
    if (board.board[startx + direction][starty] == ' ') { // if square empty
        board.board[startx + direction][starty] = board.board[x][y]; // moves piece from old square to new square and renames the new square as the old square aka 'rook'
        board.board[startx][starty] = ' '; // clears old square
        moves.push_back(startx + direction + " " + starty); // adds move to vector (nerd talk for saves the generated move)
    }

    // move 2 forward if first move
    
    if (startx == 1 || startx == 6) {
            if (board.board[startx + direction * 2][starty] == ' ') { // if square empty
            board.board[startx + direction * 2][starty] = board.board[startx][starty]; // moves piece from old square to new square and renames the new square as the old square aka 'rook'
            board.board[startx][starty] = ' '; // clears old square
        }
    }
    // capture right
    
    // capture left
    return moves;
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