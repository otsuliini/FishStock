

#include <iostream>
#include <vector>
#include <string>
#include <cctype> // for isupper, islower
#include "Chessboard.hpp"
#include "GenMoves.hpp"

std::vector<std::string> generateAllMoves(bool turn) {
    Chessboard board;
    std::vector<std::string> allMoves;
    
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
                    Move Move( x, y, x, y, board ); 
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

            // Append generated moves
            allMoves.insert(allMoves.end(), pieceMoves.begin(), pieceMoves.end());
        }
    }
    
    return allMoves;
}
