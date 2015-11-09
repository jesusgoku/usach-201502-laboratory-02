#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "utilities.h"

void pauseMessage(char *message)
{
    if (NULL != message) {
        printf("%s", message);
    } else {
        printf("Presione enter para continuar ...");
    }
    pause();
}

void pauseMessageAndClearScreen(char *message)
{
    pauseMessage(message);
    clearScreen();
}

void pause()
{
    getchar();
}

void pauseAndClearScreen()
{
    pause();
    clearScreen();
}

void clearScreen()
{
    system("clear");
}

bool readConfirmOption(char *message)
{
    char option;
    bool isValid;
    do {
        printf("%s (s/n): ", message);
        scanf("%c", &option);
        fpurge(stdin);
        option = tolower(option);
        isValid = 's' == option || 'n' == option;
        if (!isValid) {
            printf("\nOpción no valida! ...\n");
        }
    } while (!isValid);

    return 's' == option;
}

int ctoi(char c)
{
    return (int) c - '0';
}
