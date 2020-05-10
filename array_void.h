#ifndef __ARRAY_VOID_H
#define __ARRAY_VOID_H
#include "array.h"

typedef void *Object;
typedef void (*DisplayData)(Object);
typedef Object (*MapperVoid)(Object);
typedef Bool (*PredicateVoid)(Object);
typedef Object (*ReducerVoid)(Object, Object);

typedef struct
{
  Object *array;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;

ArrayVoid_ptr create_array_from(int length);
void display_char(Object data);
void display_int(Object data);
void display_array(ArrayVoid_ptr array, DisplayData displayer);

Object void_square(Object a);
Bool void_filter_even(Object a);
Bool void_filter_vowels(Object alphabet);
Object void_sum(Object element, Object context);

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper);
ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate);
Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer);
#endif