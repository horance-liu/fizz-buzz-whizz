package fizz.bazz.whizz

import fizz.bazz.whizz.Actions._
import fizz.bazz.whizz.Matchers._
import fizz.bazz.whizz.Rules._

import org.scalatest._
import prop._

class RuleSpec extends PropSpec with TableDrivenPropertyChecks with Matchers {
  val spec = {
    val r1_3 = atom(times(3), to("Fizz"))
    val r1_5 = atom(times(5), to("Buzz"))
    val r1_7 = atom(times(7), to("Whizz"))

    val r1 = anyof(r1_3, r1_5, r1_7)

    val r2 = anyof(
      allof(r1_3, r1_5, r1_7),
      allof(r1_3, r1_5),
      allof(r1_3, r1_7),
      allof(r1_5, r1_7))

    val r3 = atom(contains(3), to("Fizz"))
    val rd = atom(always(true), nop);

    anyof(r3, r2, r1, rd)
  }

  val specs = Table(
    ("n", "expect"),
    (3, "Fizz"),
    (5, "Buzz"),
    (7, "Whizz"),
    (3 * 5, "FizzBuzz"),
    (3 * 7, "FizzWhizz"),
    ((5 * 7) * 2, "BuzzWhizz"),
    (3 * 5 * 7,   "FizzBuzzWhizz"),
    (13, "Fizz"),
    (35, "Fizz"),  // 35 > 5*7
    (2,  "2")
  )

  property("fizz buzz whizz") {
    forAll(specs) { spec(_) should be (_) }
  }
}
