#include "fizz-buzz-whizz/Action.h"

Action to(std::string&& str) {
  return [str = std::move(str)](int) {
    return str;
  };
}

Action nop() {
  return [](int n) {
    return std::to_string(n);
  };
}
