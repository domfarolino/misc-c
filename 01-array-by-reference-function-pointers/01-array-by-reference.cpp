#include <stdio.h>

// Suppress -Wsizeof-array-argument errors which are helpful in warning you that
// your sizeof(arrayPtrHere) may not give you what you expect since the array decays (read on)
#pragma GCC diagnostic ignored "-Wsizeof-array-argument" // suppress -Wsizeof-array-argument warnings (#winning)

/**
 * In this program we create a "static" array of integers. In the function it
 * was created in, the length of the buffer that the array points to can be seen
 * by calling `sizeof arrayPtrHere`. When passing the array as an argument to a
 * function, the array "decays" to a pointer to the array's first element, meaning
 * `sizeof arrayPtrHere` will then yield the size of the pointer (expect 8 bytes)
 * instead of the logical array size. To allow the full static array to be preserved,
 * even as a function argument, we must pass it by reference. A static array can be
 * passed by reference by denoting in a function's prototype `int (&arrayName)[n]`
 * where `n` is either specified by the prototype as an integer, or prefaced with
 * `template <size_t n>` to work with any static array passed in.
 *
 * When a static array is passed by reference, it does not degrade to just a pointer,
 * so we can call things like `sizeof` on it with no worries. To pass a dynamically
 * allocated array by reference we can specify `int *&arrayPtr`. It should be noted
 * that dynamically allocated arrays are purely pointers, so `sizeof` will never yield
 * the logical size of the array buffer as it would with a "static" array.
 *
 * I use "static" here instead of just the word static, to denote that I mean the array
 * is statically allocated, and not declared literally as a static variable.
 */

void receiveArrayOfInts(int array[]) {
  printf("Inside receieveArrayOfInts(), sizeof array: %lu\n", sizeof array);
  printf("Address of array: %p\n", array);
}

template <size_t n>
void receiveArrayOfIntsByReference(int (&array)[n]) {
  printf("Inside receiveArrayOfIntsByReference(), sizeof array: %lu\n", sizeof array);
  printf("Address of array: %p\n", array);
}

void receiveArrayOfPointers(int* array[]) {
  printf("Inside receieveArrayOfPointers(), sizeof array: %lu\n", sizeof array);
  printf("Address of array: %p\n", array);
}

template <size_t n>
void receiveArrayOfPointersByReference(int* (&array)[n]) {
  printf("Inside receiveArrayOfPointersByReference(), sizeof array: %lu\n", sizeof array);
  printf("Address of array: %p\n", array);
}

int main() {
  int arrayOfInts[3], *arrayOfPointers[3];

  printf("Inside main(), sizeof arrayOfInts: %lu\n", sizeof arrayOfInts);
  printf("Address of arrayOfInts: %p\n", arrayOfInts);
  printf("Inside main(), sizeof arrayOfPointers: %lu\n", sizeof arrayOfPointers);
  printf("Address of arrayOfPointers: %p\n\n", arrayOfPointers);

  receiveArrayOfInts(arrayOfInts);
  receiveArrayOfIntsByReference(arrayOfInts);

  receiveArrayOfPointers(arrayOfPointers);
  receiveArrayOfPointersByReference(arrayOfPointers);
  return 0;
}
