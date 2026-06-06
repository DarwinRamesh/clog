#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

void array_init(array *ptr, size_t array_size_init ){
  
  ptr -> arr_size = 0;
  ptr -> byte_alloc = array_size_init;

  // mem needed for malloc
  
  size_t byte_to_alloc = ptr -> byte_alloc * sizeof(char*);

  printf("Initializing array, address @ %p\n", (void*)ptr);
  printf("Allocating memory to array : %zu bytes.\n", byte_to_alloc);
  
  ptr -> arr = malloc(byte_to_alloc);

  if (ptr->arr == NULL){
    printf("FATAL, memory alloc to dynamic array failed!\n");
  }

}

