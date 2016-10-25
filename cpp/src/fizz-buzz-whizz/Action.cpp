#include "fizz-buzz-whizz/Action.h"
#include "cui/algo/__string__.h"

Action to(std::string&& str) {
  return [str = std::move(str)](auto) {
    return str;
  };
}

Action nop() {
  return [](auto n) {
    return cui::toString(n);
  };
}
