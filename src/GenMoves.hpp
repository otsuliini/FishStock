#ifndef GENMOVES_HPP
#define GENMOVES_HPP
#include <iostream>
#include <vector>
#include <string>   
#include <algorithm>
#include <Chessboard.hpp>
#include <fortnite.c>   
#include <MoveGen.cpp>


std::vector<std::string> generateAllMoves(bool turn); // DON'T READ SPAGHETTI CODE PLEASE
std::vector<std::string> genPawnMoves(bool turn, int startx, int starty);
std::vector<std::string> genKnightMoves(bool turn, int startx, int starty);
std::vector<std::string> genBishopMoves(bool turn, int startx, int starty) ;
std::vector<std::string> genRookMoves(bool turn, int startx, int starty) ;
std::vector<std::string> genQueenMoves(bool turn, int startx, int starty) ;
std::vector<std::string> genKingMoves(bool turn, int startx, int starty);

#endif