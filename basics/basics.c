//
// Created by USER on 05/12/2023.
//

#include <stdio.h>
# include <stdlib.h>
#include <time.h>
#include "basics.h"

void swap(int *x, int *y);
int* create_array(size_t n);

void array_practice() {
    int size;

    printf("Define the size of the array: ");
    scanf("%d", &size);

    int our_arr[size];

    for (int i = 0; i < size; i++) {
        // Prints memory garbage
        printf("%d\n", our_arr[i]);
    }
}

void structures_practice() {
    Rectangle r; // Declaration
    Rectangle r2 = {10, 5}; // Declaration + Initialization

    printf("Size of the rectangle structure: %llu\n", sizeof(r));
    printf("Length of rectangle: %d\n", r2.length);
    printf("Area of rectangle: %d\n", r2.length * r2.breadth);
}

void pointers_practice() {
    int *int_pointer;
    char *char_pointer;
    float *float_pointer;
    int *arr_pointer[25];

    printf("%llu\n", sizeof(int_pointer));
    printf("%llu\n", sizeof(char_pointer));
    printf("%llu\n", sizeof(float_pointer));
    printf("%llu\n", sizeof(arr_pointer));

    // Declaring a pointer
    int *p;
    int *j;

    // Here we are assigning p a memory address allocated on the heap that holds 5 ints an int[5]
    p = (int *) malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        p[i] = (i + 1) * 10;
    }

    for (int i = 0; i < 5; i++) {
        printf("Memory from the heap stored in P %d: %d\n", i, p[i]);
    }

    // Only need to free memory that is allocated on the heap
    free(p);

    int a = 10;
    j = &a;
    printf("Memory from a that j is pointing to: %llu\n", j);
    printf("Dereferenced value of j: %d\n", *j);
    a = 20;
    printf("Dereferenced value of j after changin A: %d", *j);
}

void struct_pointer_practice() {
    Rectangle r = {10, 5};
    Rectangle *p = &r;

    printf("Len of Rect: %d\n", p->length);
    printf("Breadth of Rect: %d\n", (*p).breadth);

    Rectangle *p2 = (Rectangle *) malloc(sizeof(Rectangle));
    p2->length = 20;
    p2->breadth = 10;

    printf("Len of Rect: %d\n", p2->length);
    printf("Breadth of Rect: %d\n", (*p2).breadth);

    free(p2);
}

void swap_ints(int *x, int *y) {
    *x += *y;
    *y = *x - *y;
    *x = *x - *y;
}

void parameter_passing_practice() {
    int a = 10, b = 20;
    printf("Before: a = %d, b = %d\n", a, b);
    swap_ints(&a, &b);
    printf("After: a = %d, b = %d\n", a, b);
}

int* create_array(size_t n) {
    int* new_array = (int*) malloc(n * sizeof(int));
    printf("Created array with size: %zu\n", n);
    return new_array;
}

void array_passing_practice() {
    srand((unsigned)time(NULL));
    size_t size = rand() % 20;

    int* array = create_array(size);

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    printf("Items: ");
    for (int i = 0; i < size; i++) {
        printf("%d -> ", array[i]);
    }

    free(array);
}