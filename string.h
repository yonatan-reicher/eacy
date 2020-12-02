#pragma once

#include <string.h>

#include "T_array.h"

define_array(char);

typedef struct string {
    char_array inner;
} string;

void new_string(string* pstr, const char* cStr) {
    size_t size = strlen(cStr) + 1;  //  size of the inner array
    new_char_array(&pstr->inner, size);

    //  copy the string over
    memcpy(array_index(&pstr->inner, 0), cStr, size);
}

void copy_string(string* pDest, const string* pSource) {
    new_string(pDest, array_index(&pSource->inner, 0));
}

void move_string(string* pDest, string* pSource) {
    move_char_array(&pDest->inner, &pSource->inner);
}

void delete_string(string* str) { delete_char_array(&str->inner); }

size_t string_size(const string* str) {
    //  The inner array's size also refers to the last '\0' character
    //  while the string doesn't
    return str->inner.size - 1;
}

char* string_index(string* str, size_t i) {
    return array_index(&str->inner, i);
}

char* const_string_index(const string* str, size_t i) {
    return array_index(&str->inner, i);
}

/*
A slice of a string, a reference to a part of the string.
When the original string is destroyed this str points to 
destroyed memory and must not be used.
*/
typedef struct str {
    char* start;
    size_t size;
} str;
 
str str_of_cString(char* cString, size_t start, size_t length) {
    str ret = { &cString[start], length };
    return ret;
}

str str_of_string(string* pStr, size_t start, size_t length) {
    str ret = { string_index(pStr, start), length };
}

char* str_index(str slice, size_t i) {
    return &slice.start[i];
}

/*
The size of a str

Input:
    stringSlice - A string slice
Output:
    The size of the slice
*/
size_t str_size(str stringSlice) {
    return stringSlice.size;
}

