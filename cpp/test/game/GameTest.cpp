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
        auto r1_3 = atom(times_3, to_fizz);
        auto r1_5 = atom(times_5, to_buzz);
        auto r1_7 = atom(times_7, to_whizz);

        auto r1 = orelse({r1_3, r1_5, r1_7});

        auto r2 = orelse({ andalso({r1_3, r1_5, r1_7})
                         , andalso({r1_3, r1_5})
                         , andalso({r1_3, r1_7})
                         , andalso({r1_5, r1_7})
                         });

        auto r3 = atom(contains_3,  to_fizz);
        auto rd = atom(always_true, nop);

        return orelse({r3, r2, r1, rd});
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
