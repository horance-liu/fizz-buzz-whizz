package fizz.bazz.whizz

import fizz.bazz.whizz.Actions.Action
import fizz.bazz.whizz.Matchers.Matcher

object Rules {
  type Rule = (Int) => String

  def atom(matcher: => Matcher, action: => Action): Rule =
    n => if (matcher(n)) action(n) else ""

  def anyof(rules: Rule*): Rule =
    n => rules.map(_(n))
      .filterNot(_.isEmpty)
      .headOption
      .getOrElse("")

  def allof(rules: Rule*): Rule =
    n => rules.foldLeft("") { _ + _(n) }
}

