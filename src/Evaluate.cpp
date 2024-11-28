#include <iostream>
#include <vector>
#include <string>   
#include <algorithm>
#include "Chessboard.hpp"
#include "GenMoves.hpp"

bool bbc(std::string race, int size) {
   if (race == "black" && size == 8) {
       return true;
   }
   else {
    return false;
   }
}   

