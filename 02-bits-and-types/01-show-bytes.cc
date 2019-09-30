#include <iostream>

#pragma GCC diagnostic ignored "-Wconstant-conversion"

// Right now this shows in big-endian form.
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
  char a; // [-128, 127].
  unsigned char b; // [0, 255].

  printf("sizeof(char): %lu\n", sizeof(char));
  a = 127;
  b = 127;
  showBits(a);
  showBits(b);
  std::cout << "a == b: " << bool(a == b) << std::endl;

  printf("Now assigning both |a| and |b| to 128\n");

  // Overflows to -128. Bits will be the same as |b|
  // however, assuming two's complement.
  a = 128;
  b = 128;
  showBits(a);
  showBits(b);
  std::cout << "a == b: " << bool(a == b) << std::endl;

  return 0;
}
