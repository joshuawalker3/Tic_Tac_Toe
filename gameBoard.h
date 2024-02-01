//
// Created by joshua on 1/29/24.
//

#ifndef TIC_TAC_TOE_GAMEBOARD_H
#define TIC_TAC_TOE_GAMEBOARD_H

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

struct boardSpace{
    bool filled;
    char val;
};

struct boardSpace** initializeSpaces() {
    struct boardSpace** spacesArr = (struct boardSpace**)malloc(sizeof(struct boardSpace**) * 3);

    for (int i = 0; i < 3; i++) {
        spacesArr[i] = (struct boardSpace*)malloc(sizeof(struct boardSpace) * 3);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            spacesArr[i][j].filled = false;
            spacesArr[i][j].val = ' ';
        }
    }

    return spacesArr;
}


void printBoard(struct boardSpace** spaces) {

    int currentNum = 1;
    char currentChar = 'A';

    printf("  ");

    for (int i = 0; i < 11; i++) {
        if (i % 4 == 1) {
            printf("%d ", currentNum++);
        }
        else {
            printf("  ");
        }
    }

    printf("\n  ");

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (i % 4 != 3) {
                if (i % 4 == 1 && j % 4 == 1) {
                    printf("%c ", spaces[i / 4][j / 4].val);
                }
                else if (j % 4 != 3) {
                    printf("  ");
                }
                else {
                    printf("* ");
                }
            }
            else {
                printf("* ");
            }
        }

        if (i % 4 == 0) {
            printf("\n%c ", currentChar++);
        }
        else {
            printf("\n  ");
        }
    }
}

#endif //TIC_TAC_TOE_GAMEBOARD_H
