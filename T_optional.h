#pragma once

#define define_optional(T)                                                 \
    typedef struct T##_optional {                                          \
        bool some;                                                         \
        T value;                                                           \
    } T##_optional;                                                        \
                                                                           \
    T##_optional some_##T(T value) { return (T##_optional){true, value}; } \
                                                                           \
    T##_optional none_##T() { return (T##_optional){false}; }

/*
Is the optional holding a value?

Input:
    const T_optional EXPR - The optional
Output: bool
    true if"f the optional get be called in get_some
*/
#define is_some(EXPR) ((EXPR).some)

/*
The value the optional holds

Input:
    const T_optional EXPR - The optional
Output: T
    The value the optional holds. 
    If the optional does not hold a value, this value is undefined.
*/
#define get_some(EXPR) ((EXPR).value)