#include <stdlib.h>
#include <stdint.h>
#include "aligned_malloc.h"

void* aligned_malloc(size_t size, size_t alignment) {
    size_t total_size = 
        size 
        + alignment - 1     // To make sure we have enough space to align
        + sizeof(void*);    // To store the pointer to original memory location

    void* original_ptr = malloc(total_size);
    if (!original_ptr) {
        return NULL;
    }

    // Make room for the original pointer
    uintptr_t aligned_ptr = (uintptr_t) original_ptr + sizeof(void*);
    
    // Align the pointer
    aligned_ptr = (aligned_ptr + alignment - 1) & ~(alignment - 1);
    
    // Store the original pointer
    ((void**) aligned_ptr)[-1] = original_ptr;

    return (void*) aligned_ptr;
}

void aligned_free(void* aligned_ptr) {
    if (aligned_ptr) 
        free(((void**) aligned_ptr)[-1]);
}