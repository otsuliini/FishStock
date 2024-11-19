#include <iostream>
#include <vector>
#include <string>   
#include <algorithm>
#include <Chessboard.hpp>
// IMPORTANT: turn = false = white, true = black 

std::vector<std::string> genPawnMoves(bool turn, int startx, int starty) { 
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
        }   
    }
    
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
    
    return moves;
}

std::vector<std::string> genKnightMoves(bool turn, int startx, int starty) {
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

    if (board.board[startx + direction][starty + 2] == ' ') {
        moves.push_back(startx + direction + " " + starty + 2);
    }
    else if (board.board[startx + direction][starty - 2] == ' ') {
        moves.push_back(startx + direction + " " + starty - 2);
    }
    else if (board.board[startx + 2][starty + direction] == ' ') {
        moves.push_back(startx + 2 + " " + starty + direction);
    }
    else if (board.board[startx - 2][starty + direction] == ' ') {
        moves.push_back(startx - 2 + " " + starty + direction);
    }
    else if (board.board[startx + 2][starty + 1] == ' ') {
        moves.push_back(startx + 2 + " " + starty + 1);
    }
    else if (board.board[startx + 2][starty - 1] == ' ') {
        moves.push_back(startx + 2 + " " + starty - 1);
    }
    else if (board.board[startx - 2][starty + 1] == ' ') {
        moves.push_back(startx - 2 + " " + starty + 1);
    }
    else if (board.board[startx - 2][starty - 1] == ' ') {
        moves.push_back(startx - 2 + " " + starty - 1);
    }

    return moves;  
}

std::vector<std::string> genBishopMoves(bool turn, int startx, int starty) {
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

    if (startx + 1 < 8 && starty + 1 < 8) { // top right
        if (board.board[startx + 1][starty + 1] != ' ' && board.board[startx + 1][starty + 1] != collor[0]) {
            moves.push_back(startx + 1 + " " + starty + 1);
        }
    }
    else if (startx - 1 > -1 && starty - 1 > -1) { // top left
        if (board.board[startx - 1][starty - 1] != ' ' && board.board[startx - 1][starty - 1] != collor[0]) {
            moves.push_back(startx - 1 + " " + starty - 1);
        }
    }
   
    if (startx + 1 < 8 && starty - 1 > -1) { // bottom right
        if (board.board[startx + 1][starty - 1] != ' ' && board.board[startx + 1][starty - 1] != collor[0]) {
            moves.push_back(startx + 1 + " " + starty - 1);
        }
    }
    else if (startx - 1 > -1 && starty + 1 < 8) { // bottom left
        if (board.board[startx - 1][starty + 1] != ' ' && board.board[startx - 1][starty + 1] != collor[0]) {
            moves.push_back(startx - 1 + " " + starty + 1);
        }
    return moves;
}

std::vector<std::string> genRookMoves(bool turn, int startx, int starty) {
    return moves;
}

std::vector<std::string> genQueenMoves(bool turn, int startx, int starty) {
    return moves;
}

std::vector<std::string>  genKingMoves(bool turn, int startx, int starty) {
    return moves;
}


int genALLMoves() {
    return 0;
} // I just fucking ended this kids whole carreer blud is cooked, take the fucking LLLL. 