package fizz.buzz.whizz;

import org.junit.Test;

import fizz.buzz.whizz.Rule;
import fizz.buzz.whizz.RuleResult;

import static fizz.buzz.whizz.Action.*;
import static fizz.buzz.whizz.Matcher.*;
import static fizz.buzz.whizz.Rules.*;
import static org.hamcrest.CoreMatchers.*;
import static org.junit.Assert.assertThat;

public class RuleTest {
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
  public void r2_1() {
    rule(3 * 5 * 7, "FizzBuzzWhizz");
  }

  @Test
  public void r2_2() {
    rule(3 * 5, "FizzBuzz");
  }

  @Test
  public void r2_3() {
    rule(3 * 7, "FizzWhizz");
  }

  @Test
  public void r2_4() {
    rule((5 * 7) * 2, "BuzzWhizz");
  }

  @Test
  public void r3() {
    rule(13, "Fizz");
  }
  
  @Test
  public void priority_of_r3_greater_than_r2_4() {
    rule(35 /* 5*7 */, "Fizz");
  }

  @Test
  public void rd() {
    rule(2, "2");
  }
    
  void rule(int n, String expect) {
    RuleResult result = new RuleResult();
    spec.apply(n, result);
    assertThat(result.toString(), equalTo(expect));
  }
  
  private static Rule makeSpec() {
    Rule r1_3 = atom(times(3), to("Fizz"));
    Rule r1_5 = atom(times(5), to("Buzz"));
    Rule r1_7 = atom(times(7), to("Whizz"));

    Rule r1 = anyof(r1_3, r1_5, r1_7);
    Rule r2 = anyof(allof(r1_3, r1_5, r1_7), allof(r1_3, r1_5), allof(r1_3, r1_7), allof(r1_5, r1_7));
    Rule r3 = atom(contains(3), to("Fizz"));
    Rule rd = atom(always(true), nop());

    return anyof(r3, r2, r1, rd);
  }
  
  private Rule spec = makeSpec();
}
