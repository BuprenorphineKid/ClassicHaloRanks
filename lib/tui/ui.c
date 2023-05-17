#include "ui.h"
#include "../utils.h"

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define WIN_ID_LEN 3

#define WIN_HEIGHT 30
#define WIN_WIDTH 60

#define WIN_BORDER_LEFT '|'
#define WIN_BORDER_RIGHT '|'
#define WIN_BORDER_TOP '_'
#define WIN_BORDER_BOTTOM '_'

#define WIN_TITLE_LEN 32

void Render(Renderable *r) {
  r->Render(r);
}

Window *NewWindow(int x, int y, ...) {
  Window *window = malloc(sizeof(Window));

  window->id = Random(WIN_ID_LEN);
  window->points.x = x;
  window->points.y = y;

  va_list ap;

  va_start(ap, y);

  int h = va_arg(ap, int);

  if (&h == (int *)NULL) {
    return window;
  } else if (h <= 0) {
    window->dimensions.height = WIN_HEIGHT;
  } else {
    window->dimensions.height = h;
  }

  int w = va_arg(ap, int);
  
  if (&w == (int *)NULL) {
    return window;
  } else if (w <= 0) {
    window->dimensions.width = WIN_WIDTH;
  } else {
    window->dimensions.width = w;
  };


  char bL = va_arg(ap, int);

  if (&bL == (char *)NULL) {
    return window;
  } else if (bL <= 0) {
    window->border.Left = WIN_BORDER_LEFT;
  } else {
    window->border.Left = bL;
  }

  char bR = va_arg(ap, int);

  if (&bR == (char *)NULL) {
    return window;
  } else if (bR <= 0) {
    window->border.Right = WIN_BORDER_RIGHT;
  } else {
    window->border.Right = bR;
  }

  char bT = va_arg(ap, int);

  if (&bT == (char *)NULL) {
    return window;
  } else if (bT <= 0) {
    window->border.Top = WIN_BORDER_TOP;
  } else {
    window->border.Top = bT;
  }

  char bB = va_arg(ap, int);

  if (&bB == (char *)NULL) {
    return window;
  } else if (bB <= 0) {
    window->border.Bottom = WIN_BORDER_BOTTOM;
  } else {
    window->border.Bottom = bB;
  }

  window->content->windows = (Window **)NULL;
  window->content->title = NULL;
  
  return window;
}

void *SetWinTitle(void **args) {
  Window **window = args[0];
  
  const char *title = args[1];
  char buf[WIN_TITLE_LEN];

  strncpy(buf, title, strlen(title));

  (*window)->content->title = malloc(strlen(buf) * sizeof(char));
  (*window)->content->title = buf;

  printf("DEBUG PRINT :\n_____________\n\n win_title: %s\n", (*window)->content->title);
  return NULL;
}

void *SetWinBorders(Window *window, int left, int top, ...) {
  window->border.Left = (char)left;

  window->border.Top = (char)top;

  va_list ap;

  va_start(ap, top);

  char rBuf = va_arg(ap, int);

  if ((int *)&rBuf == NULL) {
    window->border.Right = window->border.Left;
    window->border.Bottom = window->border.Top;
  } else if ((int)rBuf <= 0) {
    window->border.Right = window->border.Left;
  } else {
    window->border.Right = rBuf;
  }


  char bBuf = va_arg(ap, int);
  
  if ((int *)&bBuf == NULL || (int)bBuf <= 0) {
    window->border.Bottom = window->border.Top;
  } else {
    window->border.Bottom = bBuf;
  }

  va_end(ap);

  return NULL;
}

void RenderWindow()