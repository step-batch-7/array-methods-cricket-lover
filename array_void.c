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
void display_char(Object data)
{
  printf("%c ", *(int *)data);
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

Object void_square(Object a)
{
  int square_of_a = *(int *)a * *(int *)a;
  Object square = malloc(sizeof(int));
  *(int *)square = square_of_a;
  return square;
}

Bool void_filter_even(Object a)
{
  int number = *(int *)a;
  return number % 2 == 0 ? True : False;
}

Bool void_filter_vowels(Object a)
{
  char alphabet = *(char *)(a);
  Bool is_vowel = (alphabet == 'a') || (alphabet == 'e') || (alphabet == 'i') || (alphabet == 'o') || (alphabet == 'u');
  return is_vowel;
}

Object void_sum(Object element, Object context)
{
  int *number = (int *)context;
  *number = *(int *)context + *(int *)element;
  return number;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr newArray = malloc(sizeof(ArrayVoid));
  newArray->length = src->length;
  newArray->array = malloc(sizeof(Object) * newArray->length);
  for (int i = 0; i < src->length; i++)
  {
    newArray->array[i] = (*mapper)(src->array[i]);
  }

  return newArray;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  Object temp_array[src->length];
  int count = 0;
  for (int i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
      temp_array[count] = src->array[i];
      count++;
    }
  }
  ArrayVoid_ptr new_array = create_array_from(count);
  for (int j = 0; j < new_array->length; j++)
  {
    new_array->array[j] = temp_array[j];
  }
  return new_array;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  for (int i = 0; i < src->length; i++)
  {
    init = (*reducer)(src->array[i], init);
  }
  return init;
}
