//
// Created by JAW on 20/07/2024.
//

#include "binary_tree.h"

#include <stdio.h>

#include "../nodes.h"

#include <stdlib.h>


bool r_insert(TNode **current, const int value) {
    if(*current == NULL) {
        *current = create_tnode(value);
        return true;
    }

    TNode *curr = *current;

    if (curr->value > value) {
        return r_insert(&curr->left, value);
    }

    if (curr->value < value) {
        return r_insert(&curr->right, value);
    }

    return false;
}

BinaryTree *create_binary_tree() {
    BinaryTree *bt = malloc(sizeof(BinaryTree));
    if (bt != NULL) {
        bt->root = NULL;
    }
    return bt;
}

void free_binary_tree(BinaryTree *bt) {
    if (bt == NULL) {
        return;
    }

    free_tnode(bt->root);
    free(bt);
}

int r_find_height(const TNode *root) {
    if (root == NULL) {
        return 0;
    }
    const int left_height = r_find_height(root->left);
    const int right_height = r_find_height(root->right);

    return left_height > right_height ? left_height + 1 : right_height + 1;
}

int tree_height(const BinaryTree *bt) {
    if (bt == NULL) {
        return 0;
    }

    return r_find_height(bt->root);
}

void r_print_layer(const TNode *root, const int level, const int idx, const char name[]) {
    if (root == NULL) {
        return;
    }

    if (level == 0) {
        printf("[%s] Layer %d - %d\n", name, idx + 1, root->value);
    } else if (level > 0) {
        r_print_layer(root->left, level - 1, idx, "LEFT");
        r_print_layer(root->right, level - 1, idx, "RIGHT");
    }
}

void print_tree(const BinaryTree *bt) {
    if (bt == NULL) {
        return;
    }

    const int h = tree_height(bt);
    for (int i = 0; i < h; i++) {
        r_print_layer(bt->root, i, i, "ROOT");
    }
}

int r_dfs_inorder(const TNode* curr, int idx, int *nodes) {
    if (curr == NULL) {
        return 0;
    }

    idx += r_dfs_inorder(curr->left, idx, nodes);
    *(nodes+idx) = curr->value;
    idx += r_dfs_inorder(curr->right, idx, nodes);
}

int* dfs_inorder(BinaryTree *tree) {
    int *nodes = malloc(sizeof(int) * tree->len);
}

static bool insert(BinaryTree *tree, const int value) {
    if (tree == NULL) {
        return false;
    }

    const bool inserted = r_insert(&tree->root, value);

    if (inserted) {
        tree->len++;
    }

    return inserted;
}

void test_binary_tree_methods() {
    BinaryTree *bt = create_binary_tree();

    insert(bt, 12);
    insert(bt, 512);
    insert(bt, 14);
    insert(bt, 13);
    insert(bt, 8);
    insert(bt, 3);
    insert(bt, 9);
    printf("Tree height: %d\n", tree_height(bt));
    printf("Tree len: %d\n", bt->len);

    print_tree(bt);
    free_binary_tree(bt);
}
