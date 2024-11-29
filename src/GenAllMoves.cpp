

#include <iostream>
#include <vector>
#include <string>
#include <cctype> // for isupper, islower
#include "Chessboard.hpp"
#include "GenMoves.hpp"
#include <sstream> // For parsing move strings



std::vector<Move> generateAllMoves(bool turn) {
    Chessboard board;
    std::vector<Move> allMoves; // Change to store Move objects

    bool PawnMovealreadyGenerated = false;
    const int BOARD_SIZE = 8;
    char playerColor = turn ? 'w' : 'b';
    
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            char piece = board.board[x][y];

            // Skip empty spaces or opponent's pieces
            if (piece == ' ' || (playerColor == 'w' ? islower(piece) : isupper(piece))) continue;

            std::vector<std::string> pieceMoves;

            switch (tolower(piece)) {
                case 'p':
                    pieceMoves = genPawnMoves(turn, x, y);
                    
                    for (const std::string& moveStr : pieceMoves) {
                        std::istringstream iss(moveStr); // Parse the move string
                        int endX, endY;
                        iss >> endX >> endY;

                        // Create the Move object and store it
                        Move move = Move(x, y, endX, endY, board);
                        allMoves.push_back(move);
                        Chessboard resultingBoard = applyMove(board, x, y, endX, endY);
                    }
                    
                    break;
                case 'r':
                    pieceMoves = genRookMoves(turn, x, y);
                    break;
                case 'n':
                    pieceMoves = genKnightMoves(turn, x, y);
                    break;
                case 'b':
                    pieceMoves = genBishopMoves(turn, x, y);
                    break;
                case 'q':
                    pieceMoves = genQueenMoves(turn, x, y);
                    break;
                case 'k':
                    pieceMoves = genKingMoves(turn, x, y);
                    break;
                default:
                    std::cerr << "Error: Unrecognized piece at (" << x << ", " << y << "): " << piece << std::endl;
                    continue;
            }

            // Convert pieceMoves strings to Move objects
            for (const std::string& moveStr : pieceMoves) {
                std::istringstream iss(moveStr); // Parse the move string
                int endX, endY;
                iss >> endX >> endY;

                // Create the Move object and store it
                allMoves.emplace_back(x, y, endX, endY, board);
            }
        }
    }
    
    return allMoves;
}
