#ifndef UI_H
#define UI_H

#include "../events.h"

typedef struct co_ordinates {
  int x, y;
} co_ord;

typedef struct {
  void *self;
  void (* Render)(void *);
  co_ord points;
} Renderable;


void Render(Renderable *);

typedef struct _Win {
  int id;
  co_ord points;
  struct {
    int height;
    int width;
  } dimensions;
  struct {
    char Left;
    char Right;
    char Top;
    char Bottom; 
  } border;
  struct {
    char *title;
   struct _Win **windows;
  } *content;
} Window;

Window *NewWindow(int, int, ...);

void *SetWinTitle(void **);

void *SetWinBorders(Window *, int, int, ...);

void *SetWinHeight(Window *, int);

void *SetWinWidth(Window *, int);

void *RenderWindow(Window *);

void *UpdateWindow(Window *);



#endif