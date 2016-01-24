package fizz.bazz.whizz

object Matchers {
  type Matcher = Int => Boolean

  def times(n: Int): Matcher = _ % n == 0
  def contains(n: Int): Matcher = _.toString.contains(n.toString)
  def always(bool: Boolean): Matcher = _ => bool
}
