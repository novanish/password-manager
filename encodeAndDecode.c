#include "boolean.c"

static void transformer(int key, char **str, boolean should_encode) {
  key = should_encode ? key : -1 * key;

  for (int i = 0; (*str)[i] != '\0'; i++) {
    (*str)[i] += key;
  }
}

void decoder(int key, char **str) { transformer(key, str, false); }
void encoder(int key, char **str) { transformer(key, str, true); }