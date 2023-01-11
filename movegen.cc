#include "movegen.h"
#include "board.h"

int genMoves(Tree& t) {


    return t.children.size();
}

void genMoveCastle(Tree& t) {
    Board* b = t.board();
    bool wtm = b->toMove; // (white to move)

    if (wtm) {
        if (b->castling & 1) { // white kingside
            if (!b->pieces[F1] && !b->pieces[G1]
            && b->isAttacked(E1, !wtm)
            && b->isAttacked(F1, !wtm)
            && b->isAttacked(G1, !wtm)) {
                // TODO
            }
        }
        if (b->castling & 2) { // white queenside
            if (!b->pieces[B1] && !b->pieces[C1] && !b->pieces[D1]
            && b->isAttacked(C1, !wtm)
            && b->isAttacked(D1, !wtm)
            && b->isAttacked(E1, !wtm)) {
                // TODO
            }
        }
    } else {
        if (b->castling & 4) { // black kingside
            if (!b->pieces[F8] && !b->pieces[G8]
            && b->isAttacked(E8, !wtm)
            && b->isAttacked(F8, !wtm)
            && b->isAttacked(G8, !wtm)) {
                // TODO
            }
        }
        if (b->castling & 8) { // black queenside
            if (!b->pieces[B8] && !b->pieces[C8] && !b->pieces[D8]
            && b->isAttacked(C8, !wtm)
            && b->isAttacked(D8, !wtm)
            && b->isAttacked(E8, !wtm)) {
                // TODO
            }
        }
    }
}

void genMovePawnCapt(Tree& t, Square sq) {
    Board* b = t.board();
    bool wtm = b->toMove; // (white to move)

    if (wtm) {
        Square ne = Square(sq+NE); 
        if (!is_out(ne) && (b->enpassant==ne || b->pieces[ne] < 0)) {
            // TODO
        }
        Square nw = Square(sq+NW);
        if (!is_out(nw) && (b->enpassant==nw || b->pieces[nw] < 0)) {
            // TODO
        }
    } else {
        Square se = Square(sq+NE); 
        if (!is_out(se) && (b->enpassant==se || b->pieces[se] > 0)) {
            // TODO
        }
        Square sw = Square(sq+NW);
        if (!is_out(sw) && (b->enpassant==sw || b->pieces[sw] > 0)) {
            // TODO
        }
    }
}

void genMovePawn(Tree& t, Square sq) {

}


void genMovePieces(Tree& t, Square sq, Piece pc) {
    switch (pc) {
        case K:

        case Q: 
        
    }
}