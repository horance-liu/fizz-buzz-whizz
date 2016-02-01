#include "magellan/magellan.hpp"
#include "fizz-buzz-whizz/Rule.h"

USING_HAMCREST_NS

FIXTURE(FizzBuzzWhizzSpec) {

  Rule spec = makeSpec();

  Rule makeSpec() {
    auto r1_3 = atom(times(3), to("Fizz"));
    auto r1_5 = atom(times(5), to("Buzz"));
    auto r1_7 = atom(times(7), to("Whizz"));

    auto r1 = anyof( { r1_3, r1_5, r1_7 });

    auto r2 = anyof({
      allof( { r1_3, r1_5, r1_7 } ),
      allof( { r1_3, r1_5 } ),
      allof( { r1_3, r1_7 } ),
      allof( { r1_5, r1_7 } )
    });

    auto r3 = atom(contains(3), to("Fizz"));
    auto rd = atom(always(true), nop());

    return anyof( { r3, r2, r1, rd });
  }

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
    ASSERT_THAT(spec(n), eq(expect));
  }
};
