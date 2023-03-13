#include "boolean.c"

static void transformer(int key, char **str, boolean shouldEncode) {
  for (int i = 0; (*str)[i] != '\0'; i++) {
    if (shouldEncode) {
      (*str)[i] += key;
    } else {
      (*str)[i] -= key;
    }
  }
}

void decoder(int key, char **str) { transformer(key, str, false); }
void encoder(int key, char **str) { transformer(key, str, true); }