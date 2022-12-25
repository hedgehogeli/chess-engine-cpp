#include "board_util.h"

#include <string>


Square operator++ (Square& sq) {
    if (is_out(static_cast<Square>(sq + EAST))) {
        return sq = static_cast<Square>(sq + LEFT + NORTH);
    } else return sq = static_cast<Square>(sq+EAST);
}




File operator++ (File& f) {
    return f = static_cast<File>((static_cast<unsigned char>(f) + 1));
}
File operator-- (File& f) {
    return f = static_cast<File>((static_cast<unsigned char>(f) - 1));
}
File operator+= (File& f, int i) {
    return f = static_cast<File>((static_cast<unsigned char>(f) + i));
}
File operator-= (File& f, int i) {
    return f = static_cast<File>((static_cast<unsigned char>(f) - i));
}



Rank operator++ (Rank& f) {
    return f = static_cast<Rank>((static_cast<unsigned char>(f) + 1));
}
Rank operator-- (Rank& f) {
    return f = static_cast<Rank>((static_cast<unsigned char>(f) - 1));
}



bool is_out(const Square sq) { return (sq & 0x88); };
int file(const Square sq) { return (sq & 7); }
int rank(const Square sq) { return (sq >> 4); }
Square sq(File col, Rank row) {  return Square(row * 0x10 + col); }

