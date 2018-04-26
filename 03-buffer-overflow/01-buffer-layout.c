#include <stdio.h>

void secretFunction() {
  printf("You've been hacked\n");
}

void test() {
  int buffer[4];
  int buffer2[4];
  printf("Stack layout:\n");
  printf("Buffer:\n");
  printf("%p  buffer[3]\n", buffer + 3);
  printf("%p  buffer[2]\n", buffer + 2);
  printf("%p  buffer[1]\n", buffer + 1);
  printf("%p  buffer[0]\n", buffer);
  /////////////////////////////////////
  printf("Buffer2:\n");
  printf("%p  buffer2[3]\n", buffer2 + 3);
  printf("%p  buffer2[2]\n", buffer2 + 2);
  printf("%p  buffer2[1]\n", buffer2 + 1);
  printf("%p  buffer2[0]\n", buffer2);
  /////////////////////////////////////
  printf("Let's reach a single int past the end of buffer 2 (at %p), and set its value to `10`\n", buffer2 + 4);
  *(buffer2 + 4) = 10;
  /////////////////////////////////////
  printf("Now buffer[0]: %i\n", buffer[0]);
}

int main() {
  test();
  printf("You're safe\n");
  return 0;
}
