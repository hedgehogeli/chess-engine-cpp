#include "board.h"
// #include "piece.h"

#include <iostream>
#include <string>

void println(std::string msg) {
    std::cout << msg << std::endl;
}

std::ostream &operator<<(std::ostream &out, Board &b) {
    return b.print(out);
}

int main() {

    Board curBoard = Board();

    // curBoard.print(std::cout);
    std::cout << curBoard;

    // if ((Board::is_out(Board::sq(, 8)) ) {
    //     std::cout << "gfreat" << std::endl;
    // }
    
    
}
