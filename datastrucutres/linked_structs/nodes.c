//
// Created by JAW on 20/07/2024.
//
#include "nodes.h";
#include <stdlib.h>;

Node* create_node(const int value) {
    Node *n = malloc(sizeof(Node));
    if (n != NULL) {
        n->value = value;
        n->next = NULL;
    }
    return n;
}

void free_node(Node* node) {
    if (node == NULL) {
        return;
    }
    if (node->next != NULL) {
        free_node(node->next);
    }
    free(node);
}