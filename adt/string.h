#include <stddef.h>
#include <stdint.h>
#include "../utils/boolean.h"

#ifndef STRING_H
#define STRING_H

typedef uint8_t Char8_t;
typedef uint16_t Char16_t;
typedef uint32_t Char32_t;

typedef struct {
    Char8_t *data;
    size_t bufferCapacity;
    size_t bufferLength;
} String;

// TODO: adjust error code and add more
typedef enum {
    STRING_SUCCESS = 0,
    STRING_ERR_NULL_POINTER = 1,
    STRING_ERR_OUT_OF_BOUNDS = 2
} StringErrno;

// SELECTOR //
#define STRING_DATA(STRING) (STRING).data
#define STRING_BUFFER_CAPACITY(STRING) (STRING).bufferCapacity
#define STRING_BUFFER_LENGTH(STRING) (STRING).bufferLength


// Macro //

#define STRING_(DATA) (String){.data = (Char8_t*) u8##DATA, .bufferCapacity = sizeof(u8##DATA), .bufferLength = sizeof(u8##DATA) - 1}


// Constructor //

// String string_char_start();


// Basic Function //

StringErrno string_equals(String a, String b, Boolean *result);

StringErrno string_character_at(String string, size_t index, Char8_t *character);

StringErrno string_character_index(String string, size_t *index, Char8_t character);

StringErrno string_codepoint_at(String string, size_t *index, Char32_t *codePoint);


#endif