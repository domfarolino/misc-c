# 03-buffer-overflow

The code in this folder demonstrates how to perform a buffer overflow attack in C, and execute shell code
to take control of a binary. Much of the code follows examples found in:

 - https://dhavalkapil.com/blogs/Buffer-Overflow-Exploit/
 - https://dhavalkapil.com/blogs/Shellcode-Injection/

The first example, `01-buffer-layout.c`, basically just demonstrates how exactly variables on
the stack are layed out in memory. I use two buffers to demonstrate that the stack grows downward
to lower addresses, though individual arrays/buffers _appear_ to grow upward since their last elements
have higher addresses than the earlier elements (which appear later on the stack).

The second example, `02-buffer-overflow.c`, demonstrates code vulnerable to a buffer overflow expolit.
Basically, `scanf`, the vulnerable function, allows us to write data past the end of a stack-allocated
buffer. If we look at an object dump, we can determine exactly how many bytes have been allocated to our
buffer (sometimes it is more than we've requested in the C code) and figure out:

 - How much data to write to the buffer to fill it, overwrite the base pointer, and start writing over the return address
 - The address of the `secretFunction` to place over the return address so we can execute the function

I grabbed the object dump with: `objdump -d 02-buffer-overflow > 02-obj`, and was able to exploit the binary
with: `python -c 'print "a"*16 + "\x8b\x84\x04\x08"' | ./02-buffer-overflow`. On my machine, the 4 byte character buffer
was allocated 12 bytes, so I need to write 16 in order to fill it up and overwrite the base pointer (since the buffer appears
right next to it in memory). The next four bytes will be the address of `secretFunction` in reverse.
