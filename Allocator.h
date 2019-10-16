//
// Created by tameer on 10/15/19.
//

#ifndef __ALLOCATOR_H__
#define __ALLOCATOR_H__
#define BLOCK_SIZE sizeof(_SBLOCK)


#include <stdio.h>
    typedef enum { FALSE ,TRUE} bool;
typedef struct MemoryAllocator MemoryAllocator;
typedef struct __s_block __s_block;


/* memoryPool is a ptr to an already-existing large memoryblock */
MemoryAllocator *MemoryAllocator_init(void *memoryPool, size_t size);

/* Returns a ptr to the memoryPool */
void *MemoryAllocator_release(MemoryAllocator *allocator);

void *MemoryAllocator_allocate(MemoryAllocator *allocator, size_t size);

/* Merge the next adjacent block is free */
void MemoryAllocator_free(MemoryAllocator *allocator, void *ptr);

/* Merges all adjacent free blocks, and returns the size oflargest free block */
size_t MemoryAllocator_optimize(MemoryAllocator *allocator);

#endif /* __ALLOCATOR_H__ */