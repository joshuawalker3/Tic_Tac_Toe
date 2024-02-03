//
// Created by joshua on 2/2/24.
//

#include "gameBoard.h"

#ifndef TIC_TAC_TOE_GAMEPLAY_H
#define TIC_TAC_TOE_GAMEPLAY_H

struct game {
    struct boardSpace** spaces;
    bool xTurn;
};

char turnChar = 'X';
int turnCount = 0;
bool win = false;

struct game currentGame;

bool checkWin(struct boardSpace**);
bool checkRows(struct boardSpace**);
bool checkCols(struct boardSpace**);
bool checkDiagonal(struct boardSpace**);

void initializeGame() {
    currentGame.spaces = initializeSpaces();
    currentGame.xTurn = true;
    printBoard(currentGame.spaces);
}

void playGame() {
    while (!win && turnCount < 9) {
        bool validSpot = false;
        bool validRowInput = false;
        bool validColInput = false;

        if (currentGame.xTurn) { turnChar = 'X'; }
        else { turnChar = 'O'; }
        printf("It's %c's turn. Enter space you would like to fill! Example: A1   ", turnChar);

        char row = 'P';
        int col = 4;

        while (!validSpot || !validRowInput || !validColInput) {

            row = getchar();
            if (row > 67) { row -= 32; }
            if (row > 64 && row < 68) { validRowInput = true; }
            else {
                while(getchar() != '\n');
                printf("Invalid row entered. Please try again!\nIt's %c's turn. Enter space you would like to fill! Example: A1   ", turnChar);
            }

            if (validRowInput) {
                scanf("%d", &col);
                if (col > 0 && col < 4) { validColInput = true; }
                else {
                    validRowInput = false;
                    while(getchar() != '\n');
                    printf("Invalid column entered. Please try again!\nIt's %c's turn. Enter space you would like to fill! Example: A1   ", turnChar);
                }
            }

            if (validRowInput && validColInput) {
                if (currentGame.spaces[row - 65][col - 1].filled == false) { validSpot = true; }
                else {
                    while(getchar() != '\n');
                    printf("That spots already filled. Please try again!\nIt's %c's turn. Enter space you would like to fill! Example: A1   ", turnChar);
                }
            }
        }

        while(getchar() != '\n');

        currentGame.spaces[row - 65][col - 1].val = turnChar;
        currentGame.spaces[row - 65][col - 1].filled = true;

        printBoard(currentGame.spaces);

        turnCount++;

        if (turnCount >= 5) {
            win = checkWin(currentGame.spaces);
        }

        if (win) {
            printf("%c's won!!!!\n", turnChar);
        }

        if (!win && turnCount == 9) {
            printf("Stalemate. Try again.\n");
        }

        currentGame.xTurn = !currentGame.xTurn;
    }
}

bool checkWin(struct boardSpace** spaces) {
    if (checkRows(spaces)) { return true; }
    if (checkCols(spaces)) { return true; }
    if (checkDiagonal(spaces)) { return true; }

    return false;
}

bool checkRows(struct boardSpace** spaces) {
    for (int i = 0; i < 3; i++) {
        if (spaces[i][0].val == spaces[i][2].val && spaces[i][0].val == spaces[i][1].val && spaces[i][0].filled) { return true; }
    }

    return false;
}

bool checkCols(struct boardSpace** spaces) {
    for (int i = 0; i < 3; i++) {
        if (spaces[0][i].val == spaces[2][i].val && spaces[0][i].val == spaces[1][i].val && spaces[0][i].filled) { return true; }
    }

    return false;
}

bool checkDiagonal(struct boardSpace** spaces) {
    if (
            (spaces[0][0].val == spaces[2][2].val && spaces[0][0].val == spaces[1][1].val && spaces[0][0].filled)
            ||
            (spaces[2][0].val == spaces[0][2].val && spaces[2][0].val == spaces[1][1].val && spaces[2][0].filled)
            ) {
        return true;
    }

    return false;
}

void exitGame() {
    free(currentGame.spaces);
}

#endif //TIC_TAC_TOE_GAMEPLAY_H
