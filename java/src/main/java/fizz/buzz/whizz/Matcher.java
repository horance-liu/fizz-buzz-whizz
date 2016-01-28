package fizz.buzz.whizz;

import static java.lang.String.valueOf;

@FunctionalInterface
public interface Matcher {
  boolean matches(int n);

  static Matcher times(int times) {
    return n -> n % times == 0;
  }

  static Matcher contains(int num) {
    return n -> valueOf(n).contains(valueOf(num));
  }

  static Matcher always(boolean bool) {
    return n -> bool;
  }
}
