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

