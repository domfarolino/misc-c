#include <iostream>

void secretFunction() {
  std::cout << "You've been hacked" << std::endl;
}

void test() {
  int buffer[4];
  int buffer2[4];
  std::cout << "Buffer:" << std::endl;
  std::cout << buffer << std::endl;
  std::cout << buffer + 1 << std::endl;
  std::cout << buffer + 2 << std::endl;
  std::cout << buffer + 3 << std::endl;
  /////////////////////////////////////
  std::cout << "Buffer2:" << std::endl;
  std::cout << buffer2 << std::endl;
  std::cout << buffer2 + 1 << std::endl;
  std::cout << buffer2 + 2 << std::endl;
  std::cout << buffer2 + 3 << std::endl;
  /////////////////////////////////////
  std::cout << "Reach past buffer2:" << std::endl;
  std::cout << buffer2 + 4 << std::endl;
  /////////////////////////////////////
  *(buffer + 5) = 10;
}

int main() {
  test();
  std::cout << "You've been saved" << std::endl;
  return 0;
}
