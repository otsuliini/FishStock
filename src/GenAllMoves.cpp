#include <iostream>
#include <vector>
#include <string>   
#include <algorithm>
#include <Chessboard.hpp>
#include <fortnite.c>   
#include <MoveGen.cpp>

std::vector<std::string> generateAllMoves(bool turn) {
    Chessboard board;
    std::vector<std::string> allMoves;
    
    const int BOARD_SIZE = 8;
    char playerColor = turn ? 'w' : 'b';
    
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            char piece = board.board[x][y];

            if (piece == ' ' || piece == (playerColor == 'w' ? 'b' : 'w')) continue;
            
            std::vector<std::string> pieceMoves;
            switch (tolower(piece)) { // Assuming piece identifiers: 'P', 'N', 'B', 'R', 'Q', 'K'
                case 'p': // Pawn
                    pieceMoves = genPawnMoves(turn, x, y);
                    break;
                case 'n': // Knight
                    pieceMoves = genKnightMoves(turn, x, y);
                    break;
                case 'b': // Bishop
                    pieceMoves = genBishopMoves(turn, x, y);
                    break;
                case 'r': // Rook
                    pieceMoves = genRookMoves(turn, x, y);
                    break;
                case 'q': // Queen
                    pieceMoves = genQueenMoves(turn, x, y);
                    break;
                case 'k': // King
                    pieceMoves = genKingMoves(turn, x, y);
                    break;
                default:
                    continue; // Ignore unrecognized pieces
            }
            
            // Add the generated moves to the allMoves vector
            allMoves.insert(allMoves.end(), pieceMoves.begin(), pieceMoves.end());
        }
    }
    
    return allMoves;
}
