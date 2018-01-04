#include <stdio.h>

/**
 * Basic struct usage in C.
 * Structs in C can't have member
 * functions quite in the same way
 * as C++ (no implicit `this` is passed).
 * Also you'll need to always use `struct Type`
 * when trying to refer to an struct of type `Type`.
 */
struct Point {
  int x;
  int y;
  void (*printCoords)(const struct Point*);
};

void printXY(const struct Point* p) {
  if (!p) return;
  printf("p->x: %i\np->y: %i\n", p->x, p->y);
}

int main() {
  struct Point p = {10, 20, printXY};
  p.printCoords(&p);
  return 0;
}
