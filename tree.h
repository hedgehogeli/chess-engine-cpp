#ifndef __TREE_H__
#define __TREE_H__

#include <list>
#include <memory>

class Board;

class Tree {
    std::unique_ptr<Board> b; 
    
  public:

    std::list<std::unique_ptr<Tree>> children;

    Tree(Board& b);

    Board* board() { return b.get(); }
};

#endif