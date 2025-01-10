#ifndef CODEPOINT_H
#define CODEPOINT_H

#include "../utils/boolean.h"
#include "string.h"
#include <stddef.h>

Boolean codepoint_is_whitespace(Char32_t codePoint);

Boolean codepoint_is_line_terminators(Char32_t codePoint);

#endif