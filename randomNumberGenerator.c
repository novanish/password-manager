#include <stdlib.h>
#include <time.h>
#include "boolean.c"

static boolean initialized = false;

int generate_random_number(int min, int max)
{
    if (!initialized)
    {
        srand(time(NULL)); // initialize random seed}
        initialized = true;
    }

    return rand() % (max - min + 1) + min;
}