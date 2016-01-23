#include "fizz-buzz-whizz/Action.h"
#include <l0-infra/std/String.h>

Action to(const std::string& str) {
  return [=](auto) {
    return str;
  };
}

Action nop() {
  return [](auto n) {
    return stdext::toString(n);
  };
}
