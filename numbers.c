#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

int main(void)
{
  ArrayVoid_ptr new_array = create_array_from(4);
  int *numbers = malloc(sizeof(int) * new_array->length);
  *(numbers + 0) = 1;
  *(numbers + 1) = 2;
  *(numbers + 2) = 3;
  *(numbers + 3) = 4;

  new_array->array[0] = numbers + 0;
  new_array->array[1] = numbers + 1;
  new_array->array[2] = numbers + 2;
  new_array->array[3] = numbers + 3;
  int *context = malloc(sizeof(int));
  display_array(new_array, &display_int);
  ArrayVoid_ptr mapped = map_void(new_array, &void_square);
  display_array(mapped, &display_int);
  ArrayVoid_ptr filtered = filter_void(new_array, &void_filter_even);
  display_array(filtered, &display_int);
  return 0;
}