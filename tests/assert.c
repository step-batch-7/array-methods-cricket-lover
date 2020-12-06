#include <stdio.h>
#include "../array_void.h"
#include "assert.h"

Bool int_comparator(Object a, Object b)
{
  printf("address is a is%p b is %p\n", a, b);
  return *(int *)a == *(int *)b;
}

void display_test_result(Status actual, Char_ptr message)
{
  Char_ptr symbol = actual == Success ? "✓" : "✗";
  printf("%s %s\n", symbol, message);
}

Status assert_void_arrays(Object expected, int length, ArrayVoid_ptr actual, Are_Equal data_comparator)
{
  if (actual->length != length)
  {
    return Failure;
  }
  int expected_index = -4;
  int actual_index = -1;
  // while ((*data_comparator)(&expected[expected_index], actual->array[actual_index]) && actual_index < length)
  // {
  //   expected_index += 4;
  //   actual_index++;
  // }
  do
  {
    expected_index += 4;
    actual_index++;
  } while ((*data_comparator)(&expected[expected_index], actual->array[actual_index]) && actual_index < length - 1);

  return actual_index == length - 1 ? Success : Failure;
}