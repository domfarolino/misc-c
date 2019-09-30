#include <iostream>

/**
 * Instructions
 *  1. Compile this with no special flags
 *  2. Execute the binary to produce some output
 *  3. Compile this with -fno-elide-constructors flag
 *  4. Execute the binary to produce some output
 *  5. Note the difference in output, since the compiler
 *     elides the copy constructor by default, even when
 *     doing so may have side effects.
 */

class Object {
private:
  int internal;
public:
  Object(int i) {
    internal = i;
    std::cout << "Constructor called with " << i << " passed in " << std::endl;
  }

  Object(const Object& other) {
    std::cout << "Copy constructor called with object whose i value is " << other.internal << std::endl;
  }
};

int main() {
  Object obj1 = Object(1);
  Object obj2 = 2;
  return 0;
}
