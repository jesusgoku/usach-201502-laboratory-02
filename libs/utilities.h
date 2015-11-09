#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include <stdlib.h>
#include <stdbool.h>

#if defined POSIX
  #define CLEARSCR system ("clear")
#elif defined MSDOS || defined WIN32
  #define CLEARSCR system ("cls")
#endif

void pause();
void pauseAndClearScreen();
void pauseMessage(char *message);
void pauseMessageAndClearScreen(char *message);
void clearScreen();
bool readConfirmOption(char *message);

int ctoi(char c);

#endif
