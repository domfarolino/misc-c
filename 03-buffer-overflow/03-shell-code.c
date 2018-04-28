#include <stdio.h>
#include <string.h>

void func(char *name) {
  char buf[100];
  strcpy(buf, name);
  printf("Welcome %s\n", buf);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Come on dude\n");
    return 1;
  }

  func(argv[1]);
  return 0;
}
