#include <stdio.h>
#include <stdlib.h>
#include "../adt/string.h"

typedef enum {
    VISUAL_SUCCESS = 0,
    VISUAL_ERR_INVALID_BLOCK = 1, // fixme
} VisualErrno;

VisualErrno display_input(String *input) {
    
    return VISUAL_SUCCESS;
};

// TODO: display_input inside box
// step 1: using identifier in the format
// step 2: using gotoxy to set the position of the cursor
// step 3: use scnaf and parse the \n
// step 4: rewrite the entire display

VisualErrno display_show(String *display[], String *input) {
    size_t __displayLength__ = sizeof(&display) / sizeof(&display[0]);
    printf("Display length: %zu\n", __displayLength__);
    for (size_t i = 0; i < __displayLength__; i++) {
        printf("%s\n", display[i]->data);
    }
    return VISUAL_SUCCESS;
}

