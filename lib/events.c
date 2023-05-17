#include "events.h"
#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

Event *_event_queue;

void *Execute(Event *event) {
  if (event == NULL) {
    return NULL;
  }  

  if (event->args.Count == 0) {
    event->Operation(NULL);

    return NULL;
  }

  void *prms[event->args.Count];

  for (int i = 0; i < event->args.Count; i++) {
   prms[i] = event->args.value[i];
  }

  event->Operation(prms);

  return NULL;
}

void Queue(EventHandler *eh, Event *e) {
  eh->events[eh->evCounter] = e;
  eh->evCounter++;

  eh->events = realloc(eh->events, sizeof(Event *) * (eh->evCounter + 1));
}

void collapseEventQueue(EventHandler *eh) {
  if (eh->events[0] == NULL) {
    for (int i = 0; i < eh->evCounter; i++ ) {
      eh->events[i] = eh->events[i +1];
    }
  }
}

void LoadBuffer(EventHandler *eh) {  
    if (eh->Buffer == NULL) {
      eh->Buffer = malloc(sizeof(Event ));
      eh->Buffer = eh->events[0];

      eh->events[0] = NULL;

      collapseEventQueue(eh);
    
      eh->evCounter--;
      eh->events = realloc(eh->events, sizeof(Event *) * (eh->evCounter + 1));
    }
}

void UnLoadBuffer(EventHandler *eh) {
  if (eh->Buffer != NULL) {
    eh->Buffer = NULL;
  }
}

void *Start(void *ehndlr) {
  EventHandler *eh = ehndlr;

  const int TRUE = 1;
  
  while (TRUE) {
    
    for (int i = 0; i < eh->evCounter; i++) {
      LoadBuffer(eh);
      Execute(eh->Buffer);
      UnLoadBuffer(eh);
    }
  }

   return NULL; 
}