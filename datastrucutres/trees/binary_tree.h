//
// Created by JAW on 20/07/2024.
//

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "../nodes.h"
#include <stdbool.h>

typedef struct {
    TNode *root;
    int len;
} BinaryTree;

static bool insert(BinaryTree* tree, int value);
void test_binary_tree_methods();

#endif //BINARY_TREE_H
