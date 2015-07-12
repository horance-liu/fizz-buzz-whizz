package fizz.buzz;

import org.junit.Test;

import fizz.buzz.RuleResult;

import static org.hamcrest.CoreMatchers.equalTo;
import static org.junit.Assert.assertThat;

import static fizz.buzz.Rule.atom;
import static fizz.buzz.Rule.allof;
import static fizz.buzz.Rule.anyof;
import static fizz.buzz.Matcher.times;
import static fizz.buzz.Matcher.contains;
import static fizz.buzz.Matcher.always;
import static fizz.buzz.Action.to;
import static fizz.buzz.Action.nop;

public class RuleTest {    
    private RuleResult result = new RuleResult();
    private Rule spec = makeSpec();

    private static Rule makeSpec() {
        Rule r1_3 = atom(times(3), to("Fizz"));
        Rule r1_5 = atom(times(5), to("Buzz"));
        Rule r1_7 = atom(times(7), to("Whizz"));

        Rule r1 = anyof(r1_3, r1_5, r1_7);

        Rule r2 = anyof( allof(r1_3, r1_5, r1_7)
                       , allof(r1_3, r1_5)
                       , allof(r1_3, r1_7)
                       , allof(r1_5, r1_7));

        Rule r3 = atom(contains(3), to("Fizz"));
        Rule rd = atom(always(true), nop());

        return anyof(r3, r2, r1, rd);
    }

    void rule(int n, String expect)
    {
        spec.apply(n, result);
        assertThat(result, equalTo(new RuleResult(expect)));
    }
    
    @Test
    public void r1_3() {
        rule(3, "Fizz");
    }
    
    @Test
    public void r1_5() {
        rule(5, "Buzz");
    }

    @Test
    public void r1_7() {
        rule(7, "Whizz");
    }

    @Test
    public void r3() {
        rule(13, "Fizz");
    }

    @Test
    public void r2_1() {
        rule(3*5*7, "FizzBuzzWhizz");
    }

    @Test
    public void r2_2() {
        rule(3*5, "FizzBuzz");
    }

    @Test
    public void r2_3() {
        rule(3*7, "FizzWhizz");
    }

    @Test
    public void r2_4() {
        rule((5*7)*2, "BuzzWhizz");
    }

    @Test
    public void priority_of_r3_greater_than_r2_4() {
        rule(5*7/*35*/, "Fizz");
    }

    @Test
    public void rd() {
        rule(2, "2");
    }
}
