#ifndef __ASSERT_H
#define __ASSERT_H

typedef enum
{
  Failure,
  Success
} Status;
typedef Bool (*Are_Equal)(Object, Object);
typedef int *Int_ptr;
typedef char *Char_ptr;

Bool int_comparator(Object a, Object b);
void display_test_result(Status actual, Char_ptr message);
Status assert_void_arrays(Object expected, int length, ArrayVoid_ptr actual, Are_Equal data_comparator);

#endif