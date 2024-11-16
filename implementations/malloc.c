//
// CREATED on JAW on 16/11/2024
//
// INFO: Implementation reference https://danluu.com/malloc-tutorial/ 

#include <assert.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

// Its naive because it only reserves the memory and give us a pointer
// It doesnt add any metadata to the memory block, so we cannot free the memory
// Because we don't know its size at runtime.
void *naive_malloc(size_t size) {
    if (size == 0) return NULL;

    // SBRK(0) returns the pointer to the top of the heap
    // SBRK(SIZE) moves the heap pointer to addr + SIZE and returns a pointer
    void *heap = sbrk(0);
    void *request = sbrk(size);

    // If request to move the heap fails it returns -1
    if (request == (void*) -1) {
        return NULL;
    } else {
        // We assert the heap's addr is equal the requested move addr
        // Because if the heap has moved both will point to the same addr.
        assert(heap == request);
        return heap;
    }
}

// Defining our abstract representation of 
// a memory block meta information
// Contains the size of the block to help us free the ptr
// Has a reference like a LL that point to the next "contiguous" memory block
// And has a flag to assert if it is freed
#define META_SIZE sizeof(struct BlockMeta)
struct BlockMeta {
    int free;
    size_t size;
    struct BlockMeta *next;
};

// We have to define a start for our memory linked list 
// Well make it a linked struct because we will want to 
// Reuse memory every time possible to make sure we dont
// waste any resources
void *global_base = NULL;

// First we have to iterate over the List to check if we already have a free space
// To avoid allocating when we can reuse. 
struct BlockMeta *find_free_block(struct BlockMeta **last, size_t size) {
    struct BlockMeta *current = global_base;

    // While iterating we check for blocks that have not been freed
    // And blocks that fits the memory requested 
    while(current != NULL && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }
    return current;
}

// If we dont' find any block that can fit the new memory requested
// We have to ask for the OS for a new memory block, and append it to the end of
// Our memory linked list
struct BlockMeta *request_space(struct BlockMeta *last, size_t size) {
    // We start pointing our memory block to the top of the heap
    struct BlockMeta *block = sbrk(0);
    // We request memory to fit users request + the metadata that's pointing to the heap
    void *requested = sbrk(size + META_SIZE);

    if (requested == (void*) -1) {
        return NULL;
    }

    // Assert that the block has been moved with the heap request
    assert((void *) block == requested);
    if (last != NULL) {
        last->next = block;
    }

    // Fill the information about the memory block
    block->size = size;
    block->next = NULL;
    block-> free = 0;
    return block;
}

void *my_malloc(size_t size) {
    struct BlockMeta *block;

    // Return freeable pointer of Null if 0 or less is passed
    if (size <= 0) return NULL;

    // First time allocating memory we have to setup the LL head
    if (global_base == NULL) {
        block = request_space(NULL, size);
        if (block == NULL) return NULL;
        global_base = block;
        return (block + 1);
    }

    // We use another pointer here to avoid modifying global base
    // If we modify it we will lose reference to the head of the LL
    struct BlockMeta *last = global_base;
    block = find_free_block(&last, size);

    // If could not find node that could fit the data
    // Asks the OS for another node and append it to the tail
    if (block == NULL) {
        block = request_space(last, size);
        if (block == NULL) return NULL;
    };

    // Just making sure the block is identified as freed
    block->free = 0;

    // Here we have to return the pointer incremented by one
    // Because we have to hide the memory block metadata
    // Since the block is the type of BlockMeta the +1 operation
    // Will jump exactly one BlockMeta size and will point to the free
    // Memory that we just allocated.
    return (block + 1);
}

// Helper function to get the pointer metadata
struct BlockMeta *get_ptr_metadata(void *ptr) {
    return (struct BlockMeta*)ptr - 1;
}

// Once allocated we have to able to free the memory
// In our case we are reusing data and taggin unused/free memory
// As free memory blocks to be later reused
// This will reuse the memory, and clean all allocated blocks
// After the program finishes
void my_free(void *ptr) {
    if (ptr == NULL) return;
    struct BlockMeta *meta = get_ptr_metadata(ptr);
    assert(meta->free == 0);
    ptr = NULL;
    meta->free = 1;
}

// Realloc will take a malloced pointer and will resize it
// If the pointer is big enough it will just return the pointer
// If it isnt the function will allocate a new block and free the provided ptr
void *my_realloc(void *ptr, size_t size) {
    // Should work exaclty like malloc when ptr == NULL
    if (ptr == NULL) return my_malloc(size);

    // Get the block metadata to ensure that we have enough space
    // To fit the new size
    struct BlockMeta *meta = get_ptr_metadata(ptr);
    if (meta->size >= size) return ptr;

    // If we dont have enough space we have to malloc a new block
    void *new_ref = my_malloc(size);
    if (new_ref == NULL) return NULL;

    // After creating a new memory block big enough
    // We have to copy the memory from one pointer to another
    // And free the original pointer
    memcpy(new_ref, ptr, meta->size);
    my_free(ptr);

    return new_ref;
}

// Calloc will just allocate like malloc but will default all
// Elements to 0
void *calloc(size_t number_elements, size_t element_size) {
    size_t size = number_elements * element_size;
    void *ptr = my_malloc(size);
    if (ptr == NULL) return NULL;
    memset(ptr, 0, size);
    return ptr;
}

// INFO: Section dedicated to resolve the exercises on the original article
void exercise1_malloc() {
    printf("Running exercise test, asserting if all data types can be used with my allocator\n");
}
