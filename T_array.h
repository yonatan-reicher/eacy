#pragma once

#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Declare a type named T##_array and some functions

T is a named type
*/
#define define_array(T)                                               \
    /*  A dynamic T array */                                          \
    typedef struct T##_array {                                        \
        T *start;                                                     \
        size_t size;                                                  \
    } T##_array;                                                      \
                                                                      \
    /*  Allocate an array object of size `size` */                    \
    bool new_##T##_array(T##_array *parray, size_t size) {            \
        parray->size = size;                                          \
        parray->start = (T *)malloc(size * sizeof(T));                \
        return parray->start != NULL;                                 \
    }                                                                 \
                                                                      \
    /*  Create a copy of an array */                                  \
    bool copy_##T##_array(T##_array *dest, const T##_array *source) { \
        size_t size = array_size(*source);                            \
                                                                      \
        bool success = new_##T##_array(dest, size);                   \
        if (success == false) {                                       \
            return false;                                             \
        }                                                             \
        memcpy(dest->start, source->start, size * sizeof(T));         \
    }                                                                 \
                                                                      \
    /*  Frees the memory owned by array ands nulls it */              \
    void delete_##T##_array(T##_array *parray) {                      \
        free(parray->start);                                          \
        parray->start = NULL;                                         \
    }

/*
Get a pointer to the array

Input:
    [const] T##_array* ARRAY - a pointer to the array
    size_t I - the index
Output: [const] T*
    A pointer to the element at the index,
    if the array is constent the pointer will be constent
*/
#define array_index(ARRAY, I) (&(ARRAY)->start[I])

/*
Get a size of the array

Input:
    const T##_array* ARRAY - pointer to the array
Output: size_t
*/
#define array_size(ARRAY) ((ARRAY)->size)

/*
Iterate through the array

Input:
    [const] T##_array* ARRAY -
        pointer to the array (notice, executed more than once)
    [const] T* P_ELEMENT -
        pointer to the current element (notice, executed more than once)
    BLOCK - A single statement or curly-braced block to execute
*/
#define foreach(ARRAY, P_ELEMENT, BLOCK)                                  \
    for ((P_ELEMENT) = (ARRAY)->start;                                    \
         (P_ELEMENT) < (ARRAY)->start + array_size(ARRAY); (P_ELEMENT)++) \
    BLOCK
