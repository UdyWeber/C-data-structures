//
// Created by JAW on 23/08/2024.
//

#include <stdlib.h>
#include "slice.h"

#include <stdio.h>


Slice *slice(int *original, const int start, const int end) {
    if (start < 0 || start > end) {
        fprintf(stderr, "Malformed start of slice");
        exit(-1);
    }

    Slice *s = malloc(sizeof(Slice));

    return s;
}

void print(const Slice *s) {
    printf("[");
    const size_t len = s->len;
    for (int i = 0; i < len; i++) {
        const int item = *(s->array + i);
        len - 1 != i ? printf("%d ", item) : printf("%d", item);
    }
    printf("]\n");
}

void check_bounds(const int index, const size_t len) {
    if (index < 0 || index > len - 1) {
        fprintf(stderr, "Slice out of bounds");
        exit(-1);
    }
}

int get_elem(const Slice *s, const int index) {
    check_bounds(index, s->len);
    return *(s->array + index);
}

void set_elem(const Slice *s, const int index, const int new_value) {
    check_bounds(index, s->len);
    *(s->array + index) = new_value;
}


void apply(const Slice *s, const applier_func f) {
    for (int i = 0; i < s->len; i++) {
        *(s->array + i) = f(*(s->array+i));
    }
}
