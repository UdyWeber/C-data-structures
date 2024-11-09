//
// Created by JAW on 20/07/2024.
//
#include "nodes.h"
#include <stdlib.h>

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
    free_node(node->next);
    free(node);
}

TNode* create_tnode(const int value) {
    TNode *n = malloc(sizeof(TNode));
    if (n != NULL) {
        n->value = value;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

void free_tnode(TNode *node) {
    if (node == NULL) {
        return;
    }
    free_tnode(node->left);
    free_tnode(node->right);
    free(node);
}