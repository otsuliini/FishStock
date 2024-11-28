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
                    case 'P':
                        pieceMoves = genPawnMoves(turn, x, y);
                        std::cout << "white pawn moves generated";
                    break;

                   case 'R':
                       pieceMoves = genRookMoves(turn, x, y);
                       std::cout << "white rook moves generated";
                       break;

                   case 'N':
                       pieceMoves = genKnightMoves(turn, x, y);
                       std::cout << "white knight moves generated";
                       break;
                       
                   case 'B':
                       pieceMoves = genBishopMoves(turn, x, y);
                       std::cout << "white bishop moves generated";
                       break;

                   case 'Q':
                       pieceMoves = genQueenMoves(turn, x, y);
                       std::cout << "white queen moves generated";
                       break;

                   case 'K':
                       pieceMoves = genKingMoves(turn, x, y);
                       std::cout << "white king moves generated";
                       break;

                   default:
                       std::cout << "error in generateAllMoves (WHITE piece)";
                       break;
               }
           }
           else if (islower(piece)) {
               piececolor = "black";
               switch (piece) {
                   case 'p':
                       pieceMoves = genPawnMoves(turn, x, y);
                       std::cout << "black pawn moves generated";
                       break;

                   case 'r':
                       pieceMoves = genRookMoves(turn, x, y);
                       std::cout << "black rook moves generated";
                       break;

                   case 'n':
                       pieceMoves = genKnightMoves(turn, x, y);
                       std::cout << "black knight moves generated";
                       break;

                   case 'b':
                       pieceMoves = genBishopMoves(turn, x, y);
                       std::cout << "black bishop moves generated";
                       break;

                   case 'q':
                       pieceMoves = genQueenMoves(turn, x, y);
                       std::cout << "black queen moves generated";
                       break;

                   case 'k':
                       pieceMoves = genKingMoves(turn, x, y);
                       std::cout << "black king moves generated";
                       break;

                   default:
                       std::cout << "error in generating black moves";
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
