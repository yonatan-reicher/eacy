#include <stdio.h>
#include "../T_array.h"

define_array(int)

int main() {
    int_array array;
    new_int_array(&array, 10);
    for (size_t i = 0; i < array.size; i++) {
        *array_index(&array, i) = i;
    }
    int_array copy;
    if (copy_int_array(&copy, &array) == false) {
        printf("Failed to copy array\n");
        return 1;
    }
    for (size_t i = 0; i < copy.size; i++) {
        if (*array_index(&copy, i) != i) {
            printf("Copy failed at index %zu\n", i);
            return 1;
        }
    }
    printf("Success!");
    return 0;
}
