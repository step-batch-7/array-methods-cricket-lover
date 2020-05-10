#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

int main(void)
{
  ArrayVoid_ptr new_array = create_array_from(4);
  int *number_1 = malloc(sizeof(int));
  *number_1 = 1;
  int *number_2 = malloc(sizeof(int));
  *number_2 = 2;
  int *number_3 = malloc(sizeof(int));
  *number_3 = 3;
  int *number_4 = malloc(sizeof(int));
  *number_4 = 4;
  new_array->array[0] = number_1;
  new_array->array[1] = number_2;
  new_array->array[2] = number_3;
  new_array->array[3] = number_4;
  int *context = malloc(sizeof(int));
  Object result = reduce_void(new_array, context, &void_sum);
  display_int(result);
}