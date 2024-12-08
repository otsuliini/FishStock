#include <iostream>
#include <vector>
#include <string>   
#include <algorithm>
#include "Chessboard.hpp"
#include "GenMoves.hpp"


// IMPORTANT: turn = false = white, true = black 

std::vector<std::string> genPawnMoves(bool turn, int startx, int starty) {
    // Initialize variables
    Chessboard board;
    int direction;
    std::vector<std::string> moves;
    std::string color;

    // Determine direction and color based on turn
    if (turn == true) {
        direction = -1;
        color = "black";
    } else {
        direction = 1;
        color = "white";
    }

    // Move one forward
    if (board.board[startx + direction][starty] == ' ') { // If square is empty
        moves.push_back(std::to_string(startx + direction) + " " + std::to_string(starty));
    }

    // Move two forward if first move
    if (startx == 1 && direction == 1 || startx == 6 && direction == -1) { // Ensure pawn is in starting row
        if (board.board[startx + direction * 2][starty] == ' ') { // If square is empty
            moves.push_back(std::to_string(startx + direction * 2) + " " + std::to_string(starty));
        }
    }

    // Captures to the right
    if (starty + 1 < 8) { // Ensure within bounds
        if (board.board[startx + direction][starty + 1] != ' ' && board.board[startx + direction][starty + 1] != color[0]) {
            moves.push_back(std::to_string(startx + direction) + " " + std::to_string(starty + 1));
        }
    }

    // Captures to the left
    if (starty - 1 >= 0) { // Ensure within bounds
        if (board.board[startx + direction][starty - 1] != ' ' && board.board[startx + direction][starty - 1] != color[0]) {
            moves.push_back(std::to_string(startx + direction) + " " + std::to_string(starty - 1));
        }
    }

    return moves;
}



std::vector<std::string> genKnightMoves(bool turn, int startx, int starty) {
    Chessboard board;
    std::vector<std::string> moves;

    // Determine color based on turn
    std::string color = turn ? "black" : "white";

    // All possible knight move offsets
    int knightMoves[8][2] = {
        {1, 2}, {1, -2}, {2, 1}, {2, -1},
        {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}
    };

    // Check all possible knight moves
    for (auto& move : knightMoves) {
        int newX = startx + move[0];
        int newY = starty + move[1];

        // Ensure the new position is within bounds
        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            char piece = board.board[newX][newY];
            // Add the move if the square is empty or occupied by an opponent
            if (piece == ' ' || piece != color[0]) {
                moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
            }
        }
    }

    return moves;
}

std::vector<std::string> genBishopMoves(bool turn, int startx, int starty) {
    Chessboard board;
    int directions[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    std::vector<std::string> moves;
    std::string color;
    const int BOARD_SIZE = 8;

    // Ensure starting position is within bounds
    if (startx < 0 || startx >= BOARD_SIZE || starty < 0 || starty >= BOARD_SIZE) {
        return moves;
    }

    // Determine color based on turn
    color = turn ? "black" : "white";

    // Loop over all directions
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < BOARD_SIZE; j++) { // Incremental steps in the current direction
            int newX = startx + directions[i][0] * j;
            int newY = starty + directions[i][1] * j;

            // Ensure the new position is within bounds
            if (newX < 0 || newX >= BOARD_SIZE || newY < 0 || newY >= BOARD_SIZE) {
                break;
            }

            char piece = board.board[newX][newY];
            if (piece == ' ') { // Empty square
                moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
            } else { // Occupied square
                if (piece != color[0]) { // Capture if opponent's piece
                    moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
                }
                break; // Stop further movement in this direction
            }
        }
    }

    return moves;
}

std::vector<std::string> genRookMoves(bool turn, int startx, int starty) {
    Chessboard board;
    const int BOARD_SIZE = 8;
    std::vector<std::string> moves;
    std::string color = turn ? "black" : "white";

    // Rook movement directions: up, down, left, right
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Iterate over all four directions
    for (auto& direction : directions) {
        for (int step = 1; step < BOARD_SIZE; step++) {
            int newX = startx + direction[0] * step;
            int newY = starty + direction[1] * step;

            // Ensure the new position is within bounds
            if (newX < 0 || newX >= BOARD_SIZE || newY < 0 || newY >= BOARD_SIZE) {
                break;
            }

            char piece = board.board[newX][newY];
            if (piece == ' ') { // Empty square
                moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
            } else { // Occupied square
                if (piece != color[0]) { // Capture if opponent's piece
                    moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
                }
                break; // Stop further movement in this direction
            }
        }
    }

    return moves;
}


std::vector<std::string> genQueenMoves(bool turn, int startx, int starty) {
    const int BOARD_SIZE = 8;
    Chessboard board;
    std::vector<std::string> moves;
    std::string color = turn ? "black" : "white";

    // Queen's movement directions: diagonals and straight lines
    int directions[8][2] = {
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1},  // Diagonals
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}     // Horizontal and vertical
    };

    // Ensure starting position is within bounds
    if (startx < 0 || startx >= BOARD_SIZE || starty < 0 || starty >= BOARD_SIZE) {
        return moves;
    }

    // Loop through all possible directions
    for (int i = 0; i < 8; i++) {
        for (int step = 1; step < BOARD_SIZE; step++) {
            int newX = startx + directions[i][0] * step;
            int newY = starty + directions[i][1] * step;

            // Check if the new position is within bounds
            if (newX < 0 || newX >= BOARD_SIZE || newY < 0 || newY >= BOARD_SIZE) {
                break; // Stop if out of bounds
            }

            // Get the piece at the target position
            char target = board.board[newX][newY];
            if (target == ' ') {
                // Empty square: normal move
                moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
            } else {
                // Check if it's a valid capture
                if ((turn && islower(target)) || (!turn && isupper(target))) {
                    moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
                }
                break; // Stop further movement in this direction
            }
        }
    }

    return moves;
}



std::vector<std::string> genKingMoves(bool turn, int startx, int starty) {
    Chessboard board;
    const int BOARD_SIZE = 8;
    std::string color = turn ? "black" : "white";
    std::vector<std::string> moves;

    // Possible king moves (8 directions)
    int directions[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},   // Up, Down, Right, Left
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // Diagonals
    };

    // Generate all possible moves
    for (auto& direction : directions) {
        int newX = startx + direction[0];
        int newY = starty + direction[1];

        // Check if new position is within bounds
        if (newX >= 0 && newX < BOARD_SIZE && newY >= 0 && newY < BOARD_SIZE) {
            char target = board.board[newX][newY];
            if (target == ' ' || (turn && islower(target)) || (!turn && isupper(target))) {
                moves.push_back(std::to_string(newX) + " " + std::to_string(newY));
            }
        }
    }

    return moves;
}

// I just fucking ended this kids whole carreer blud is cooked, take the fucking LLLL. 

