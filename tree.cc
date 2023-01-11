#include "tree.h"

Tree::Tree(Board& b) {
    board = std::make_unique<Board>(b);
}