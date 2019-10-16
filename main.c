#include <stdio.h>
#include "stdlib.h"
#include "Allocator.h"
int main() {
    printf("Hello, World!\n");
    char *memory = (char*)malloc(sizeof(char)*1000);
    MemoryAllocator* real_mem = MemoryAllocator_init(memory,1000);

    void * temp = MemoryAllocator_allocate(real_mem,33);
    printf("%p %p",real_mem,temp);

    return 0;
}