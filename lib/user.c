#include "user.h"

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

User *NewUser(const char *name) {
  User *u = malloc(sizeof(User));
  
  if (strcmp(name, "")) {
    strcpy(u->name, "DEFAULT_USER");
  } else {
    strcpy(u->name, name);
  }

  u->rank = 0;
  u->xp = 0;
  u->stats.deaths = 0;
  u->stats.kills = 0;
  u->stats.losses = 0;
  u->stats.wins = 0;

  return u;
}

void DelUser(User *usr) {
  free(usr);
}


void addxp(User *usr, int xp) {
  usr->xp = usr->xp + xp;
}

void renameUser(User *usr, const char *name) {
  if (strcmp(usr->name, name)) {
    return;
  }

  strcpy(usr->name, name);
}

void incDeaths(User *usr, ...) {
  va_list ap;
  va_start(ap, usr);

  int inc = va_arg(ap, int);

  if (inc < 0) {
    inc = 1;
  }

  usr->stats.deaths = usr->stats.deaths + inc;
}

void incKills(User *usr, ...) {
  va_list ap;
  va_start(ap, usr);

  int inc = va_arg(ap, int);

  if (inc < 0) {
    inc = 1;
  }

  usr->stats.kills = usr->stats.kills + inc;
}

void incWins(User *usr, ...) {
  va_list ap;
  va_start(ap, usr);

  int inc = va_arg(ap, int);

  if (inc < 0) {
    inc = 1;
  }

  usr->stats.wins = usr->stats.wins + inc;
}

void incLosses(User *usr, ...) {
  va_list ap;
  va_start(ap, usr);

  int inc = va_arg(ap, int);

  if (inc < 0) {
    inc = 1;
  }

  usr->stats.losses = usr->stats.losses + inc;
}

void incRank(User *usr, ...) {
  va_list ap;
  va_start(ap, usr);

  int inc = va_arg(ap, int);

  if (inc < 0) {
    inc = 1;
  }

  usr->rank = usr->rank + inc;
}