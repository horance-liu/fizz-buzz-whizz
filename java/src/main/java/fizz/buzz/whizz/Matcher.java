package fizz.buzz.whizz;

@FunctionalInterface
public interface Matcher {
  boolean matches(int n);

  static Matcher times(int times) {
    return n -> n % times == 0;
  }

  static Matcher contains(int num) {
    return n -> Integer.toString(n).contains(Integer.toString(num));
  }

  static Matcher always(boolean bool) {
    return n -> bool;
  }
}
