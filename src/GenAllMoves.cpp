#include <iostream>
#include <vector>
#include <string>   
#include <algorithm>
#include "Chessboard.hpp"
#include "GenMoves.hpp"




std::vector<std::string> generateAllMoves(bool turn) {
    Chessboard board;
    std::vector<std::string> allMoves;
    
    const int BOARD_SIZE = 8;
    char playerColor = turn ? 'w' : 'b';
    std::string piececolor;
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            char piece = board.board[x][y];

            if (piece == ' ' || piece == (playerColor == 'w' ? 'b' : 'w')) continue;
            
            std::vector<std::string> pieceMoves;
           if (isupper(piece)) {
               piececolor = "white";	

               switch (piece) {
                   case 'R':
                       pieceMoves = genRookMoves(turn, x, y);
                       break;
                   case 'N':
                       pieceMoves = genKnightMoves(turn, x, y);
                       break;
                   case 'B':
                       pieceMoves = genBishopMoves(turn, x, y);
                       break;
                   case 'Q':
                       pieceMoves = genQueenMoves(turn, x, y);
                       break;
                   case 'K':
                       pieceMoves = genKingMoves(turn, x, y);
                       break;
                   default:
                       std::cout << "error in generateAllMoves (WHITE piece)";
                       break;
               }
           }
           else if (islower(piece)) {
               piececolor = "black";
               switch (piece) {
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
                       std::cout << "error";
                       break;
               }
           }
           else {
               std::cout << "error in generateAllMoves (BLACK piece)";
           }



            // Add the generated moves to the allMoves vector
            allMoves.insert(allMoves.end(), pieceMoves.begin(), pieceMoves.end());
        
    }
    
    return allMoves;
}
}
