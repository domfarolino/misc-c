#include <iostream>
#include <string>

class MoveableDom {
public:
  MoveableDom() {
    std::cout << "Constructor being called" << std::endl;
  }

  MoveableDom(const MoveableDom& rhs) {
    std::cout << "Copy constructor being called" << std::endl;
  }

  MoveableDom(MoveableDom&& rhs) {
    std::cout << "Move constructor being called" << std::endl;
  }
};

class CopyableDom {
public:
  CopyableDom() {
    std::cout << "Constructor being called" << std::endl;
  }

  CopyableDom(const CopyableDom& rhs) {
    std::cout << "Copy constructor being called" << std::endl;
  }
};

int main() {
  MoveableDom mv_dom = MoveableDom(MoveableDom(MoveableDom(MoveableDom())));
  CopyableDom cp_dom = CopyableDom(CopyableDom(CopyableDom(CopyableDom())));
  return 0;
}
