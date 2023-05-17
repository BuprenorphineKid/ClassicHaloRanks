#include "lib/events.h"
#include "lib/tui/ui.h"
#include "lib/tui/terminal.h"
#include "lib/user.h"
#include "lib/utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


EventHandler eventHandler = {
  Queue,
  Start,
  NULL,
  &_event_queue,
  0,
};

int main() {
  Terminal *t = NewTerminal();
/*
  eventHandler.events = (Event **)malloc(sizeof(Event *));

  pthread_t thr;
  
  pthread_create(&thr, NULL, eventHandler.Start, (void *)&eventHandler);

  

  Window *win1 = NewWindow(40, 30);

  const char *winName = "Testes";
  
  void **winTitleParams = malloc(sizeof(char) * strlen(winName) + sizeof(Window *));
  
  winTitleParams[0] = &win1;
  winTitleParams[1] = "Testes";
  
  Paramaters win_title_args = {
    2,
    winTitleParams,
  };
  
  Event win_title_change = {
    SetWinTitle,
    win_title_args,
  };


  printf("Before :\n\t%s\n\n\n", win1->content->title);

  eventHandler.Queue(&eventHandler, &win_title_change);

  printf("After :\n\t%s\n\n\n", win1->content->title);

  
  pthread_join(thr, NULL);
*/
}