#include "encodeAndDecode.c"
#include <stdlib.h>
#include <time.h>

static boolean initialized = false;

int generate_random_number(int min, int max) {
  if (!initialized) {
    srand(time(NULL)); // initialize random seed}
    initialized = true;
  }

  return rand() % (max - min + 1) + min;
}

int get_int() {
  int n;
  scanf("%d", &n);

  return n;
}