package fizz.buzz.whizz;

import java.util.Arrays;
import java.util.function.Predicate;
import java.util.stream.Stream;

public final class Rules {
  public static Rule atom(Matcher matcher, Action action) {
    return (n, rr) -> rr.collect(matcher.matches(n), action.to(n));
  }

  public static Rule anyof(Rule... rules) {
    return (n, rr) -> stream(rules).anyMatch(rule(n, rr));
  }

  public static Rule allof(Rule... rules) {
    return (n, rr) -> {
      RuleResult result = new RuleResult();
      return rr.collect(allMatch(rules).apply(n, result), result);
    };
  }

  private static Rule allMatch(Rule... rules) {
    return (n, rr) -> stream(rules).allMatch(rule(n, rr));
  }

  private static Predicate<Rule> rule(int n, RuleResult rr) {
    return r -> r.apply(n, rr);
  }

  private static Stream<Rule> stream(Rule... rules) {
    return Arrays.asList(rules).stream();
  }

  private Rules() {
  }
}
