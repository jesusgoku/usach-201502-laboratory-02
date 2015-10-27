#include <stdio.h>

#include "board.h"

void fillBoard(Board b)
{
    Cell temp;
    for (int j = 0; j < BOARD_ROWS; ++j) {
        for (int k = 0; k < BOARD_COLS; ++k) {
            if (j == k && j == BOARD_ROWS / 2) {
                temp = CELL_EMPTY;
            } else if ((j < BOARD_BLOQUED_ROWS && k < BOARD_BLOQUED_COLS)
                || (j < BOARD_BLOQUED_ROWS && k >= (BOARD_COLS - BOARD_BLOQUED_COLS))
                || (j >= (BOARD_ROWS - BOARD_BLOQUED_ROWS) && k >= (BOARD_COLS - BOARD_BLOQUED_COLS))
                || (j >= (BOARD_ROWS - BOARD_BLOQUED_ROWS) && k < BOARD_BLOQUED_COLS)) {
                temp = CELL_BLOQUED;
            } else {
                temp = CELL_COIN;
            }

            b[j][k] = temp;
        }
    }
}

void printBoard(Board b)
{
    for (int j = 0; j < BOARD_ROWS; ++j) {
        printBoardRowDivider(BOARD_COLS);
        for (int k = 0; k < BOARD_COLS; ++k) {
            printf("| %c ", b[j][k]);
        }
        printf("|\n");
    }
    printBoardRowDivider(BOARD_COLS);
}

void printBoardRowDivider(int cols)
{
    for (int k = 0; k < cols; ++k) {
        printf("+---");
    }
    printf("+\n");
}
