//
// Created by JAW on 20/07/2024.
//

#include "nodes.h"
#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

SinglyLinkedList *create_list() {
    SinglyLinkedList *l = malloc(sizeof(SinglyLinkedList));
    if (l != NULL) {
        l->length = 0;
    }
    return l;
}

SinglyLinkedList *create_list_with_value(const int value) {
    SinglyLinkedList *l = create_list();
    l->head = create_node(value);
    if (l->head != NULL) {
        l->length = 1;
    }
    return l;
}

void free_list(SinglyLinkedList *l) {
    if (l == NULL) {
        return;
    }
    if (l->head != NULL) {
        free_node(l->head);
    }
    free(l);
}

static void append(SinglyLinkedList *list, const int value) {
    Node *new_node = create_node(value);

    if (list == NULL) {
        return;
    }

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *curr = list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }

    list->length++;
}

void preppend(SinglyLinkedList *list, const int value) {
    if (list == NULL) {
        return;
    }

    Node *new_node = create_node(value);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *oldHead = list->head;
        new_node->next = oldHead;
        list->head = new_node;
    }

    list->length++;
}

int insert_after(SinglyLinkedList *list, const int after, const int value) {
    if (list == NULL || list -> head == NULL) {
        return -1;
    }

    Node *curr = list->head;
    while(curr != NULL) {
        if (curr->value == after) {
            if (curr->next == NULL) {
                curr->next = create_node(value);
            } else if (curr->next != NULL) {
                Node *tmp = curr->next;
                curr->next = create_node(value);
                curr->next->next = tmp;
            }

            list->length++;
            return 1;
        }

        curr = curr->next;
    }

    return -1;
}

Node *prepop(SinglyLinkedList *list) {
    if (list == NULL || list->head == NULL) {
        return NULL;
    }

    Node *curr = list->head;
    list->head = curr->next;
    list->length--;

    curr->next = NULL;
    return curr;
}

Node *pop(SinglyLinkedList *list) {
    if (list == NULL || list->head == NULL) {
        return NULL;
    }
    Node *tmp = NULL;
    Node *curr = list->head;

    if (curr->next == NULL) {
        list->head = NULL;
        tmp = curr;
    } else {
        while (curr->next->next != NULL) {
            curr = curr->next;
        }

        tmp = curr->next;
        curr->next = NULL;
    }

    list->length--;
    tmp->next = NULL;
    return tmp;
}

int delete_after(SinglyLinkedList *list, const int value) {
    if (
        list == NULL
        || list->head == NULL
        || (list->head->next == NULL && list->head->value == value)
    ) {
        return -1;
    }

    Node *curr = list->head;
    while (curr->next != NULL) {
        if (curr->value == value) {
            Node *tmp = curr->next;
            curr->next = curr->next->next;

            // Free removed node
            tmp->next = NULL;
            free_node(tmp);
            tmp = NULL;

            list->length--;
            return 1;
        }
        curr = curr->next;
    }
    return -1;
}

int delete_value(SinglyLinkedList *list, const int value) {
    int returns = -1;

    if (list == NULL || list->head == NULL) {
        return returns;
    }

    if (list->head->next == NULL && list->head->value == value) {
        free_node(list->head);
        list->head = NULL;
        returns = 1;
    } else {
        Node *curr = list->head;

        while (curr->next != NULL) {
            if (curr->next->value == value) {
                // Fix list continuity
                Node *tmp = curr->next;
                curr->next = tmp->next;

                // Deassociate and free node
                tmp->next = NULL;
                free_node(tmp);
                tmp = NULL;

                list->length--;
                return 1;
            }

            curr = curr->next;
        }
    }

    list->length--;
    return returns;
}

int search(const SinglyLinkedList *list, const int value) {
    const Node *curr = list->head;
    while (curr != NULL) {
        if (curr->value == value) {
            return 1;
        }
    }
    return -1;
}

void apply_func(const SinglyLinkedList *list, const ApplyableFunc f) {
    if (list == NULL) {
        return;
    }

    Node *curr = list->head;
    while (curr != NULL) {
        curr->value = f(curr->value);
        curr = curr->next;
    }
}

void print_elements(const SinglyLinkedList *list, const bool in_line) {
    if (list == NULL) {
        return;
    }

    const Node *curr = list->head;
    if (in_line) {
        while (curr != NULL) {
            if (curr->next == NULL) {
                printf("%d\n", curr->value);
            } else {
                printf("%d - ", curr->value);
            }
            curr = curr->next;
        }
    } else {
        for (int i = 0; i < list->length; i++, curr = curr->next) {
            printf("%d - %d\n", i, curr->value);
        }
    }
    printf("Total length: %d\n", list->length);
}

int square(const int x) {
    return x * x;
}

void test_methods() {
    SinglyLinkedList *ll = create_list();

    // Add values
    append(ll, 5);
    preppend(ll, 3);
    append(ll, 32);
    preppend(ll, 12);
    insert_after(ll, 12, 420);
    insert_after(ll, 32, 69);

    // Apply transformations
    delete_after(ll, 5);
    apply_func(ll, square);
    free_node(pop(ll));
    delete_value(ll, 9);

    // Print everything
    print_elements(ll, true);

    // Free list
    free_list(ll);
}
