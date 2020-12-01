#pragma once

#include <inttypes.h>
#include "T_array.h"

#define BITS_IN_BYTE 8

typedef struct byte {
    union {
        uint8_t fullByte;
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

/*
Turn an uint8_t value to a byte value
*/
byte byte_of_uint8(uint8_t i) {
    byte ret = { 0 };
    ret.fullByte = i;
    return ret;
}

define_array(byte);

/*
Get the bit of the byte_array as if it was a bit array

Input:
    pArray - The array object
    index - The index in number of bytes after first
Output:
    A byte such that the first bit is the (index+1)th bit and the 
    rest of the bits are the bits directly after
*/
byte bit_array_get(byte_array* pArray, size_t index) {
    size_t byteIndex = index / BITS_IN_BYTE;
    size_t bitIndex = index % BITS_IN_BYTE;

    uint16_t ret = *(uint16_t*)array_index(pArray, byteIndex);
    ret = ret >> bitIndex;
    return byte_of_uint8((uint8_t)ret);
}

/*
Set the bit of the byte_array as if it was a bit array

Input:
    pArray - The array object
    index - The index in number of bytes after first
*/
void bit_array_set(byte_array* pArray, size_t index, bool value) {
    size_t byteIndex = index / BITS_IN_BYTE;
    size_t bitIndex = index % BITS_IN_BYTE;

    byte* oldByte = array_index(pArray, byteIndex);
    
    byte bitfield = byte_of_uint8(value ? 1 : 0);
    bitfield.fullByte = bitfield.fullByte << bitIndex;
     
    oldByte->fullByte &= ~bitfield.fullByte;
    oldByte->fullByte |= bitfield.fullByte;
}
