#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "board.h"
#include "colors.h"
#include "utilities.h"

void boardGame()
{
    clearScreen();
    printLogo();
    pauseMessageAndClearScreen(NULL);
    printInstruction();
    pauseMessageAndClearScreen(NULL);
    boardLoop();
}

void boardLoop()
{
    Board b;
    char inputOption;
    Coord source, dest;
    fillBoard(b);
    do {
        do {
            printGameScreen(b);
            inputOption = readValidOption("Ingrese la fila de origen", VALID_OPTIONS);
            if (isProgramOption(inputOption, VALID_PROGRAM_OPTIONS)) {
                break;
            }
            source.row = ctoi(inputOption);

            printGameScreen(b);
            inputOption = readValidOption("Ingrese la columna de origen", VALID_OPTIONS);
            if (isProgramOption(inputOption, VALID_PROGRAM_OPTIONS)) {
                break;
            }
            source.col = ctoi(inputOption);

            printGameScreen(b);
            inputOption = readValidOption("Ingrese la fila de destino", VALID_OPTIONS);
            if (isProgramOption(inputOption, VALID_PROGRAM_OPTIONS)) {
                break;
            }
            dest.row = ctoi(inputOption);

            printGameScreen(b);
            inputOption = readValidOption("Ingrese la columna de destino", VALID_OPTIONS);
            if (isProgramOption(inputOption, VALID_PROGRAM_OPTIONS)) {
                break;
            }
            dest.col = ctoi(inputOption);
        } while (0);

        switch (inputOption) {
            case 'q':
            case 'Q':
                if (readConfirmOption("¿Esta usted seguro?")) {
                    printf("Adios\n");
                } else {
                    inputOption = OPTION_NOTHING;
                }
                break;
            case 'h':
            case 'H':
                clearScreen();
                printInstruction();
                pauseMessage(NULL);
                break;
            case 'r':
            case 'R':
                fillBoard(b);
                break;
            case 'w':
            case 'W':
                printf("Win game step\n");
                break;
        }
    } while ('q' != inputOption);
}

char readValidOption(char *message, char *validOptions)
{
    char input;
    bool isValid;

    do {
        printf("%s: ", message);
        scanf("%c", &input);
        fpurge(stdin);
        isValid = isValidOption(input, validOptions);
        if (!isValid) {
            printf("\nOpción no valida! ...\n");
        }
    } while (!isValid);

    return input;
}

bool isValidOption(char input, char *validOptions)
{
    char c;
    for (int k = 0; '\0' != (c = validOptions[k]); ++k) {
        if (c == input) {
            return true;
        }
    }

    return false;
}

bool isProgramOption(char option, char *programOptions)
{
    return isValidOption(option, programOptions);
}

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
    printBoardColumnsNum(BOARD_COLS);

    for (int j = 0; j < BOARD_ROWS; ++j) {
        printBoardRowDivider(BOARD_COLS + 2);
        printf("| %d ", j);
        for (int k = 0; k < BOARD_COLS; ++k) {
            printf("| %s%c%s ", KGRN, b[j][k], KNRM);
        }
        printf("| %d |\n", j);
    }
    printBoardRowDivider(BOARD_COLS + 2);
    printBoardColumnsNum(BOARD_COLS);
}

void printBoardRowDivider(int cols)
{
    for (int k = 0; k < cols; ++k) {
        printf("+---");
    }
    printf("+\n");
}

void printBoardColumnsNum(int cols)
{
    printf("    ");
    for (int j = 0; j < cols; ++j) {
        printf("| %d ", j);
    }
    printf("|\n");
}

void printLogo()
{
    printf("  ____                      _ \n");
    printf(" | __ )  ___   __ _ _ __ __| |\n");
    printf(" |  _ \\ / _ \\ / _` | '__/ _` |\n");
    printf(" | |_) | (_) | (_| | | | (_| |\n");
    printf(" |____/ \\___/ \\__,_|_|  \\__,_|\n");
}

void printInstruction()
{
    printf("\nBoard Game\n\n");
    printf("\t01. Hello world\n");
    printf("\t02. Hello world\n");
    printf("\t03. Hello world\n");
    printf("\t04. Hello world\n");
}

void printProgramOptions()
{
    printf(
        "\n%c. Ayuda | %c. Reiniciar | %c. A punto | %c. Salir\n",
        OPTION_HELP,
        OPTION_RESTART,
        OPTION_WIN,
        OPTION_EXIT
    );
}

void printGameScreen(Board b)
{
    clearScreen();
    printBoard(b);
    printProgramOptions();
}

bool hasValidMovementsFromSource(Board b, Coord source)
{
    Coord dest, eat;
    dest.row = source.row - 2;
    dest.col = source.col;
    eat.row = source.row - 1;
    eat.col = source.col;

    if (dest.row >= 0 && dest.row) {
        return false;
    }

    return false;
}

bool isValidMovement(Board b, Coord source, Coord dest)
{
    return true;
}
