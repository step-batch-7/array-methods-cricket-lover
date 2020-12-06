#include <stdio.h>
#include <stdlib.h>
#include "../array_void.h"
#include "assert.h"

void test_map_void(ArrayVoid_ptr new_array)
{
  int expected[4] = {1, 4, 9, 16};
  ArrayVoid_ptr actual = map_void(new_array, &void_square);
  Status status = assert_void_arrays(expected, 4, actual, &int_comparator);
  display_test_result(status, "Hey its working");
}

void run_tests(ArrayVoid_ptr new_array)
{
  printf("running tests......\n\n");
  test_map_void(new_array);
  printf("\n......finished tests\n");
}

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
  run_tests(new_array);
}