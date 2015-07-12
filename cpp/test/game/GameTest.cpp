#include "magellan/magellan.hpp"
#include "game/Rule.h"
#include "game/RuleResult.h"

USING_HAMCREST_NS

FIXTURE(GameTest)
{
    RuleResult result;
    SharedRule spec = make_spec();

    SharedRule make_spec()
    {
        auto r1_3 = atom(times(3), to("Fizz"));
        auto r1_5 = atom(times(5), to("Buzz"));
        auto r1_7 = atom(times(7), to("Whizz"));

        auto r1 = anyof({r1_3, r1_5, r1_7});

        auto r2 = anyof({ allof({r1_3, r1_5, r1_7})
                        , allof({r1_3, r1_5})
                        , allof({r1_3, r1_7})
                        , allof({r1_5, r1_7})
                        });

        auto r3 = atom(contains(3),  to("Fizz"));
        auto rd = atom(always(true), nop());

        return anyof({r3, r2, r1, rd});
    }

    void rule(int n, const std::string& expect)
    {
        spec->apply(n, result);
        ASSERT_THAT(result, eq(RuleResult(expect)));
    }

    TEST("r1_3")
    {
        rule(3, "Fizz");
    }

    TEST("r1_5")
    {
        rule(5, "Buzz");
    }

    TEST("r1_7")
    {
        rule(7, "Whizz");
    }

    TEST("r3")
    {
        rule(13, "Fizz");
    }

    TEST("r2_1")
    {
        rule(3*5*7, "FizzBuzzWhizz");
    }

    TEST("r2_2")
    {
        rule(3*5, "FizzBuzz");
    }

    TEST("r2_3")
    {
        rule(3*7, "FizzWhizz");
    }

    TEST("r2_4")
    {
        rule((5*7)*2, "BuzzWhizz");
    }

    TEST("priority of r3 greater than r2_4")
    {
        rule(5*7/*35*/, "Fizz");
    }

    TEST("rd")
    {
        rule(2, "2");
    }
};
