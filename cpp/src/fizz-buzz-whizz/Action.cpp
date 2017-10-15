#include "fizz-buzz-whizz/Action.h"

Action to(std::string&& str) {
  return [str = std::move(str)](auto) {
    return str;
  };
}

Action nop() {
  return [](auto n) {
    return std::to_string(n);
  };
}
