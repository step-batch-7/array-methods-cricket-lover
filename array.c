#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int square_of_num(int a)
{
  return a * a;
}

Bool is_even(int a)
{
  return a % 2 == 0;
}

int add(int a, int b)
{
  return a + b;
}

Array_Ptr create_int_array_from(int *values, int length)
{
  Array_Ptr newArray = malloc(sizeof(Array));
  newArray->length = length;
  newArray->array = malloc(sizeof(int) * newArray->length);
  for (int i = 0; i < newArray->length; i++)
  {
    newArray->array[i] = values[i];
  }
  return newArray;
}

void display_int_array(Array_Ptr array)
{
  for (int i = 0; i < array->length; i++)
  {
    printf("%d ", array->array[i]);
  }
  printf("\n");
}

Array_Ptr map(Array_Ptr src, Mapper mapper)
{
  Array_Ptr newArray = malloc(sizeof(Array));
  newArray->length = src->length;
  newArray->array = malloc(sizeof(int) * newArray->length);
  for (int i = 0; i < src->length; i++)
  {
    newArray->array[i] = (*mapper)(src->array[i]);
  }

  return newArray;
}

Array_Ptr filter(Array_Ptr src, Predicate predicate)
{
  int temp_array[src->length];
  int count = 0;
  for (int i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
      temp_array[count] = src->array[i];
      count++;
    }
  }
  return create_int_array_from(temp_array, count);
}

int reduce(Array_Ptr src, int init, Reducer reducer)
{
  for (int i = 0; i < src->length; i++)
  {
    init = (*reducer)(init, src->array[i]);
  }
  return init;
}
