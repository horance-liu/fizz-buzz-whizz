#include "fizz-buzz-whizz/Matcher.h"
#include <string>

Matcher times(int n) {
  return [n](int m) {
    return m % n == 0;
  };
}

Matcher contains(int n) {
  return [n](int m) {
    return std::to_string(m).find(std::to_string(n)) != std::string::npos;
  };
}

Matcher always() {
  return [](int) {
    return true;
  };
}
