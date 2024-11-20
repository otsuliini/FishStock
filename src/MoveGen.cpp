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
    //captures 
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
    
    std::vector<std::string> moves;
    std::string collor;
    if (turn == true) {
       
        std::string collor = "black";
    }
    else {
        
        std::string collor = "white";	
    }

    if (board.board[startx + 1][starty + 2] == ' ') {
        moves.push_back(startx + 1 + " " + starty + 2);
    }
    else if (board.board[startx + 1][starty - 2] == ' ') {
        moves.push_back(startx + 1 + " " + starty - 2);
    }
    else if (board.board[startx + 2][starty + 1] == ' ') {
        moves.push_back(startx + 2 + " " + starty + 1);
    }
    else if (board.board[startx - 2][starty + 1] == ' ') {
        moves.push_back(startx - 2 + " " + starty + 1);
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
    int directions[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    std::vector<std::string> moves;
    std::string collor;
    if (turn == true) {
        std::string collor = "black";
    }
    else {
        std::string collor = "white";	
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 8; j++) {
            if (board.board[startx + directions[i][0] * j][starty + directions[i][1] * j] == ' ') { // Normal Moves
                moves.push_back(startx + directions[i][0] * j + " " + starty + directions[i][1] * j);
            }
            else if (board.board[startx + directions[i][0] * j][starty + directions[i][1] * j] != ' ') { // Captures
                if (board.board[startx + directions[i][0] * j][starty + directions[i][1] * j] != collor[0]) {
                    moves.push_back(startx + directions[i][0] * j + " " + starty + directions[i][1] * j);
                }
                break;
            }
        }
    }
    
    return moves;
}

std::vector<std::string> genRookMoves(bool turn, int startx, int starty) { 
    Chessboard board;
    
    std::vector<std::string> moves;
    std::string collor;
    if (turn == true) {
        std::string collor = "black";
    }
    else {
        std::string collor = "white";	
    }

    for (int i = 0; i < 8; i++)// horizontal moves and takes
        if (board.board[startx][starty + i] == ' '){
            moves.push_back(startx + " " + starty + i);
        }
        else if (board.board[startx][starty + i] != ' ' && board.board[startx][starty + i] != collor[0]){
            moves.push_back(startx + " " + starty + i);
            break;
        }
    
    for (int i = 0; i < 8; i++){ // vertical moves and takes
        if (board.board[startx + i][starty] == ' '){
            moves.push_back(startx + i + " " + starty);
        }
        else if (board.board[startx + i][starty] != ' ' && board.board[startx + i][starty] != collor[0]){
            moves.push_back(startx + i + " " + starty);
            break;
        }
    }
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