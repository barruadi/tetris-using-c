#include <stddef.h>
#include <stdint.h>

typedef uint8_t Char8_t;
typedef uint16_t Char16_t;
typedef uint32_t Char32_t;

#define STRING_(DATA) (String){.data = (Char8_t*) u8##DATA, .dataCapacity = sizeof(u8##DATA), .dataLength = sizeof(u8##DATA) - 1}

typedef struct {
    Char8_t *data;
    size_t dataCapacity;
    size_t dataLength;
} String;