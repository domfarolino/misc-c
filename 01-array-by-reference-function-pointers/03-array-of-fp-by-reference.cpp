#include <stdio.h>

/**
 * This program demonstrates passing a statically allocated
 * array of function pointers by reference. Hold your applause.
 */

int add(int a, int b) {
  int sum = a + b;
  printf("In add(), the sum of a and b: %d\n", sum);
  return sum;
}

int multiply(int a, int b) {
  int product = a * b;
  printf("In multiply(), the product of a and b: %d\n", product);
  return product;
}

int divide(int a, int b) {
  int quotient = a / b;
  printf("In divide(), the quotient of a and b: %d\n", quotient);
  return quotient;
}

template <size_t n>
// To not pass array by reference: (int(*array[])(int, int) {
void receiveArrayOfFunctionPointers(int(*(&array)[n])(int, int)) {
  printf("In receiveArrayOfFunctionPointers(), `sizeof array` yields: %lu\n", sizeof array);

  int (*add)(int, int) = array[0];
  int (*multiply)(int, int) = array[1];
  int (*divide)(int, int) = array[2];

  int sum = add(10, 20);
  int product = multiply(10, 20);
  int quotient = divide(10, 20);

  printf("Returned sum: %d\n", sum);
  printf("Returned product: %d\n", product);
  printf("Returned quotient: %d\n", quotient);
}

int main() {
  int (*array[3])(int, int);
  printf("In main(), `sizeof array` yields: %lu\n", sizeof array);
  array[0] = add;
  array[1] = multiply;
  array[2] = divide;
  receiveArrayOfFunctionPointers(array);
  return 0;
}
