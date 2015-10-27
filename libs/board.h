#ifndef __BOARD_H__
#define __BOARD_H__

#define BOARD_ROWS 7
#define BOARD_COLS 7

#define BOARD_BLOQUED_ROWS 2
#define BOARD_BLOQUED_COLS 2

#define CELL_BLOQUED 'X'
#define CELL_EMPTY ' '
#define CELL_COIN 'O'

typedef char Board[BOARD_ROWS][BOARD_COLS];
typedef char Cell;

void fillBoard(Board b);
void printBoard(Board b);
void printBoardRowDivider(int cols);

#endif // __BOARD_H__
