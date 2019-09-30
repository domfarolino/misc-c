# 02-bits-and-types

## 01-show-bytes

The first example in this folder demonstrates that chars and unsigned chars
have the same bit representation for all 256 values (assuming a char consumes
a single byte of memory) when two's complement is used to represent negative
values. I wrote this example assuming I'd see the sign bit in action when we
overflow a signed char, which would then yield a different bit representation
than unsigned chars, when both of their values were >= than 128. When I didn't
observe this, I found and read [this](https://stackoverflow.com/questions/18013599)
lovely stackoverflow post explaining that when two's complement is used, there is no
bit representing the sign of a number. Didn't realize this.

## 02-bit-shift-and-overflow & 03-constant-shift-length

This is a goofy program. Basically we have four numbers with the following types:
  - `int`
  - `uint`
  - `long int`
  - `ulong int`

...and with each type of integer we run `number |= 1 << i` where `i` eventually
gets large enough to shift 1 all the way to the position where `number`'s most
significant bit is. Bitwise-or'ing `number` and our manufactured shift then sets
`number`'s most significant bit. The reason we use integers and their unsigned
counterparts is so we can demonstrate that setting the most significant bit on
a signed type will generate its most-negative value. To generate this value in
it's positive form, we can use an unsigned type whose value will not overflow into
the negatives when its most significant bit is set. Regardless of signage, the bit
representation of signed and unsigned types through all increments will be the same
when two's complement is used.

Furthermore, this example shows that you always have to be careful to use the right type
of "1" left-shifting. That is, when you write `1 << n`, the `1` is by default represented
as an `int`. If integers are represented by 32 bytes on your platform, and you'd like to
left-shift the 1 more than 32 bits, you'll need to add appropriate type indicators to the 1.
For example, if you wanted to set the 33rd bit of a `long int` variable, you might write something
like `longVar |= (1 << 32)`.

However, since the `1` is interpreted by default as an `int`, we overflow the shifted `1` past
its most significant bit and end up setting its least significant bit. We then bitwise-or the
integer created from our left-shift with our long int, thus setting ITS least significant bit as
well, instead of its 33rd bit as we wished.

See below for more in-the-weeds details.
<details>
There are some nuances with the above point, especially when evaluating `1 << 32`. We're not
guaranteed to see an overflow take place when left-shifting a number >= the total number of
bits the operand has. The C Standard says that shifting by a number of bits >= than the width
(in bits) of the operand (in this case 32) results in undefined behavior. Note that this is
not the same as performing `integer <<= 1`, 32 or more times (in which case overflown bits will
never be recovered). Instead I'm talking about the behavior of `32BitVariableHere <<= {someNumber>=32}`.

Most Intel processors are designed to use a 5-bit wide field as a mask for the number of bits
to shift a 32-bit data type by. This means in the expression `1 << shiftLengthVariable`,
`shiftLengthVariable` is basically a 5-bit integer (max val of 31). If `shiftLengthVar` is larger
than 31, it will overflow the 5-bit mask, wrapping around to the least significant bits, leading
to the behavior described above (though the behavior isnot guaranteed).

Furthermore, when using a constant as opposed to a variable, like `1 << 33` instead of
`1 << shiftLengthVar` the compiler may not actually overflow the `1` into its least significant
bits as it would if the `33` were stored in a variable. This can lead to super nasty undefined
behavior, demonstrated by program **03-constant-shift-length**.

The reason we might not see the same overflow/masking behavior when using a constant is because
the compiler may choose to handle it itself without using the aforementioned 5-bit mask after
storing the constant as an integer. So in short, overflowing the shift-length from left-shifting
is not guaranteed, but happens on modern Intel processors when the shift length is stored in a
variable. This behavior should not be relied upon though, especially, when using a constant shift
length (not a variable).

Good resources/references:

 - https://stackoverflow.com/a/3872587/3947332
 - https://stackoverflow.com/questions/7401888
</details>
