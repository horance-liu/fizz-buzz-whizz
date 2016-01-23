package fizz.buzz.whizz;

public final class Rules {
  public static Rule atom(Matcher matcher, Action action) {
    return (n, rr) -> rr.collect(matcher.matches(n), action.to(n));
  }

  private static Rule combine(boolean shortcut, Rule... rules) {
    return (n, rr) -> {
      for (Rule r : rules)
        if (r.apply(n, rr) == shortcut)
          return shortcut;
      return !shortcut;
    };
  }

  public static Rule anyof(Rule... rules) {
    return combine(true, rules);
  }
 
  public static Rule allof(Rule... rules) {
    return (n, rr) -> {
      RuleResult result = new RuleResult();
      return rr.collect(combine(false, rules).apply(n, result), result);
    };
  }
  
  private Rules() {
  }
}
