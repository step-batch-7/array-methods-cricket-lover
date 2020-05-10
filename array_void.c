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