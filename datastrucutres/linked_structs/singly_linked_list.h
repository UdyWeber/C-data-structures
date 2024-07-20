//
// Created by JAW on 20/07/2024.
//

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "nodes.h"
#include <stdbool.h>

typedef struct {
    int length;
    Node* head;
} SinglyLinkedList;

typedef int (*ApplyableFunc)(int);

SinglyLinkedList* create_list();
SinglyLinkedList* create_list_with_value(const int value);
void free_list(SinglyLinkedList* l);
static void append(SinglyLinkedList* list,int value);
void preppend(SinglyLinkedList* list, int value);
int insert_after(SinglyLinkedList* list, int value);
Node* prepop(SinglyLinkedList* list);
Node* pop(SinglyLinkedList* list);
int delete_after(SinglyLinkedList* list, int value);
int delete_value(SinglyLinkedList* list, int value);
int search(const SinglyLinkedList* list, int value);
void print_elements(const SinglyLinkedList* list, bool in_line);
void apply_func(const SinglyLinkedList* list, ApplyableFunc f);
void test_methods();

#endif //SINGLY_LINKED_LIST_H
