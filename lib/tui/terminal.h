#ifndef CURSOR_H
#define CURSOR_H

#include <stddef.h>

#define TERM_CLEAR printf("\033[H\033[2J\033[3J")

typedef struct {
  int x, y;
} Cursor;

void CursorUp(Cursor *c);
void CursorDown(Cursor *c);
void CursorRight(Cursor *c);
void CursorLeft(Cursor *c);

typedef struct {
  int rows, cols;
  Cursor *cursor;
} Terminal;

Terminal *NewTerminal();

#endif
