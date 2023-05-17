#ifndef EVENTS_H
#define EVENTS_H

#include <stddef.h>

typedef struct {
  int Count;
  void **value;
} Paramaters;

typedef struct {
  void *(*Operation)(void **params);
  Paramaters args;
} Event;

typedef struct _eh EventHandler;

typedef struct _eh {
  void (*Queue)(EventHandler *, Event *);
  void *(*Start)(void *);
  Event *Buffer;
  Event **events;
  int evCounter;
} EventHandler;

void Queue(EventHandler *, Event *);

void *Start(void *);

extern Event *_event_queue;

#endif
