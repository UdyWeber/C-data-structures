//
// Created by USER on 05/12/2023.
//

#ifndef STUDYING_DATA_STRUCTURES_BASICS_H
#define STUDYING_DATA_STRUCTURES_BASICS_H

void array_practice();
void structures_practice();
void pointers_practice();
void struct_pointer_practice();
void parameter_passing_practice();
void array_passing_practice();

// Takes 8 bytes of memory
typedef struct {
    int length;
    int breadth;
} Rectangle;

// Takes 8 bytes of memory
struct ComplexNum {
    int real;
    int img;
};

// Takes 89 bytes
struct Student {
    int age;
    char name[25];
    char dept[10];
    char address[50];
};

#endif //STUDYING_DATA_STRUCTURES_BASICS_H
