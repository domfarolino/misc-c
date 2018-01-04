#include <stdio.h>

/**
 * This is a goofy program. Basically we have
 * four numbers with the following types:
 *   - `int`
 *   - `uint`
 *   - `long int`
 *   - `ulong int`
 *
 * ...and with each type of integer we run `number |= 1 << i`
 * where `i` eventually gets large enough to shift 1 all the way
 * to the position where number's most significant bit is. Bitwise-or'ing
 * `number` and our manufactured shift then sets number's most significant bit.
 * The reason we use `int` and `long int` and then their unsigned counterparts is
 * so we can demonstrate that setting the most significant bit on a signed type will
 * generate its most-negative value. To get the largest value we can use an unsigned
 * type whose value will not overflow when the most significant bit is set. Regardless
 * of signage, the bit representation of signed and unsigned types will be the same
 * assuming two's compliment is used.
 *
 * The code in this example is a bit overkill because we could really just be printing the
 * result of the left-shift in each for loop instead of applying the left-shift to the number
 * but the reason I'm not is because:
 *   - I get to use more bitwise operators this way for fun :)
 *   - The original intention of this example was to show that you always have to be
 *     careful that you're using the right type of "1" that you're shifting. That is, if
 *     you'd like to left-shift 1 more than sizeof(int)*8 bits, you'll need to add appropriate
 *     type indicators to the 1. For example, if you wanted to set the 33rd bit of a `long int` variable,
 *     you might write something like `longVar |= (1 << 32)` however since the `1` is by default an `int`,
 *     because we didn't cast it to the proper type, we'll overflow the shifted `1` past the most significant
 *     integer bit and end up setting its least significant bit (which is already set ;) ). We then bitwise-or
 *     the integer with our long int, thus setting its least significant bit as well instead of the 33rd bit.
 *     TODO: modify this example to show this!
 *
 * Three are some nuances with the last of the above points, especially when evaluating `1 << 32`. We're not
 * guaranteed to see an overflow take place when left-shifting past the total number of bits the operand has
 * available. The C Standard says that shifting a number of bits >= than the width (in bits) of the operand
 * (in this case 32, the size in bits of the `int 1`) results in undefined behavior.
 *
 * Most Intel processors are designed to use a 5-bit wide field as a mask for the number of bits to shift a
 * 32-bit data type by. This means in the expression `1 << shiftLengthVariable`, `shiftLengthVariable` is basically
 * a 5-bit integer (max val of 31). If `shiftLengthVar` is larger than 31, it will overflow the 5-bit mask, wrapping
 * around to the least significant bits. This is the idea the last of the above points is trying to get across, even
 * though the behavior is not guaranteed. Furthermore, when using a constant as opposed to a variable, as we did in the
 * example expression `1 << 33`, the compiler may not actually overflow the `1` into its least significant bits as it would
 * if the `33` were stored in a variable.
 *
 * The reason we might not see the same overflow/masking behavior when using a constant is because the compiler can
 * handle it itself without using compiler-generated code storing the constant in an integer type. So in short, overflowing
 * from left-shifting is not guaranteed, but happens on modern Intel processors when the shift length is stored in a variable.
 * It should never be expected to happen when using a constant indicating the shift length.
 */

int main() {
  int i = 0;

  int intAdjuster = 0;
  for (i = 28; i < 32; ++i) {
    intAdjuster |= 1 << i;
    printf("1 << %d: %d\n", i, intAdjuster);
    intAdjuster = 0;
  }
  printf("\n");

  unsigned int unsignedIntAdjuster = 0;
  for (i = 28; i < 32; ++i) {
    unsignedIntAdjuster |= 1u << i;
    printf("1u << %d: %u\n", i, unsignedIntAdjuster);
    unsignedIntAdjuster = 0;
  }
  printf("\n");


  long int longIntAdjuster = 0;
  for (i = 60; i < 64; ++i) {
    longIntAdjuster |= 1l << i;
    printf("1l << %d: %li\n", i, longIntAdjuster);
    longIntAdjuster = 0;
  }
  printf("\n");

  unsigned long int unsignedLongIntAdjuster = 0;
  for (i = 60; i < 64; ++i) {
    unsignedLongIntAdjuster |= 1lu << i;
    printf("1lu << %d: %lu\n", i, unsignedLongIntAdjuster);
    unsignedLongIntAdjuster = 0;
  }

  return 0;
}
