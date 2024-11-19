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
    std::string collor;
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
        moves.push_back(startx + direction + " " + starty); // adds move to vector (nerd talk for saves the generated move)
    }

    // move 2 forward if first move
    
    if (startx == 1 || startx == 6) {
            if (board.board[startx + direction * 2][starty] == ' ') { // if square empty
            moves.push_back(startx + direction * 2 + " " + starty); // adds move to vector (nerd talk for saves the generated move)
        } // i think it might actually work
    }
    
    // capture
    if (starty + 1 < 8) {
        if (board.board[startx + direction][starty + 1] != ' ' && board.board[startx + direction][starty + 1] != collor[0]) {
            moves.push_back(startx + direction + " " + starty + 1);
        }
    }
    else if (starty - 1 > -1) {
        if (board.board[startx + direction][starty - 1] != ' ') {
            if (board.board[startx + direction][starty - 1] != collor[0]) {
                moves.push_back(startx + direction + " " + starty - 1);
            }
        }
    }
    else {
        std::cout << "error";
    }
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