# chess-engine-cpp

Current general outline:

0x88 board representation 

support for FEN

connect to GUI

generate all possible moves (pseudo legal)

full legality check, (probably need to add attack array)

test # of possibilities against stockfish or smth else at depth 3 or 4 (perft)

quiescence search / removing horizon effect

come up with a heuristic

minimax

alpha beta pruning

transposition table

time constraints / go down depth 1 by 1, not arbitrary depth
