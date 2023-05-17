#include "utils.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

int Random(int size) {
  char str[size];

  srand(time(NULL));
  unsigned int r1 = rand();

  sleep(1);

  srand(time(NULL));
  unsigned int r2 = rand();

  unsigned long r3 = (long)(100.00 * (r2 * r1) / 9999 + 1000);

  int r4 = r3;

  char buf[size];
  
  sprintf(buf, "%d", r4);
  
  strcpy(str, buf);
  
  str[size] = '\0';
  
  return strtol(str, NULL, 10);
}