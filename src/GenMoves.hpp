#ifndef GENMOVES_HPP
#define GENMOVES_HPP

#include <vector>
#include <string>

// Function declarations for generating chess moves
std::vector<Move> generateAllMoves(bool turn);
std::vector<std::string> genPawnMoves(bool turn, int startx, int starty);
std::vector<std::string> genKnightMoves(bool turn, int startx, int starty);
std::vector<std::string> genBishopMoves(bool turn, int startx, int starty);
std::vector<std::string> genRookMoves(bool turn, int startx, int starty);
std::vector<std::string> genQueenMoves(bool turn, int startx, int starty);
std::vector<std::string> genKingMoves(bool turn, int startx, int starty);

#endif // GENMOVES_HPP
