//
// Created by USER on 23/01/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "array_practice.h"
#include <errno.h>

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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_missing_element_sorted(Array *arr, int low) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] - i != low) {
            return low + i;
        }
    }

    return -1;
}

void find_multiple_missing_elements_sorted(Array *arr, int low) {
    int diff = low - 0;

    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] - i != diff) {
            while(diff < arr->A[i] - i) {
                printf("%d\n", diff + i);
                diff++;
            }
        }
    }
}
// Fastest way to find the missing elements
void find_multiple_missing_elements(Array *arr, int low, int high) {
    int x[high+1];
    int i;

    for(i = 0; i < high + 1; i++) {
        x[i] = 0;
    }

    for(i = 0; i < arr -> length; i++) {
        x[arr->A[i]] = 1;
    }

    for(i = low; i < high + 1; i++) {
        if (x[i] == 0) {
            printf("Missing: %d\n", i);
        }
    }
}

void test_find_multiple_missing_elements() {
    Array *a = create_dynamic_array(10, 9);
    a->A[0] = 6;
    a->A[1] = 9;
    a->A[2] = 7;
    a->A[3] = 13;
    a->A[4] = 11;
    a->A[5] = 12;
    a->A[6] = 19;
    a->A[7] = 15;
    a->A[8] = 16;

    find_multiple_missing_elements(a, 6, 19);
    free_dynamic_array(a);
}


void test_find_multiple_missing_elements_sorted() {
    Array *a = create_dynamic_array(10, 9);
    a->A[0] = 6;
    a->A[1] = 7;
    a->A[2] = 9;
    a->A[3] = 11;
    a->A[4] = 12;
    a->A[5] = 13;
    a->A[6] = 15;
    a->A[7] = 16;
    a->A[8] = 19;

    find_multiple_missing_elements_sorted(a, a->A[0]);
    free_dynamic_array(a);
}


void test_find_missing_element() {
    Array *a = create_dynamic_array(10, 9);
    a->A[0] = 6;
    a->A[1] = 7;
    a->A[2] = 8;
    a->A[3] = 9;
    a->A[4] = 10;
    a->A[5] = 11;
    a->A[6] = 12;
    a->A[7] = 13;
    a->A[8] = 14;

    printf("Found: %d", find_missing_element_sorted(a, a->A[0]));
    free_dynamic_array(a);
}

void resize(Array *arr) {
    int *new_array = (int *) malloc((arr->size + 1) * sizeof(int));

    if (new_array == NULL) {
        perror("Error allocating new resized array");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < arr->length; i++) {
        new_array[i] = arr->A[i];
    }

    free(arr->A);
    arr->A = new_array;
    arr->size++;
}

void display(Array *arr) {
    for (int i = 0; i < arr->length; i++) {
        if (i == arr->length - 1) {
            printf("%d", arr->A[i]);
            continue;
        }

        printf("%d -> ", arr->A[i]);
    }
}

void append(Array *arr, int append_value) {
    if (arr->length == arr->size) {
        resize(arr);
    }

    arr->A[arr->length] = append_value;
    arr->length++;
}

void insert(Array *arr, int value_to_insert, int index) {
    if (index > arr->length || index < 0) {
        perror("Cannot insert element outside of array bounds");
        exit(EXIT_FAILURE);
    }

    if (arr->length == arr->size) {
        resize(arr);
    }
    // Shift the elements to the end  of the array
    for (int i = arr->length; i > index; i--) {
        arr->A[i] = arr->A[i - 1];
    }
    // Insert new value into blank space
    arr->A[index] = value_to_insert;
    arr->length++;
}

int delete(Array *arr, int index) {
    if (index >= arr->length || index < 0) {
        perror("Cannot delete element outside of array bounds");
        exit(EXIT_FAILURE);
    }

    int deleted_value = arr->A[index];

    for (int i = index; i < arr->length; i++) {
        arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
    return deleted_value;
}

int linear_search(Array *arr, int value) {
    printf("Using linear search\n");

    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == value) {
            return i;
        }
    }
    return -1;
}

int binary_search(Array *arr, int value) {
    printf("Using binary search\n");

    int low = 0, high = arr->length;

    while (low <= high) {
        // Most robust method also could be
        // int middle = (high + low) / 2;
        int middle = low + (high - low) / 2;
        int target = arr->A[middle];

        if (value == target) {
            return middle;
        } else if (value > target) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }

    return -1;
}

int get(Array *arr, int index) {
    if (index < 0 || index > arr->size) {
        perror("Array out of bounds");
        exit(EXIT_FAILURE);
    }

    return arr->A[index];
}

void set(Array *arr, int index, int value) {
    if (index < 0 || index > arr->size) {
        perror("Array out of bounds");
        exit(EXIT_FAILURE);
    }

    arr->A[index] = value;
}

int max(Array *arr) {
    int max = arr->A[0];

    for (int i = 1; i < arr->length; i++) {
        if (arr->A[i] > max) {
            max = arr->A[i];
        }
    }

    return max;
}

int min(Array *arr) {
    int min = arr->A[0];

    for (int i = 1; i < arr->length; i++) {
        if (arr->A[i] < min) {
            min = arr->A[i];
        }
    }

    return min;
}

int sum(Array *arr) {
    int sum = 0;

    for (int i = 0; i < arr->length; i++) {
        sum += arr->A[i];
    }

    return sum;
}

int avg(Array *arr) {
    return sum(arr) / arr->length;
}

void insert_sorted(Array *arr, int value) {
    if (arr->length == arr->size) {
        resize(arr);
    }

    int i = arr->length - 1;
    while (arr->A[i] > value) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = value;
    arr->length++;
}

int is_sorted(Array *arr) {
    for (int i = 1; i < arr->length; i++) {
        if (arr->A[i - 1] > arr->A[i]) {
            return 0;
        }
    }

    return 1;
}

void reverse_with_array(Array *arr) {
    int pivot[arr->length];
    int i, j;

    for (i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        pivot[j] = arr->A[i];
    }

    for (i = 0; i < arr->length; i++) {
        arr->A[i] = pivot[i];
    }
}

void reverse_in_place(Array *arr) {
    for (int i = 0, j = arr->length - 1; i <= j; i++, j--) {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void left_shift(Array *arr, int times) {
    times = times % arr->length;

    int temp = arr->A[0];

    for (int t = 0; t < times; t++) {
        for (int i = 1; i < arr->length; i++) {
            arr->A[i - 1] = arr->A[i];
        }

        arr->A[arr->length - 1] = temp;
        temp = arr->A[0];
    }
}

void move_left_negatives(Array *arr) {
    int i = 0, j = arr->length - 1;

    while (i < j) {
        while (arr->A[i] < 0) {
            i++;
        }

        while (arr->A[j] >= 0) {
            j--;
        }

        if (i < j) {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}

Array *create_dynamic_array(int size, int length) {
    Array *result = malloc(sizeof(Array));
    result->size = size;
    result->length = length;
    result->A = malloc(result->size * sizeof(int));
    return result;
}

void free_dynamic_array(Array *arr) {
    free(arr->A);
    arr->A = NULL;
    free(arr);
}

Array *merge_array(Array *a, Array *b) {
    Array *result = create_dynamic_array(a->size + b->size, a->length + b->length);

    int i = 0, j = 0, k = 0;

    while (i < a->length && j < b->length) {
        if (a->A[i] <= b->A[j]) {
            result->A[k] = a->A[i++];
        } else {
            result->A[k] = b->A[j++];
        }

        k++;
    }

    while (i < a->length) {
        result->A[k++] = a->A[i++];
    }

    while (j < b->length) {
        result->A[k++] = b->A[j++];
    }

    return result;
}

Array *set_union_sorted(Array *a, Array *b) {
    Array *result = create_dynamic_array(a->size + b->size, 0);

    int i = 0, j = 0, k = 0;

    while (i < a->length && j < b->length) {
        if (a->A[i] < b->A[j]) {
            result->A[k] = a->A[i++];
        } else if (b->A[j] < a->A[i]) {
            result->A[k] = b->A[j++];
        } else {
            result->A[k] = a->A[i++];
            j++;
        }

        k++;
    }

    while (i < a->length) {
        result->A[k++] = a->A[i++];
    }

    while (j < b->length) {
        result->A[k++] = b->A[j++];
    }

    result->length = k;
    return result;
}

Array *set_union(Array *a, Array *b) {
    Array *result = create_dynamic_array(a->size + b->size, 0);
    int i = 0, j = 0, k = 0;

    // Dump first array into results
    while (i < a->length) {
        result->A[k++] = a->A[i++];
    }

    // Search in the result for the elements that exists and append if it doesn't
    while (j < b->length) {
        int exists = 0;

        for (i = 0; i < k; i++) {
            if (result->A[i] == b->A[j]) {
                exists = 1;
                break;
            }
        }

        if (!exists) {
            result->A[k++] = b->A[j];
        }

        j++;
    }

    result->length = k;
    return result;
}

Array *set_intersection(Array *a, Array *b) {
    Array *result = create_dynamic_array(a->size + b->size, 0);
    int i, j, k = 0;

    for (i = 0; i < a->length; i++) {
        for (j = 0; j < b->length; j++) {
            if (a->A[i] == b->A[j]) {
                result->A[k++] = a->A[i];
            }
        }
    }
    result->length = k;
    return result;
}

Array *set_difference(Array *a, Array *b) {
    Array *result = create_dynamic_array(a->size + b->size, 0);
    int i, j, k = 0;

    for (i = 0; i < a->length; i++) {
        int exist = 1;

        for (j = 0; j < b->length; j++) {
            if (a->A[i] == b->A[j]) {
                exist = 0;
                break;
            }
        }

        if (exist) {
            result->A[k++] = a->A[i];
        }
    }
    result->length = k;
    return result;
}

void test_merge_array() {
    Array *a = create_dynamic_array(2, 2);
    Array *b = create_dynamic_array(2, 2);

    a->A[0] = 1;
    a->A[1] = 12;
    b->A[0] = 1;
    b->A[1] = 36;

    Array *result = merge_array(a, b);
    display(result);

    free_dynamic_array(a);
    free_dynamic_array(b);
    free_dynamic_array(result);
}

void test_set_union() {
    Array *a = create_dynamic_array(4, 4);
    Array *b = create_dynamic_array(3, 3);

    a->A[0] = 14;
    a->A[1] = 1;
    a->A[2] = 102;
    a->A[3] = 59;
    b->A[0] = 1;
    b->A[1] = 12;
    b->A[2] = 36;

    Array *result = set_union(a, b);
    display(result);
    printf("\nSet len: %d\nSet size: %d\n", result->length, result->size);

    free_dynamic_array(a);
    free_dynamic_array(b);
    free_dynamic_array(result);
}

void test_set_intersection() {
    Array *a = create_dynamic_array(4, 4);
    Array *b = create_dynamic_array(3, 3);

    a->A[0] = 14;
    a->A[1] = 1;
    a->A[2] = 102;
    a->A[3] = 59;
    b->A[0] = 1;
    b->A[1] = 59;
    b->A[2] = 36;

    Array *result = set_intersection(a, b);
    display(result);
    printf("\nSet len: %d\nSet size: %d\n", result->length, result->size);

    free_dynamic_array(a);
    free_dynamic_array(b);
    free_dynamic_array(result);
}

void test_set_difference() {
    Array *a = create_dynamic_array(4, 4);
    Array *b = create_dynamic_array(3, 3);

    a->A[0] = 14;
    a->A[1] = 1;
    a->A[2] = 102;
    a->A[3] = 59;
    b->A[0] = 2;
    b->A[1] = 14;
    b->A[2] = 59;

    Array *result = set_difference(a, b);
    display(result);
    printf("\nSet len: %d\nSet size: %d\n", result->length, result->size);

    free_dynamic_array(a);
    free_dynamic_array(b);
    free_dynamic_array(result);
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

    int append_value;

    printf("\nEnter a number to be appended\n");
    scanf("%d", &append_value);

    append(&arr, append_value);
    display(&arr);

    int insert_value;

    printf("\nEnter a number to be inserted\n");
    scanf("%d", &insert_value);

    if (is_sorted(&arr)) {
        insert_sorted(&arr, insert_value);
    } else {
        int insert_index;

        printf("\nEnter a index from 0 to %d\n", arr.length);
        scanf("%d", &insert_index);

        insert(&arr, insert_value, insert_index);
    }

    display(&arr);

    int times_to_shift;

    printf("\nEnter the number of shifts you want to make\n");
    scanf("%d", &times_to_shift);
    left_shift(&arr, times_to_shift);
    display(&arr);

    int index_to_delete;

    printf("\nEnter a index from 0 to %d to be deleted\n", arr.length - 1);
    scanf("%d", &index_to_delete);

    printf("Successfully deleted value %d\n", delete(&arr, index_to_delete));
    display(&arr);

    int (*search_ptr)(Array *, int) = arr.length <= 5 ? linear_search : binary_search;

    int num_to_search;

    printf("\nType a number to see if it exists\n");
    scanf("%d", &num_to_search);

    int found_index = search_ptr(&arr, num_to_search);

    found_index == -1
    ? printf("Number %d not found\n", num_to_search)
    : printf("Found %d at index %d\n", num_to_search, found_index);

    printf("That's your reversed list: ");
    reverse_with_array(&arr);
    display(&arr);

    printf("\nThat's your re-reversed list: ");
    reverse_in_place(&arr);
    display(&arr);

    printf("\n Moving negatives to the left side\n");
    move_left_negatives(&arr);
    display(&arr);

    free(arr.A);
}