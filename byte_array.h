#pragma once

#include "T_array.h"

typedef struct byte {
    union {
        unsigned char fullByte;
        struct {
            unsigned char bit1: 1;
            unsigned char bit2: 1;
            unsigned char bit3: 1;
            unsigned char bit4: 1;
            unsigned char bit5: 1;
            unsigned char bit6: 1;
            unsigned char bit7: 1;
            unsigned char bit8: 1;
        };
    };
} byte;

define_array(byte);

/*
Get the bit of the byte_array as if it was a bit array

Input:
    pArray - The array object
    index - The index in number of bytes after first
Output:
    A byte such that the first bit is the (index+1)th bit (other bits may not be zero)
*/
byte bit_array_get(byte_array* pArray, size_t index) {
    size_t byteIndex = index / sizeof(byte);
    size_t bitIndex = index % sizeof(byte);

    byte ret = (*array_index(pArray, byteIndex));
    ret.fullByte >> bitIndex;
    return ret;
}
