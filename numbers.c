#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

int main(void)
{
  ArrayVoid_ptr new_array = create_array_from(4);
  int *number_1 = malloc(sizeof(int));
  *number_1 = 2;
  int *number_2 = malloc(sizeof(int));
  *number_2 = 3;
  int *number_3 = malloc(sizeof(int));
  *number_3 = 4;
  int *number_4 = malloc(sizeof(int));
  *number_4 = 5;
  new_array->array[0] = number_1;
  new_array->array[1] = number_2;
  new_array->array[2] = number_3;
  new_array->array[3] = number_4;
  display_array(new_array, &display_int);
}