package fizz.buzz.whizz;

@FunctionalInterface
public interface Rule {
  boolean apply(int n, RuleResult rr);
}
