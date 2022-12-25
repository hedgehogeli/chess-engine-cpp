#ifndef __BOARD_H__
#define __BOARD_H__

#include "piece.h"
#include "board_util.h"

#include <bitset>

/*
0x88 - square conversions
0x88square = rank*16 + (file - 1)
file = 0x88square & 7
rank = (0x88square & 112) + 1



*/

class Board {
    
    bool toMove; // toMove = true for White, false for Black
    char castling; // 1 = shortW, 2 = longW, 4 = shortB, 8 = longB
    size_t draw50; // counter for 50 move draw
    Square enpassant;

    Piece pieces[128];
    
  public:
    Board();

    
    void clear();
    void fillSq(Piece piece, Square sq);
    void clearSq(Square sq);

    void load_fen(std::string fen);

    // print method
    std::ostream& print(std::ostream &out);

};



#endif
