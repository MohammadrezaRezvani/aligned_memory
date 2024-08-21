#ifndef ALIGNED_MALLOC_H
#define ALIGNED_MALLOC_H

#include <stddef.h>

void* aligned_malloc(size_t size, size_t alignment);
void aligned_free(void* aligned_ptr);

#endif // ALIGNED_MALLOC_H