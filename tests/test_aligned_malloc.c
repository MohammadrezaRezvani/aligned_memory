#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include "aligned_malloc.h"

bool is_aligned(void* ptr, size_t alignment) {
    return ((uintptr_t) ptr & (alignment - 1)) == 0;
}

void test_aligned_malloc_alignment_16_size_100() {
    size_t alignment = 16;
    size_t size = 100;
    void* ptr = aligned_malloc(size, alignment);
    assert(ptr != NULL);
    assert(is_aligned(ptr, alignment));
    printf("alignment test with size 16 and alignment 100 passed!\n");
    aligned_free(ptr);
}

void test_aligned_malloc_alignment_32_size_200() {
    size_t alignment = 32;
    size_t size = 200;
    void* ptr = aligned_malloc(size, alignment);
    assert(ptr != NULL);
    assert(is_aligned(ptr, alignment));
    printf("alignment test with size 32 and alignment 200 passed!\n");
    aligned_free(ptr);
}

void test_aligned_malloc_alignment_64_size_300() {
    size_t alignment = 64;
    size_t size = 300;
    void* ptr = aligned_malloc(size, alignment);
    assert(ptr != NULL);
    assert(is_aligned(ptr, alignment));
    printf("alignment test with size 64 and alignment 300 passed!\n");
    aligned_free(ptr);
}

void test_aligned_malloc_alignment_128_size_400() {
    size_t alignment = 128;
    size_t size = 400;
    void* ptr = aligned_malloc(size, alignment);
    assert(ptr != NULL);
    assert(is_aligned(ptr, alignment));
    printf("alignment test with size 128 and alignment 400 passed!\n");
    aligned_free(ptr);
}

void test_aligned_malloc() {
    test_aligned_malloc_alignment_16_size_100();
    test_aligned_malloc_alignment_32_size_200();
    test_aligned_malloc_alignment_64_size_300();
    test_aligned_malloc_alignment_128_size_400();
}

int main() {
    printf("Running tests...\n");
    test_aligned_malloc();
    printf("All tests passed.\n");
    return 0;
}
