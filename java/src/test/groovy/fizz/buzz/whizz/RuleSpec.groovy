package fizz.buzz.whizz

import spock.lang.Specification

import fizz.buzz.whizz.Game

class RuleSpec extends Specification {
  def "fizz buzz whizz"() {
    expect:
    Game.spec(3, 5, 7).apply(n) == expect

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
