#include <stdio.h>
#include <stdlib.h>
#include "../adt/string.h"

typedef enum {
    VISUAL_SUCCESS = 0,
    VISUAL_ERR_INVALID_BLOCK = 1, // fixme
} VisualErrno;

VisualErrno display_input(String fragments, String *input) {
    // Find the location of 'X' in the fragments
    size_t x_location = 0;
    StringErrno string_err;
    string_err = string_character_index(fragments, &x_location, 'X');



    // Assuming a fixed width for the display, calculate x and y coordinates
    // int width = 80; // Example width, adjust as needed
    // int x = position % width;
    // int y = position / width;

    // Move the cursor to the position of 'X'
    printf("\033[%d;%zuH", 0 + 1, x_location + 1); // ANSI escape code for cursor positioning

    // Read input from the user
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return VISUAL_ERR_INVALID_BLOCK;
    }

    // Remove the newline character from the input
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
    
    // string_set(input, buffer);
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

#include "display_login.c"

int main(void) {
    String fragments = STRING_("Hello, X! How are you today?");
    String input;
    display_input(fragments, &input);
    printf("Input: %s\n", input.data);

    String display[] = {
        STRING_("Hello, X! How are you today?"),
        STRING_("I'm doing well, thank you!"),
        STRING_("What can I do for you today?")
    };
    // display_show(display, &input);

    return 0;
}