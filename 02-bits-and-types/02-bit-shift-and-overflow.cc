#include <stdio.h>
#include <string>

std::string show_bits(long long num, int max_bits) {
  std::string return_bits;
  for (int i = max_bits - 1; i >= 0; --i) {
    if (num & 1ll << i) return_bits += "1";
    else return_bits += "0";
  }

  return return_bits;
}

int main() {
  int i;
  std::string bits;

  printf("This is an example where when we write `1 << n`, we \n"
         "use the proper type indicator alongside the `1`. Note \n"
         "the lack of errors in the output\n\n");

  int intAdjuster = 0;
  for (i = 28; i < 34; ++i) {
    intAdjuster |= 1 << i;
    bits = show_bits(intAdjuster, 32);
    printf("1 << %d: %d  (bits: %s)\n", i, intAdjuster, bits.c_str());

    // Reset.
    intAdjuster = 0;
  }
  printf("\n");

  unsigned int unsignedIntAdjuster = 0;
  for (i = 28; i < 34; ++i) {
    unsignedIntAdjuster |= 1u << i;
    bits = show_bits(unsignedIntAdjuster, 32);
    printf("1u << %d: %u  (bits: %s)\n", i, unsignedIntAdjuster, bits.c_str());

    // Reset.
    unsignedIntAdjuster = 0;
  }
  printf("\n");


  long int longIntAdjuster = 0;
  for (i = 60; i < 68; ++i) {
    longIntAdjuster |= 1l << i;
    bits = show_bits(longIntAdjuster, 64);
    printf("1l << %d: %li  (bits: %s)\n", i, longIntAdjuster, bits.c_str());

    // Reset.
    longIntAdjuster = 0;
  }
  printf("\n");

  unsigned long int unsignedLongIntAdjuster = 0;
  for (i = 60; i < 68; ++i) {
    unsignedLongIntAdjuster |= 1lu << i;
    bits = show_bits(unsignedLongIntAdjuster, 64);
    printf("1lu << %d: %lu  (bits: %s)\n", i, unsignedLongIntAdjuster, bits.c_str());

    // Reset.
    unsignedLongIntAdjuster = 0;
  }

  printf("\nThis is an example where we always write exactly `1 << n`, \n"
  "and never use proper type indicators. Therefore, the `1` is always \n"
  "intepreted as an integer\n\n");

  // The code below is *basically* a straight-up copy-paste from above.
  intAdjuster = 0;
  for (i = 28; i < 34; ++i) {
    intAdjuster |= 1 << i;
    bits = show_bits(intAdjuster, 32);
    printf("1 << %d: %d  (bits: %s)\n", i, intAdjuster, bits.c_str());

    // Reset.
    intAdjuster = 0;
  }
  printf("\n");

  unsignedIntAdjuster = 0;
  for (i = 28; i < 34; ++i) {
    unsignedIntAdjuster |= 1 << i;
    bits = show_bits(unsignedIntAdjuster, 32);
    printf("1 << %d: %u  (bits: %s)\n", i, unsignedIntAdjuster, bits.c_str());

    // Reset.
    unsignedIntAdjuster = 0;
  }
  printf("\n");


  longIntAdjuster = 0;
  for (i = 60; i < 68; ++i) {
    longIntAdjuster |= 1 << i;
    bits = show_bits(longIntAdjuster, 64);
    printf("1 << %d: %li  (bits: %s)\n", i, longIntAdjuster, bits.c_str());

    // Reset.
    longIntAdjuster = 0;
  }
  printf("\n");

  unsignedLongIntAdjuster = 0;
  for (i = 60; i < 68; ++i) {
    unsignedLongIntAdjuster |= 1 << i;
    bits = show_bits(unsignedLongIntAdjuster, 64);
    printf("1 << %d: %lu  (bits: %s)\n", i, unsignedLongIntAdjuster, bits.c_str());

    // Reset.
    unsignedLongIntAdjuster = 0;
  }

  return 0;
}
