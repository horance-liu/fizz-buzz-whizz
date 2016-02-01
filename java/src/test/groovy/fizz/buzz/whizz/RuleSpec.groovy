package fizz.buzz.whizz

import spock.lang.Specification

import static fizz.buzz.whizz.Action.*
import static fizz.buzz.whizz.Matcher.*
import static fizz.buzz.whizz.Rules.*

class RuleSpec extends Specification {
  private static def spec() {
    Rule r1_3 = atom(times(3), to("Fizz"))
    Rule r1_5 = atom(times(5), to("Buzz"))
    Rule r1_7 = atom(times(7), to("Whizz"))

    Rule r1 = anyof(r1_3, r1_5, r1_7)

    Rule r2 = anyof(allof(r1_3, r1_5, r1_7),
        allof(r1_3, r1_5),
        allof(r1_3, r1_7),
        allof(r1_5, r1_7))

    Rule r3 = atom(contains(3), to("Fizz"))
    Rule rd = atom(always(true), nop())

    anyof(r3, r2, r1, rd)
  }

  def "fizz buzz whizz"() {
    expect:
    spec().apply(n) == expect

    where:
    n            | expect
    3            | "Fizz"
    5            | "Buzz"
    7            | "Whizz"
    3 * 5 * 7    | "FizzBuzzWhizz"
    3 * 5        | "FizzBuzz"
    3 * 7        | "FizzWhizz"
    (5 * 7) * 2  | "BuzzWhizz"
    13           | "Fizz"
    35 /* 5*7 */ | "Fizz"
    2            | "2"
  }
}
