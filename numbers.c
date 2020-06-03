#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

int main(void)
{
  ArrayVoid_ptr new_array = create_array_from(7);
  int *numbers = malloc(sizeof(int) * new_array->length);
  *(numbers + 0) = 5;
  *(numbers + 1) = 2;
  *(numbers + 2) = 10;
  *(numbers + 3) = 8;
  *(numbers + 4) = 13;
  *(numbers + 5) = 12;
  *(numbers + 6) = 7;

  new_array->array[0] = numbers + 0;
  new_array->array[1] = numbers + 1;
  new_array->array[2] = numbers + 2;
  new_array->array[3] = numbers + 3;
  new_array->array[4] = numbers + 4;
  new_array->array[5] = numbers + 5;
  new_array->array[6] = numbers + 6;
  // int *context = malloc(sizeof(int));
  // display_array(new_array, &display_int);
  // ArrayVoid_ptr mapped = map_void(new_array, &void_square);
  // display_array(mapped, &display_int);
  // ArrayVoid_ptr filtered = filter_void(new_array, &void_filter_even);
  // display_array(filtered, &display_int);
  // int a = *(int *)reduce_void(new_array, context, &void_sum);
  // printf("%d\n", a);
  display_array(new_array, &display_int);
  // bubble_sort(new_array, &compare_int);
  quick_sort(new_array, 0, new_array->length - 1, &compare_int);
  // selection_sort(new_array, &compare_int);
  display_array(new_array, &display_int);
  return 0;
}