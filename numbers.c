#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(void)
{
  Array_Ptr numbers = malloc(sizeof(Array));
  numbers->length = 4;
  numbers->array = malloc(sizeof(int) * numbers->length);
  numbers->array[0] = 2;
  numbers->array[1] = 3;
  numbers->array[2] = 4;
  numbers->array[3] = 5;
  printf("Original array: ");
  display_int_array(numbers);

  Array_Ptr squares = map(numbers, square_of_num);
  Array_Ptr evens = filter(numbers, is_even);
  int sum = reduce(numbers, 0, add);

  printf("Mapped array with squares: ");
  display_int_array(squares);
  printf("Even filtered array: ");
  display_int_array(evens);
  printf("sum is %d\n", sum);
}