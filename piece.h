#ifndef __PIECE_H__
#define __PIECE_H__

// #include <bitset>
#include <map>

enum Piece : signed char { 
    k = -6, q, r, b, n, p, 
    EMPTY, 
    P, N, B, R, Q, K };

static const std::map<Piece, char> pieceToChar {
    {P, 'P'}, {N, 'N'}, {B, 'B'}, {R, 'R'}, {Q, 'Q'}, {K, 'K'},
    {EMPTY, ' '},
    {p, 'p'}, {n, 'n'}, {b, 'b'}, {r, 'r'}, {q, 'q'}, {k, 'k'},
};

#endif