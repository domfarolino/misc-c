#include <iostream>

void secretFunction() {
  std::cout << "You've been hacked" << std::endl;
}

void test() {
  int buffer[4];
  int buffer2[4];
  std::cout << "Stack layout:" << std::endl;
  std::cout << buffer + 3 << "  buffer[3]" << std::endl;
  std::cout << buffer + 2 << "  buffer[2]" << std::endl;
  std::cout << buffer + 1 << "  buffer[1]" << std::endl;
  std::cout << buffer << "  buffer[0]" << std::endl;
  /////////////////////////////////////
  std::cout << "Buffer2:" << std::endl;
  std::cout << buffer2 + 3 << "  buffer2[3]" << std::endl;
  std::cout << buffer2 + 2 << "  buffer2[2]" << std::endl;
  std::cout << buffer2 + 1 << "  buffer2[1]" << std::endl;
  std::cout << buffer2 << "  buffer2[0]" << std::endl;
  /////////////////////////////////////
  std::cout << "Let's reach a single int past the end of buffer2 (which is " << (buffer2 + 4) << "), and set it to `10`" << std::endl;
  *(buffer2 + 4) = 10;
  /////////////////////////////////////
  std::cout << "Now buffer[0]: " << buffer[0] << std::endl;
}

int main() {
  test();
  std::cout << "You're safe" << std::endl;
  return 0;
}
