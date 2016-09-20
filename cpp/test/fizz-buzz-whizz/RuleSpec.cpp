#include "cut/cut.hpp"
#include "fizz-buzz-whizz/Game.h"

USING_CUM_NS

FIXTURE(FizzBuzzWhizzSpec) {
  TEST("fizz buzz whizz") {
    rule(3, "Fizz");
    rule(5, "Buzz");
    rule(7, "Whizz");
    rule(3 * 5 * 7, "FizzBuzzWhizz");
    rule(3 * 5, "FizzBuzz");
    rule(3 * 7, "FizzWhizz");
    rule((5 * 7) * 2, "BuzzWhizz");
    rule(13, "Fizz");
    rule(35 /* 5*7 */, "Fizz");
    rule(2, "2");
  }

  void rule(int n, const std::string& expect) {
    ASSERT_THAT(spec(3, 5, 7)(n), eq(expect));
  }
};
