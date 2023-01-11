#ifndef __MOVEGEN_H__
#define __MOVEGEN_H__

#include "tree.h"

#include <list>
#include <memory>


// std::list<std::unique_ptr<Tree>> 
int genMoves(Tree& t);
void genMoveCastle(Tree& t);
void genMovePawn(Tree& t, Square sq);
void genMovePawnCapt(Tree& t, Square sq);
void genMovePieces(Tree& t, Square sq, Piece pc);

// sortMoves or sortChildren



#endif