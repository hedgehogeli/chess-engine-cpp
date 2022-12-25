#ifndef __BOARD_UTIL_H__
#define __BOARD_UTIL_H__

#include <string>
#include <vector> 


static const std::string DEFAULT_FEN =
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";


enum Direction : signed char {
    NORTH = 0x10, NN = NORTH + NORTH,
    SOUTH = -NORTH, SS = SOUTH + SOUTH,
    EAST = 0x01,
    WEST = -EAST,
    NE = NORTH + EAST,
    SE = SOUTH + EAST,
    SW = SOUTH + WEST,
    NW = NORTH + WEST,
    NNW = NORTH + NW,
    NNE = NORTH + NE,
    ENE = EAST + NE,
    ESE = EAST + SE,
    SSE = SOUTH + SE,
    SSW = SOUTH + SW,
    WSW = WEST + SW,
    WNW = WEST + NW,

    LEFT = WEST * 7,
};

static const std::vector<Direction> royal_delta = {
    NORTH, NE, EAST, SE, SOUTH, SW, WEST, NW }; 
static const std::vector<Direction> rook_delta = {
    NORTH, EAST, SOUTH, WEST };
static const std::vector<Direction> bishop_delta = {
    NE, SE, SW, NW};
static const std::vector<Direction> knight_delta = {
    NNW, NNE, ENE, ESE, SSE, SSW, WSW, WNW};



enum Square : signed char { // TODO: probably need to remove signed char, just let it be an int
    A1=0x00, B1, C1, D1, E1, F1, G1, H1,
    A2=0x10, B2, C2, D2, E2, F2, G2, H2,
    A3=0x20, B3, C3, D3, E3, F3, G3, H3,
    A4=0x30, B4, C4, D4, E4, F4, G4, H4,
    A5=0x40, B5, C5, D5, E5, F5, G5, H5,
    A6=0x50, B6, C6, D6, E6, F6, G6, H6,
    A7=0x60, B7, C7, D7, E7, F7, G7, H7,
    A8=0x70, B8, C8, D8, E8, F8, G8, H8,
    OUT
};
Square operator++ (Square& sq);



enum File : unsigned char {
    FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H
};
File operator++ (File& f);
File operator-- (File& f);
File operator+= (File& f, int i);
File operator-= (File& f, int i);


enum Rank : unsigned char {
    RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8
};
Rank operator++ (Rank& f);
Rank operator-- (Rank& f);


bool is_out(const Square sq);
int file(const Square sq);
int rank(const Square sq);
Square sq(File col, Rank row);


#endif