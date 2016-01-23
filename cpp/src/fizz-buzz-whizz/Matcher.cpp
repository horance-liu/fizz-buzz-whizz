#include "fizz-buzz-whizz/Matcher.h"
#include <l0-infra/std/String.h>

USING_STDEXT_NS

Matcher times(int times) {
  return [=](auto n) {
    return n % times == 0;
  };
}

Matcher contains(int num) {
  return [=](auto n) {
    return toString(n).find(toString(num)) != std::string::npos;
  };
}

Matcher always(bool value) {
  return [=](auto) {
    return value;
  };
}
