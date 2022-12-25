#include "board.h"
#include "board_util.h"
#include "piece.h"

#include <iostream>

Board::Board() {
    load_fen(DEFAULT_FEN);
    // pieces[A1] = R;
    // pieces[H8] = r;
    // pieces[A8] = R;
}

void Board::clear() {
    for (int sq=0; sq<128; ++sq) { pieces[sq] = EMPTY; }
    toMove = true;
    castling = 0;
    enpassant = OUT;
    draw50 = 0;
}

void Board::fillSq(Piece piece, Square sq) {
    // if (is_out(sq)) { std::cout << "tf" << std::endl; }
    // std::cout << std::hex << sq << " set to " << static_cast<int>(piece) << std::endl;
    pieces[sq] = piece;
}

void Board::clearSq(Square sq) {
    pieces[sq] = EMPTY;
}

void Board::load_fen(std::string fen) {
    clear();

    int index = 0;

    File col = FILE_A;
    Rank row = RANK_8;

    while (fen[index] != ' ') {
        switch(fen[index]) {
            case 'K': fillSq(K, sq(col, row)); ++col; break;
            case 'Q': fillSq(Q, sq(col, row)); ++col; break;
            case 'R': fillSq(R, sq(col, row)); ++col; break;
            case 'B': fillSq(B, sq(col, row)); ++col; break;
            case 'N': fillSq(N, sq(col, row)); ++col; break;
            case 'P': fillSq(P, sq(col, row)); ++col; break;
            case 'k': fillSq(k, sq(col, row)); ++col; break;
            case 'q': fillSq(q, sq(col, row)); ++col; break;
            case 'r': fillSq(r, sq(col, row)); ++col; break;
            case 'b': fillSq(b, sq(col, row)); ++col; break;
            case 'n': fillSq(n, sq(col, row)); ++col; break;
            case 'p': fillSq(p, sq(col, row)); ++col; break;
            case '/':
                --row;
                col = FILE_A;
                break;
            case '1': col+=1; break;
            case '2': col+=2; break;
            case '3': col+=3; break;
            case '4': col+=4; break;
            case '5': col+=5; break;
            case '6': col+=6; break;
            case '7': col+=7; break;
            case '8': col+=8; break;
        };
        ++index;
    }

    // W or B to move
    if (fen[++index] == 'w') { toMove = true; }
    else { toMove = false; }

    index += 2;

    while (fen[index] != ' ') {
        switch( fen[index] ) {
            case 'K': castling |= 1; break;
            case 'Q': castling |= 2; break;
            case 'k': castling |= 4; break;
            case 'q': castling |= 5; break;
        };
        ++index;
    }

    if (fen[++index] != '-') { // en passant
        enpassant = sq(static_cast<File>(fen[index++] - 'a'), 
                            static_cast<Rank>(fen[index++] - '1'));
    } else { index += 2; }

    // parse int for halfway 50 rule
    draw50 = std::stoi(fen.substr(index, fen.find(' ', index) - index));

    // next int is move number, currently don't care.


}

std::ostream& Board::print(std::ostream &out) {
    int col = 1; 
    for (Square sq = A1; !is_out(sq); ++sq) {
        out << pieceToChar.at(pieces[sq]);
        
        ++col;
        if (col > 8) {
            col = 1;
            out << std::endl;
        }
    }
    return out;
}

