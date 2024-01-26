//
// Created by USER on 23/01/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "array_practice.h"

void resize_array() {
    int *p1 = (int *) malloc(5 * sizeof(int));
    p1[0] = 1;
    p1[1] = 2;
    p1[2] = 9;
    p1[3] = 18;
    p1[4] = 6;

    int *p2 = (int *) malloc(10 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        p2[i] = p1[i];
    }

    free(p1);
    p1 = p2;
    p2 = NULL;

    for (int i = 0; i < 5; i++) {
        printf("P2[%d] = %d\n", i, p1[i]);
    }

    free(p1);

}

void creating_2D_arrays() {
    const int ARRAY_SIZES = 4;

    // All arrays created on the stack
    int A[3][4] = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };

    A[1][2] = 15;

    printf("Stack Array location X: 1 Y: 2 = %d\n", A[1][2]);

    // Half stack half heap
    int *B[3];

    for (int i = 0; i < 3; i++) {
        B[i] = (int *) malloc(ARRAY_SIZES * sizeof(int));
    }

    B[1][2] = 25;

    printf("Heap and Stack Array location X: 1 Y: 2 = %d\n", B[1][2]);

    for (int i = 0; i < 3; i++) {
        free(B[i]);
        B[i] = NULL;
    }

    // Full heap rsrsrs
    // A pointer to an array of array pointers all in heap
    int **C;

    C = (int **) malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; i++) {
        C[i] = (int *) malloc(ARRAY_SIZES * sizeof(int));
    }

    C[1][2] = 35;

    printf("Heap Array location X: 1 Y: 2 = %d\n", C[1][2]);

    for (int i = 0; i < 3; i++) {
        free(C[i]);
        C[i] = NULL;
    }

    free(C);
}

void display(Array *arr) {
    for (int i = 0; i < arr->length; i++) {
        if (i == arr->length - 1) {
            printf("%d", arr->A[i]);
            continue;
        }

        printf("%d - ", arr -> A[i]);
    }
}

void array_adt() {
    Array arr;
    int size, elements = 0;

    printf("Enter the array size: ");
    scanf("%d", &size);

    arr.size = size;
    arr.A = (int *) malloc(size * sizeof(int));

    while (true) {
        printf("Enter how many numbers are going to be filled: ");
        scanf("%d", &elements);

        if (elements > size || elements < 0) {
            printf("Elements cannot be bigger than the size of the array nor less\n");
            continue;
        }

        break;
    }

    for (int i = 0; i < elements; i++) {
        printf("\nPlease enter the number to be inserted in the array pos[%d]: ", i);
        scanf("%d", &arr.A[i]);

    }
    arr.length = elements;

    printf("\nDisplaying all filled array elements\n");
    display(&arr);
}