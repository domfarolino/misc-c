#include <iostream>

#pragma GCC diagnostic ignored "-Wshift-count-overflow"

int main() {
  for (int i = 28; i < 35; i++) {
    std::cout << "Shift i: " << i << ": " << (1 << i) << std::endl;
  }

  std::cout << std::endl << std::endl;

  std::cout << "Shift i: " << 28 << ": " << (1 << 28) << std::endl;
  std::cout << "Shift i: " << 29 << ": " << (1 << 29) << std::endl;
  std::cout << "Shift i: " << 30 << ": " << (1 << 30) << std::endl;
  std::cout << "Shift i: " << 31 << ": " << (1 << 31) << std::endl;
  // These would normally be warnings by -Wshift-count-overflow.
  std::cout << "Shift i: " << 32 << ": " << (1 << 32) << std::endl;
  std::cout << "Shift i: " << 33 << ": " << (1 << 33) << std::endl;
  std::cout << "Shift i: " << 34 << ": " << (1 << 34) << std::endl;

  return 0;
}
