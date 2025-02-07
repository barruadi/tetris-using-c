#ifndef UTILS_H
#define UTILS_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

// Terminal control
#define CLEARSCREEN() printf("\033[H\033[J")
#define GOTO(X, Y) printf("\033[%d;%dH", (Y), (X))


#define ASSERT(CONDITION, MESSAGE) \
    if (!(CONDITION)) { \
        fprintf(stderr, "Assertion failed: %s\n", MESSAGE); \
        exit(EXIT_FAILURE); \
    }


#endif