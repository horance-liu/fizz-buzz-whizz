#include "fizz-buzz-whizz/Matcher.h"
#include "cui/algo/__string__.h"

Matcher times(int times) {
  return [=](auto n) {
    return n % times == 0;
  };
}

Matcher contains(int num) {
  return [=](auto n) {
    return cui::toString(n).find(cui::toString(num)) != std::string::npos;
  };
}

Matcher always(bool value) {
  return [=](auto) {
    return value;
  };
}
