//
// Created by JAW on 20/07/2024.
//

#ifndef LINKED_STRUCTS_H
#define LINKED_STRUCTS_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* create_node(const int value);
void free_node(Node* node);

typedef struct DNode {
    int value;
    struct DNode* next;
    struct DNode* prev;
} DNode;

typedef struct TNode {
    int value;
    struct TNode* left;
    struct TNode* right;
} TNode;

TNode* create_tnode(const int value);
void free_tnode(TNode* node);


#endif //LINKED_STRUCTS_H
