package fizz.buzz.whizz;

import java.util.Arrays;

public final class Rules {
  public static Rule atom(Matcher matcher, Action action) {
    return (n, rr) -> rr.collect(matcher.matches(n), action.to(n));
  }

  public static Rule anyof(Rule... rules) {
    return (n, rr) -> Arrays.asList(rules)
        .stream()
        .anyMatch(rule -> rule.apply(n, rr));
  }
 
  public static Rule allof(Rule... rules) {
    return (n, rr) -> {
      RuleResult result = new RuleResult();
      return rr.collect(allMatch(rules).apply(n, result), result);
    };
  }
  
  private static Rule allMatch(Rule... rules) {
    return (n, rr) -> Arrays.asList(rules)
        .stream()
        .allMatch(rule -> rule.apply(n, rr));
  }
  
  private Rules() {
  }
}
