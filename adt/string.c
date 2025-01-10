#include "string.h"

StringErrno string_equals(String a, String b, Boolean *result) {
    if (STRING_DATA(a) == NULL || STRING_DATA(b) == NULL) {
        return STRING_ERR_NULL_POINTER;
    }

    if (STRING_BUFFER_LENGTH(a) != STRING_BUFFER_LENGTH(b)) {
        *result = FALSE;
        return STRING_SUCCESS;
    }

    for (size_t i = 0; i < STRING_BUFFER_LENGTH(a); i++) {
        Char32_t codePointA;
        Char32_t codePointB;

        if (STRING_DATA(a)[i] != STRING_DATA(b)[i]) {
            *result = FALSE;
            return STRING_SUCCESS;
        }
    }

    *result = TRUE;
    return STRING_SUCCESS;
}

StringErrno string_character_at(String string, size_t index, Char8_t *character) {
    if (STRING_DATA(string) == NULL) {
        return STRING_ERR_NULL_POINTER;
    }

    if (index >= STRING_BUFFER_LENGTH(string)) {
        return STRING_ERR_OUT_OF_BOUNDS;
    }

    *character = STRING_DATA(string)[index];
    return STRING_SUCCESS;
}

StringErrno string_character_index(String string, size_t *index, Char8_t character) {
    if (STRING_DATA(string) == NULL) {
        return STRING_ERR_NULL_POINTER;
    }

    for (size_t i = 0; i < STRING_BUFFER_LENGTH(string); i++) {
        if (STRING_DATA(string)[i] == character) {
            *index = i;
            return STRING_SUCCESS;
        }
    }

    return STRING_ERR_OUT_OF_BOUNDS;
}

StringErrno string_codepoint_at(String string, size_t *index, Char32_t *codePoint) {
    if (STRING_DATA(string) == NULL) {
        return STRING_ERR_NULL_POINTER;
    }

    if (index >= STRING_BUFFER_LENGTH(string)) {
        return STRING_ERR_OUT_OF_BOUNDS;
    }

    *codePoint = STRING_DATA(string)[*index];
    return STRING_SUCCESS;
}