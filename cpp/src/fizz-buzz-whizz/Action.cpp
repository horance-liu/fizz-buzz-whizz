#include "fizz-buzz-whizz/Action.h"
#include "cui/algo/__string__.h"

Action to(const std::string& str) {
  return [=](auto) {
    return str;
  };
}

Action nop() {
  return [](auto n) {
    return cui::toString(n);
  };
}
