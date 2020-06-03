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
  printf("%c ", *(char *)data);
}

void display_int(Object data)
{
  printf("%d ", *(int *)data);
}

Bool compare_int(Object a, Object b)
{
  return *(int *)a < *(int *)b;
}

void display_array(ArrayVoid_ptr array, DisplayData displayer)
{
  for (int i = 0; i < array->length; i++)
  {
    (*displayer)(array->array[i]);
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
  ArrayVoid_ptr newArray = create_array_from(src->length);
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

void selection_sort(ArrayVoid_ptr numbers, Comparator compare_data)
{
  for (int i = 0; i < numbers->length; i++)
  {
    int index_of_min = i;
    for (int j = i + 1; j < numbers->length; j++)
    {
      if (compare_data(numbers->array[j], numbers->array[index_of_min]))
      {
        index_of_min = j;
      }
    }
    Object temp = numbers->array[index_of_min];
    numbers->array[index_of_min] = numbers->array[i];
    numbers->array[i] = temp;
  }
}

void bubble_sort(ArrayVoid_ptr numbers, Comparator compare_data)
{
  for (int i = 0; i < numbers->length; i++)
  {
    int swaps = 0;
    for (int j = 1; j < numbers->length; j++)
    {
      if (compare_data(numbers->array[j], numbers->array[j - 1]))
      {
        Object temp = numbers->array[j];
        numbers->array[j] = numbers->array[j - 1];
        numbers->array[j - 1] = temp;
        swaps++;
      }
    }
    if (swaps == 0)
    {
      break;
    }
  }
}

void swap(ArrayVoid_ptr numbers, int firstIndex, int secondIndex)
{
  Object temp = numbers->array[firstIndex];
  numbers->array[firstIndex] = numbers->array[secondIndex];
  numbers->array[secondIndex] = temp;
}

int partition(ArrayVoid_ptr numbers, int left, int right, Comparator compare_less_than)
{
  Object pivot = numbers->array[(int)((right + left) / 2)];
  while (left <= right)
  {
    while (compare_less_than(numbers->array[left], pivot))
    {
      left++;
    }
    while (compare_less_than(pivot, numbers->array[right]))
    {
      right--;
    }
    if (left <= right)
    {
      swap(numbers, left, right);
      left++;
      right--;
    }
  }

  return left;
}

void quick_sort(ArrayVoid_ptr numbers, int left, int right, Comparator compare_less_than)
{
  if (numbers->length <= 1)
  {
    return;
  }
  int index = partition(numbers, left, right, compare_less_than);

  if (left < index - 1)
  {
    quick_sort(numbers, left, index - 1, compare_less_than);
  }
  if (index < right)
  {
    quick_sort(numbers, index, right, compare_less_than);
  }
}