package fizz.buzz.whizz

object Action {
  type Action = Int => String

  def to(str: String): Action = _ => str
  def nop: Action = _.toString
}
