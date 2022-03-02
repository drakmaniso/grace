#ifndef ARRAY
#define ARRAY


#include <stdlib.h>
#include "global.h"


#define array_typedef(itemType) \
typedef struct {            \
    itemType *items;        \
    size_t length;          \
    size_t capacity;        \
} Array##itemType


#define array_new(itemType, cap)                             \
    (Array##itemType) {                                      \
        .items = (itemType*)calloc((cap), sizeof(itemType)), \
        .length = 0,                                         \
        .capacity = (cap)                                    \
    }

#define array_length(array) ((array).length)

#define array_push(array, item)                                                                 \
    if((array).length >= (array).capacity) {                                                    \
        (array).capacity *= 2;                                                                  \
        (array).items = realloc((array).items, (array).capacity * sizeof((array).items[0]));    \
    }                                                                                           \
    (array).items[(array).length] = item;                                                       \
    (array).length++;

#define array_at(array, index) ((index) >= 0 && (index) < (array).length ? (array).items[index] : (panic("*** Array: index out of bounds ***"), (array).items[0]))


#endif ARRAY