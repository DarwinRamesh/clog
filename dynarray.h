#ifndef DYNARRAY_H
#define DYNARRAY_H

typedef struct{
  char **arr;
  size_t arr_size;
  size_t byte_alloc;
}array;

void array_init(array *ptr, size_t array_size_init);

#endif

