#ifndef __BOARD_H__
#define __BOARD_H__

#include <stdbool.h>

#define BOARD_ROWS 7
#define BOARD_COLS 7

#define BOARD_BLOQUED_ROWS 2
#define BOARD_BLOQUED_COLS 2

#define CELL_BLOQUED 'X'
#define CELL_EMPTY ' '
#define CELL_COIN 'O'

#define OPTION_EXIT 'q'
#define OPTION_HELP 'h'
#define OPTION_WIN 'w'
#define OPTION_RESTART 'r'
#define OPTION_NOTHING 'n'

#define VALID_OPTIONS "0123456qQhHwWrR"
#define VALID_PROGRAM_OPTIONS "qQhHwWrR"

typedef char Board[BOARD_ROWS][BOARD_COLS];
typedef char Cell;
typedef struct {
    int row;
    int col;
} Coord;

void boardGame();
void boardLoop();
void fillBoard(Board b);
void printBoard(Board b);
void printBoardRowDivider(int cols);
void printBoardColumnsNum(int cols);
void printLogo();
void printInstruction();
void printProgramOptions();
void printGameScreen(Board b);
char readValidOption(char *message, char *validOptions);
bool isValidOption(char input, char *validOptions);
bool isProgramOption(char option, char *programOptions);
bool hasValidMovementsFromSource(Board b, Coord source);
bool isValidMovement(Board b, Coord source, Coord dest);

#endif // __BOARD_H__
