#ifndef USER_H
#define USER_H

typedef struct {
  char name[32];
  int xp;
  int rank;
  struct {
    int kills;
    int deaths;
    int wins;
    int losses;
  } stats;
} User;

User *NewUser(const char *);

void DelUser(User *);

void addXp(User *, int);

void renameUser(User *, const char *);

void incWins(User *, ...);

void incLosses(User *, ...);

void incKills(User *, ...);

void incDeaths(User *, ...);

void incRank(User *, ...);
#endif
