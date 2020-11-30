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