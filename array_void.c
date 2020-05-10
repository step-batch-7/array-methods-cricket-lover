#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_array_from(int length)
{
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->length = length;
  new_array->array = malloc(sizeof(Object) * length);
  return new_array;
}
void display_char(Object data)
{
  printf("%c ", *(int *)data);
}

void display_int(Object data)
{
  printf("%d ", *(int *)data);
}

void display_array(ArrayVoid_ptr array, DisplayData displayer)
{
  for (int i = 0; i < array->length; i++)
  {
    displayer(array->array[i]);
  }
  printf("\n");
}

Object void_square(Object a)
{
  int *number = (int *)a;
  *number = *number * *number;
  return number;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr newArray = malloc(sizeof(ArrayVoid));
  newArray->length = src->length;
  newArray->array = malloc(sizeof(Object) * newArray->length);
  for (int i = 0; i < src->length; i++)
  {
    newArray->array[i] = (*mapper)(src->array[i]);
  }

  return newArray;
}
