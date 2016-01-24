package fizz.bazz.whizz

import fizz.bazz.whizz.Actions.Action
import fizz.bazz.whizz.Matchers.Matcher

object Rules {
  type Rule = (Int, RuleResult) => Boolean

  def atom(matcher: => Matcher, action: => Action): Rule =
    (n, rr) => rr.collect(matcher(n), action(n))

  def anyof(rules: Rule*): Rule =
    (n, rr) => rules.exists(_(n, rr))

  def allof(rules: Rule*): Rule =
    (n, rr) => {
      val result = new RuleResult
      rr.collect(rules.forall(_(n, result)), result)
    }
}

