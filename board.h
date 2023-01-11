#ifndef __BOARD_H__
#define __BOARD_H__

#include "piece.h"
#include "board_util.h"
#include "attackArray.h"

#include <bitset>

/*
0x88 - square conversions
0x88square = rank*16 + (file - 1)
file = 0x88square & 7
rank = (0x88square & 112) + 1



*/

class Board {
  public:

    bool toMove; // toMove = true for White, false for Black
    char castling; // & operator w/ 1 = shortW, 2 = longW, 4 = shortB, 8 = longB
    size_t draw50; // counter for 50 move draw
    Square enpassant;

    Piece pieces[128];
    AttackArr attacks;


    Board();

    
    void clear();
    void fillSq(Piece piece, Square sq);
    void clearSq(Square sq);

    void load_fen(std::string fen);

    bool isAttacked(Square sq, bool toMove) {
        return attacks.isAttacked(sq, toMove);
    }

    // print method
    std::ostream& print(std::ostream &out);

};



#endif
