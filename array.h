#ifndef __ARRAY_H
#define __ARRAY_H
typedef enum
{
  False,
  True
} Bool;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef struct
{
  int *array;
  int length;
} Array;
typedef Array *Array_Ptr;

int square_of_num(int a);
Bool is_even(int a);
int add(int a, int b);
Array_Ptr create_int_array_from(int *values, int length);
void display_int_array(Array_Ptr array);

Array_Ptr map(Array_Ptr src, Mapper mapper);
Array_Ptr filter(Array_Ptr src, Predicate predicate);
int reduce(Array_Ptr src, int init, Reducer reducer);

#endif
