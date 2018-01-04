#include <stdio.h>

/**
 * You can easily declare a typedef
 * in C to make it less verbose to use
 * structs of a certain type.
 */
struct Point {
  int x;
  int y;
  void (*printCoords)(const struct Point*);
};

// Now we can use `Point` instead of `struct Point`
typedef struct Point Point;

/**
 * You can also declare a struct with
 * `typedef` in front of the definition
 * with its name after, which is effectively
 * combining the above bulky steps into one :)
 */
typedef struct {
  int age;
} Person;

void printXY(const Point* p) {
  if (!p) return;
  printf("p->x: %i\np->y: %i\n", p->x, p->y);
}

int main() {
  Point p = {10, 20, printXY};
  p.printCoords(&p);

  Person person;
  person.age = 22;
  printf("person.age: %d\n", person.age);
  return 0;
}
