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

int square_of_num(int a);
Bool is_even(int a);
int add(int a, int b);
Array *create_int_array_from(int *values, int length);
void display_int_array(Array *array);

Array *map(Array *src, Mapper mapper);
Array *filter(Array *src, Predicate predicate);
int reduce(Array *src, int init, Reducer reducer);

#endif
