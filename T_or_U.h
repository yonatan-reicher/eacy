#pragma once

#define define_or(T, U)                       \
    typedef struct T##_or_##U {               \
        bool is1;                             \
        T value1;                             \
        U value2;                             \
    } T##_or_##U;                             \
                                              \
    T##_or_##U first_##T##_or_##U(T value) {  \
        return (T##_or_##U){true, value};     \
    }                                         \
                                              \
    T##_or_##U second_##T##_or_##U(U value) { \
        T##_or_##U ret = {0};                 \
        ret.value2 = value;                   \
        return ret;                           \
    }

#define is_first(T_or_U) (T_or_U.is1)
#define is_second(T_or_U) (!(T_or_U.is1))