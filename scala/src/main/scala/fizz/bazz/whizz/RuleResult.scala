package fizz.bazz.whizz

class RuleResult(result: StringBuilder) {
  def this() = this(new StringBuilder(""))

  def collect(matched: Boolean, rr: RuleResult): Boolean =
    collect(matched, rr.toString)

  def collect(matched: Boolean, str: String): Boolean = {
    if (matched) result.append(str)
    matched
  }

  override def toString = result.toString
}
