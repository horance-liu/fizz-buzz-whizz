package fizz.buzz.whizz

object Rule {
  type Rule = (Int) => String

  import Action.Action
  import Matcher.Matcher

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

