# eacy
A small, header only, macro-heavy, quality of life library

# Working Headers
* `T_array.h` - An array generic data structure
* `string.h` - A data structure for working with strings easier than `char*` types
* `T_optional.h` - A generic container that has one value or less
* `T_or_U.h` - A generic container that has one value of a type or another (a tagged union)

# How to use
### Data Structures
Types with functions such as `new_X`, `delete_X`, that are usually sent by reference, are what this library refers to as `Data Structures`

These functions share the same specific meaning in all `Data Structures`

* `new_X` - Initialize an `X` along with all it's memory. delete_X should be called after.
* `copy_X` - Initialize an `X` from another already existing `X` (Copies it's memory). delete_X should be called after on the copied-to object (and also on the copied-from object).
* `move_X` - Equivalent to copying from an object then deleting it.
* `delete_X` - Release the object's resources and memory.

##### Important notes:
* Do not copy or move data structures by hand (this is bad: `int_array array1 = array2`). Use the `copy_X` and `move_X` instead.
* Do not send any unspecified nulls into these functions

### generic types
Generic types are implemented using macros

Generic types define a macro `define_X(T)` which defines a type X in relation to T

For example, after calling `define_array(int)` in the top level of your program, you could
use the `int_array` type and `new_int_array` function 

##### Important notes:
* T should be a *named* type. For example `char*` is not a named type, but `char_ptr` is(from `typedef char char_ptr*`).
* You can call a `define_X(T)` multiple times, as long as it gets different parameters T
* If 2 `define_X(T)` make a conflict, try giving T a new name via `typedef`

# Installation
Simply put the headers in the same directly as you would your own headers and
add them to your IDE if you need

# WIP
* `shared_T_ptr.h` - A shared pointer type mimicking cpp's `std::shared_ptr<T>`
