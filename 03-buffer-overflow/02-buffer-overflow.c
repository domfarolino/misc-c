#include <stdio.h>

void secretFunction() {
  printf("Congratulations!\n");
  printf("You have entered in the secret function!\n");
}

void echo() {
  char buffer[4];
  scanf("%s", buffer);
  printf("You've entered: %s\n", buffer);
}

int main() {
  echo();
  return 0;
}
