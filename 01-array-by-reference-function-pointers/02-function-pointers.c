#include <stdio.h>

int function1(int a) {
  printf("Landed in function 1 with a: %d\n", a);
  return 10;
}

int function2(int a) {
  printf("Landed in function 2 with a: %d\n", a);
  return 11;
}

int main() {
  // The right way to do it without losing information and maintaining proper types
  int (*arrayOfPointers[2])(int);

  // This is extra here
  int (*functionPointer1)(int) = function1;
  int (*functionPointer2)(int) = function2;
  arrayOfPointers[0] = functionPointer1;
  arrayOfPointers[1] = function2;

  // Call the functions via their addresses that now reside in `arrayOfPointers`
  arrayOfPointers[0](101);
  arrayOfPointers[1](102);
  return 0;
}
