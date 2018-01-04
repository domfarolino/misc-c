# 02-bits-and-types

The first example in this folder demonstrates that chars and unsigned chars
have the same bit representation for all 256 values (assuming a char consumes
a single byte of memory) when two's complement is used to represent negative
values. I wrote this example assuming I'd see the sign bit in action when we
overflow a signed char, and when I didn't I read [this](https://stackoverflow.com/questions/18013599)
lovely stackoverflow post explaining that when two's complement is used, there
is no bit representing the sign of a number.

The second example is well documented with comments and you should read them!!
