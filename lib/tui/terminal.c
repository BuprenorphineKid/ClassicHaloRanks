#include <asm-generic/fcntl.h>
#include <bits/ioctl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include "terminal.h"

#define MV_CURS(Y, X) printf("\033[%d;%dH", Y, X)

#define CURS_UP printf("\033[A")
#define CURS_DOWN printf("\033[B")
#define CURS_RIGHT printf("\033[C")
#define CURS_LEFT printf("\033[D")

Cursor *NewCursor() {
  Cursor *c = malloc(sizeof(Cursor));

  MV_CURS(0, 0);

  c->x = 1;
  c->y = 1;

  return c;
}

void CursorUp(Cursor *c) {
  if (c->y <= 0) {
    return;
  }
  
  CURS_UP;
  c->y--;
}

void CursorDown(Cursor *c) {
  CURS_DOWN;
  c->y++;
}

void CursorRight(Cursor *c) {
  CURS_RIGHT;
  c->x++;
}

void CursorLeft(Cursor *c) {
  if (c->y <= 0) {
    return;
  }
  
  CURS_LEFT;
  c->x--;
}

Terminal *NewTerminal() {
  Terminal *t = malloc(sizeof(Terminal));

  struct winsize ws;

  int tty = open("/dev/tty", O_RDWR);
  
  ioctl(tty, TIOCGWINSZ, &ws);

  t->cols = ws.ws_col;
  t->rows = ws.ws_row;
  t->cursor = NewCursor();

  return t;
}
