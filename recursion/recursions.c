//
// Created by USER on 08/01/2024.
//
#include <stdio.h>

void add_till_ascending_time(int value, int target) {
    if (value != target) {
        printf("Value: %d, Target: %d\n", value, target);
        add_till_ascending_time(++value, target);
    }
}

void add_till_descending_time(int value, int target) {
    if (value != target) {
        add_till_descending_time(++value, target);
        printf("Value: %d, Target: %d\n", value, target);
    }
}

