//
// Created by tameer on 10/15/19.
//

#include "Allocator.h"
#include <stdlib.h>
typedef struct __s_block{
    bool isFree;
    size_t size;
}_SBLOCK;

typedef struct MemoryAllocator {
    void *memoryPool;
    size_t size;
    struct __s_block *free_blocks;
} MemoryAllocator;


MemoryAllocator *MemoryAllocator_init(void *memoryPool, size_t size){
    MemoryAllocator* mem = (MemoryAllocator*)malloc(sizeof(MemoryAllocator));

    mem->memoryPool = memoryPool;
    mem->size = size;
    mem->free_blocks = memoryPool;
    mem->free_blocks->size = size;
    mem->free_blocks->isFree=TRUE;
    (mem->free_blocks+size-1)->isFree = 0;
    (mem->free_blocks+size-1)->size = 0;
    return mem;
}

void *MemoryAllocator_allocate(MemoryAllocator *allocator, size_t size){
    _SBLOCK *temp = allocator->free_blocks;
    while((temp->isFree!=0 || temp->size!=0)){
        if (temp->isFree) {
            if (temp->size > size) {
                (temp + size)->size = temp->size - size;
                (temp + size)->isFree = 1;
                return temp + 1;
            }
        } else {
            temp = (temp + (temp->size));
        }
    }
}

void *MemoryAllocator_release(MemoryAllocator *allocator){
    return allocator->memoryPool;
}

void MemoryAllocator_free(MemoryAllocator *allocator, void *ptr){
    _SBLOCK * temp = (_SBLOCK*)ptr-1;
    temp->isFree = 1;
}

size_t MemoryAllocator_optimize(MemoryAllocator *allocator){
    size_t max = 0 ;
    _SBLOCK *temp = allocator->free_blocks;
    while((temp->isFree!=0 || temp->size!=0)){
        if(temp->isFree == 1){
            if(((temp+temp->size)->isFree)){
                temp->size += temp+temp->size;
                if(max<temp->size)
                    max = temp->size;
            }
        }else
            temp= temp+temp->size;
    }
    return max;

}