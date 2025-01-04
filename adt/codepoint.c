
#include "codepoint.h"
Boolean codepoint_is_whitespace(Char32_t codePoint) {
    switch (codePoint) {
        case 9: // '\t'
        case 11: // '\x0b'
        case 12: // '\x0c'
        case 32: // ' '
        case 160: // '\xa0'
        case 65279: // '\ufeff'
        case 12288: // '\u3000'
        case 5760: // '\u1680'
        case 8192: // '\u2000'
        case 8193: // '\u2001'
        case 8194: // '\u2002'
        case 8195: // '\u2003'
        case 8196: // '\u2004'
        case 8197: // '\u2005'
        case 8198: // '\u2006'
        case 8200: // '\u2008'
        case 8201: // '\u2009'
        case 8202: // '\u200a'
        case 8287: // '\u205f'
        case 8199: // '\u2007'
        case 8239: // '\u202f'
            return TRUE;
        default:
            return FALSE;
    }
}

Boolean codepoint_is_line_terminators(Char32_t codePoint) {
    switch (codePoint) {
        case 10: // '\n'
        case 13: // '\r'
        case 8232: // '\u2028'
        case 8233: // '\u2029'
            return TRUE;
        default:
            return FALSE;
    }
}