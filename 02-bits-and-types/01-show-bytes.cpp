#include <iostream>

// Right now this shows in big-endian form.
// TODO: make little endian
void showBits(char c) {
  int bit;
  for (int i = 7; i >= 0; --i) {
    bit = c & (1u << i);
    if (bit) std::cout << "1";
    else std::cout << "0";
  }

  std::cout << std::endl;
}

int main() {
  char a;
  unsigned char b = 128;

  printf("sizeof(char): %lu\n", sizeof(char));
  a = 127;
  b = 127;
  showBits(a);
  showBits(b);
  std::cout << "a == b: " << bool(a == b) << std::endl;

  a = 128; // -128 because of overflow, however bits will be same as unsigned assuming two's complement
  b = 128;
  showBits(a);
  showBits(b);
  std::cout << "a == b: " << bool(a == b) << std::endl;

  return 0;
}
