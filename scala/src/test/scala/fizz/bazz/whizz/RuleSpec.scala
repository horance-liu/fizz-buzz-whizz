package fizz.bazz.whizz

import org.scalatest._
import org.scalatest.Matchers._

import fizz.bazz.whizz.Actions._
import fizz.bazz.whizz.Matchers._
import fizz.bazz.whizz.Rules._

class RuleSpec extends FunSpec {
  def spec = {
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
    val rd = atom(always(true), nop());

    anyof(r3, r2, r1, rd)
  }

  def rule(n: Int, expected: String) = {
    val result = new RuleResult
    spec(n, result)
    result.toString should be (expected)
  }

  describe("r1") {
    it("times(3) -> Fizz") {
      rule(3, "Fizz")
    }

    it("times(5) -> Buzz") {
      rule(5, "Buzz");
    }

    it("times(7) -> Whizz") {
      rule(7, "Whizz");
    }
  }

  describe("r2") {
    it("times(3) && times(5) && times(7) -> FizzBuzzWhizz") {
      rule(3 * 5 * 7, "FizzBuzzWhizz");
    }

    it("times(3) && times(5) -> FizzBuzz") {
      rule(3 * 5, "FizzBuzz");
    }

    it("times(3) && times(7) -> FizzWhizz") {
      rule(3 * 7, "FizzWhizz");
    }

    it("times(5) && times(7) -> BuzzWhizz") {
      rule((5 * 7) * 2, "BuzzWhizz");
    }
  }

  describe("r3") {
    it("contains(3) -> Fizz") {
      rule(13, "Fizz");
    }

    it("the priority of contains(3) is highest") {
      rule(35 /* 5*7 */ , "Fizz");
    }
  }

  describe("rd") {
    it("others -> others") {
      rule(2, "2");
    }
  }
}
