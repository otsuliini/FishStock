#include <iostream>
#include <vector>
#include <string>   
#include <algorithm>
#include <Chessboard.hpp>
#include <fortnite.c>   
#include <GenMoves.hpp>

// IMPORTANT: turn = false = white, true = black 

std::vector<std::string> genPawnMoves(bool turn, int startx, int starty) { 
    // Fuck my life
    Chessboard board;
    int direction;
    std::vector<std::string> moves;
    std::string collor;
    if (turn == true) {
        direction = -1;
        std::string color = "black";
    }
    else {
        direction = 1;  
        std::string color = "white";	
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
    std::string color;
    if (turn == true) {
       
        std::string color = "black";
    }
    else {
        
        std::string color = "white";	
    }

    if (board.board[startx + 1][starty + 2] == ' ' ) {
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
    std::string color;
    const int BOARD_SIZE = 8;
    if (startx < 0 || startx > BOARD_SIZE - 1 || starty < 0 || starty > BOARD_SIZE - 1) {
        return moves;
    }
    if (turn == true) {
        std::string color = "black";
    }
    else {
        std::string color = "white";	
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < BOARD_SIZE; j++) {
            if (board.board[startx + directions[i][0] * j][starty + directions[i][1] * j] == ' ') { // Normal Moves
                moves.push_back(startx + directions[i][0] * j + " " + starty + directions[i][1] * j);
            }
            else if (board.board[startx + directions[i][0] * j][starty + directions[i][1] * j] != ' ') { // Captures
                if (board.board[startx + directions[i][0] * j][starty + directions[i][1] * j] != color[0]) {
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
    const int BOARD_SIZE = 8;
    std::vector<std::string> moves;
    std::string color;
    if (turn == true) {
        std::string color = "black";
    }
    else {
        std::string color = "white";	
    }

    for (int i = 0; i < BOARD_SIZE; i++){// horizontal moves and takes
        if (board.board[startx][starty + i] == ' '){
            moves.push_back(startx + " " + starty + i);
        }
        else if (board.board[startx][starty + i] != ' ' && board.board[startx][starty + i] != color[0]){
            moves.push_back(startx + " " + starty + i);
            break;
        }
    
    for (int i = 0; i < 8; i++){ // vertical moves and takes
        if (board.board[startx + i][starty] == ' '){
            moves.push_back(startx + i + " " + starty);
        }
        else if (board.board[startx + i][starty] != ' ' && board.board[startx + i][starty] != color[0]){
            moves.push_back(startx + i + " " + starty);
            break;
        }
    }
}   
        

std::vector<std::string> genQueenMoves(bool turn, int startx, int starty); {
    

    const int BOARD_SIZE = 8;
    Chessboard board;
    int directions[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    std::vector<std::string> moves;
    std::string color;
    if (turn == true) {
        std::string color = "black";
    }
    else {
        std::string color = "white";	
    }


    // Check if startx and starty are within bounds
    if (startx < 0 || startx >= BOARD_SIZE || starty < 0 || starty >= BOARD_SIZE) {
        // Handle out-of-bounds error
        return moves;
    }

    // Generate moves in each direction
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < BOARD_SIZE; j++) {
            int newX = startx + directions[i][0] * j;
            int newY = starty + directions[i][1] * j;

            // Check if newX and newY are within bounds
            if (newX < 0 || newX >= BOARD_SIZE || newY < 0 || newY >= BOARD_SIZE) {
                break;
            }

            if (board.board[newX][newY] == ' ') { // Normal Moves
                moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
            } else if (board.board[newX][newY] != ' ' && board.board[newX][newY] != color[0]) { // Captures
                moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
                break;
            }
        }
    }

    // Generate horizontal moves and takes
    for (int i = 0; i < BOARD_SIZE; i++) {
        int newX = startx;
        int newY = starty + i;

        // Check if newX and newY are within bounds
        if (newY < 0 || newY >= BOARD_SIZE) {
            break;
        }

        if (board.board[newX][newY] == ' ') {
            moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
        } else if (board.board[newX][newY] != ' ' && board.board[newX][newY] != color[0]) {
            moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
            break;
        }
    }

    // Generate vertical moves and takes
    for (int i = 0; i < BOARD_SIZE; i++) {
        int newX = startx + i;
        int newY = starty;

        // Check if newX and newY are within bounds
        if (newX < 0 || newX >= BOARD_SIZE) {
            break;
        }

        if (board.board[newX][newY] == ' ') {
            moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
        } else if (board.board[newX][newY] != ' ' && board.board[newX][newY] != color[0]) {
            moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
            break;
        }
    }

    return moves;
}


std::vector<std::string>  genKingMoves(bool turn, int startx, int starty); {
    std::string color;
    if (turn == true) {
        std::string color = "black";
    }
    else {
        std::string color = "white";	
    }

    if (board.board[startx + 1][starty] == ' ' || board.board[startx + 1][starty] != color[0]){
        moves.push_back(startx + 1 + " " + starty);
    }
    else if (board.board[startx - 1][starty] == ' ' || board.board[startx - 1][starty] != color[0]){
        moves.push_back(startx - 1 + " " + starty);
    }
    else if (board.board[startx][starty + 1] == ' ' || board.board[startx][starty + 1] != color[0]){
        moves.push_back(startx + " " + starty + 1);
    }
    else if (board.board[startx][starty - 1] == ' ' || board.board[startx][starty - 1] != color[0]){
        moves.push_back(startx + " " + starty - 1);
    }
    else if (board.board[startx + 1][starty + 1] == ' ' || board.board[startx + 1][starty + 1] != color[0]){
        moves.push_back(startx + 1 + " " + starty + 1);
    }
    else if (board.board[startx + 1][starty - 1] == ' ' || board.board[startx + 1][starty - 1] != color[0]){
        moves.push_back(startx + 1 + " " + starty - 1);
    }
    else if (board.board[startx - 1][starty + 1] == ' ' || board.board[startx - 1][starty + 1] != color[0]){
        moves.push_back(startx - 1 + " " + starty + 1);
    }
    else if (board.board[startx - 1][starty - 1] == ' ' || board.board[startx - 1][starty - 1] != color[0]){
        moves.push_back(startx - 1 + " " + starty - 1);
    }
    return moves;
}// I just fucking ended this kids whole carreer blud is cooked, take the fucking LLLL. 

