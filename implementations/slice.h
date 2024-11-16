//
// Created by JAW on 23/08/2024.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef SLICE_H
#define SLICE_H

// Cannot change the other original array size
// When appending to slice needs to drop previous array and use another bigger (+5)
typedef struct {
    int *array;
    int startptr;
    int endptr;
    size_t len;
} Slice;


#define ALLOC_SLICE(orig_array, start, end) \
    ({ \
        Slice* ptr = (Slice*) malloc(sizeof(Slice)); \
        if (ptr == NULL) { \
            fprintf(stderr, "Error allocating slice"); \
            exit(-1); \
        } \
        ptr->array = orig_array + start; \
        ptr->len = end - start; \
        ptr; \
    })

typedef int (*applier_func)(int);

Slice *slice(int *original, int start, int end);
int get(const Slice *s, int index);
void set(const Slice *s, int index, int new_value);
void print(const Slice *s);
void apply(const Slice *s, applier_func);
#endif //SLICE_H
