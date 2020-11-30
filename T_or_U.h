#pragma once

#define define_or(T, U)                       \
    typedef struct T##_or_##U {               \
        bool is1;                             \
        union {                               \
            T value1;                         \
            U value2;                         \
        };                                    \
    } T##_or_##U;                             \
                                              \
    T##_or_##U first_##T##_or_##U(T value) {  \
        T##_or_##U ret = {0};                 \
        ret.is1 = true;                       \
        ret.value1 = value;                   \
        return ret;                           \
    }                                         \
                                              \
    T##_or_##U second_##T##_or_##U(U value) { \
        T##_or_##U ret = {0};                 \
        ret.is1 = false;                      \
        ret.value2 = value;                   \
        return ret;                           \
    }

/*
does the T_or_U have a T value?

Input:
    T_or_U T_OR_U - The container
Output: bool
    true if"f the container has a T value
*/
#define is_first(T_OR_U) ((T_OR_U).is1)

/*
does the T_or_U have a U value?

Input:
    T_or_U T_OR_U - The container
Output: bool
    true if"f the container has a U value
*/
#define is_second(T_OR_U) (!(T_OR_U).is1)
