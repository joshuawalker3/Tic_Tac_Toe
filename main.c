#include <stdio.h>
#include "gameBoard.h"

int main() {
    struct boardSpace** spaces = initializeSpaces();
    printBoard(spaces);
    return 0;
}
