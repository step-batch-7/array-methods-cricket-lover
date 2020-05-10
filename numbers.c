#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

int main(void)
{
  ArrayVoid_ptr new_array = create_array_from(4);
  char *number_1 = malloc(sizeof(char));
  *number_1 = 'a';
  char *number_2 = malloc(sizeof(char));
  *number_2 = 'b';
  char *number_3 = malloc(sizeof(char));
  *number_3 = 'c';
  char *number_4 = malloc(sizeof(char));
  *number_4 = 'i';
  new_array->array[0] = number_1;
  new_array->array[1] = number_2;
  new_array->array[2] = number_3;
  new_array->array[3] = number_4;
  display_array(new_array, &display_char);
  // ArrayVoid_ptr mapped = map_void(new_array, &void_square);
  // display_array(mapped, &display_int);
  ArrayVoid_ptr filtered = filter_void(new_array, &void_filter_vowels);
  display_array(filtered, &display_char);

}