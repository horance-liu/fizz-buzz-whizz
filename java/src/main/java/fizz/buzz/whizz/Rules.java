package fizz.buzz.whizz;

import java.util.Arrays;
import java.util.stream.Stream;

import static java.util.stream.Collectors.joining;

public final class Rules {
  public static Rule atom(Matcher matcher, Action action) {
    return n -> matcher.matches(n) ? action.to(n) : "";
  }

  public static Rule anyof(Rule... rules) {
    return n ->stringStream(n, rules)
        .filter(s -> !s.isEmpty())
        .findFirst()
        .orElse("");
  }

  public static Rule allof(Rule... rules) {
    return n -> stringStream(n, rules)
        .collect(joining());
  }

  private static Stream<String> stringStream(int n, Rule[] rules) {
    return Arrays.stream(rules)
        .map(r -> r.apply(n));
  }

  private Rules() {
  }
}
