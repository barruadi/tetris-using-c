#ifndef UTILS_H
#define UTILS_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

// Terminal control
#define CLEARSCREEN() printf("\033[H\033[J")
#define GOTO(X, Y) printf("\033[%d;%dH", (Y), (X))


#define ASSERT(CONDITION, MESSAGE) \
    if (!(CONDITION)) { \
        fprintf(stderr, "Assertion failed: %s\n", MESSAGE); \
        exit(EXIT_FAILURE); \
    }

typedef enum {
    INPUT_KEY_SUCCESS = 0,
    INPUT_KEY_ERR_NO_KEY = 1,
    INPUT_KEY_ERR_UNKNOWN_KEY = 2,
    INPUT_KEY_ERR_INVALID_KEY = 3
} InputKeyErrno;


// Terminal control functions
InputKeyErrno utils_enable_raw_mode();

InputKeyErrno utils_kbhit();

InputKeyErrno utils_get_key_press(char *key);

InputKeyErrno utils_disable_raw_mode();

#endif