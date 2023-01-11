#ifndef __ATTACK_ARRAY_H__
#define __ATTACK_ARRAY_H__

#include "board_util.h"

#include <utility>

struct AttackArr {
    unsigned short whiteCtrl, blackCtrl;
    std::pair<char, char> arr[128]; // (white, black)

    bool isAttacked(Square sq, bool attackedByWhite) {
        return attackedByWhite ? arr[sq].first : arr[sq].second;
    }

};

#endif
