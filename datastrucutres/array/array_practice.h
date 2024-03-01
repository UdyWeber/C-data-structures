//
// Created by USER on 23/01/2024.
//

#ifndef STUDYING_DATA_STRUCTURES_ARRAY_PRACTICE_H
#define STUDYING_DATA_STRUCTURES_ARRAY_PRACTICE_H

typedef struct Array {
    int *A;
    int size;
    int length;
} Array;

void resize_array();
void array_adt();
void creating_2D_arrays();
Array* merge_array(Array *a, Array *b);
void free_dynamic_array(Array *arr);
Array* create_dynamic_array(int size, int length);
void test_merge_array();
void test_set_union();
void test_set_intersection();
void test_set_difference();
void test_find_missing_element();
void test_find_multiple_missing_elements();
void test_find_multiple_missing_elements_sorted();
void display(Array *arr);

#endif //STUDYING_DATA_STRUCTURES_ARRAY_PRACTICE_H
