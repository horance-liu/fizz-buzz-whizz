package fizz.buzz.whizz

import org.scalatest.{Matchers, PropSpec}
import org.scalatest.prop.TableDrivenPropertyChecks

class RuleSpec extends PropSpec with TableDrivenPropertyChecks with Matchers {
  val specs = Table(
    ("n",         "expect"),
    (3,           "Fizz"),
    (5,           "Buzz"),
    (7,           "Whizz"),
    (3 * 5,       "FizzBuzz"),
    (3 * 7,       "FizzWhizz"),
    ((5 * 7) * 2, "BuzzWhizz"),
    (3 * 5 * 7,   "FizzBuzzWhizz"),
    (13,          "Fizz"),
    (35/*5*7*/,   "Fizz"),
    (2,           "2")
  )

  property("fizz buzz whizz") {
    val spec = Game.spec(3, 5, 7)
    forAll(specs) { spec(_) should be (_) }
  }
}

