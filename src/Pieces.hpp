#ifndef PIECES_HPP
#define PIECES_HPP

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include "Chessboard.hpp"

class pawn {
    public:

    Chessboard board; 

    std::vector<std::pair<int, int>> pawnPosition;

    pawn(bool turn){
        if (turn){
            pawnPosition = board.GetPosition('P');
        }
        else {
            pawnPosition = board.GetPosition('p');
        }
    }
};
class knight {
    public:

    Chessboard board;

    std::vector<std::pair<int, int>> knightPosition;

    knight(bool turn){
        if (turn){
            knightPosition = board.GetPosition('N');
        }
        else {
            knightPosition = board.GetPosition('n');
        }
    }
};
class bishop {
    public:


    Chessboard board;
    std::vector<std::pair<int, int>> bishopPosition;

    bishop(bool turn){
        if (turn){
            bishopPosition = board.GetPosition('B');
        }
        else {
            bishopPosition = board.GetPosition('b');
        }
    }
};
class rook {
    public:
    std::vector<std::pair<int, int>> rookPosition;
    Chessboard board;
    rook(bool turn){
        if (turn){
            rookPosition = board.GetPosition('R');
        }
        else {
            rookPosition = board.GetPosition('r');
        }
    }
};
class queen {
    public:

    Chessboard board; 
    std::vector<std::pair<int, int>> queenPosition;

    queen(bool turn){
        if (turn){
            queenPosition = board.GetPosition('Q');
        }
        else {
            queenPosition = board.GetPosition('q');
        }
    }
};
class king {
    public:


    Chessboard board;
    std::vector<std::pair<int, int>> kingPosition;

    king(bool turn){
        if (turn){
            kingPosition = board.GetPosition('K');
        }
        else {
            kingPosition = board.GetPosition('k');
        }
    }
};



#endif // PIECES_HPP