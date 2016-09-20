package fizz.buzz.whizz

import Rule._
import Matcher._
import Action._

object Game {
  def spec(n1: Int, n2: Int, n3: Int): Rule = {
    val r_n1 = atom(times(n1), to("Fizz"))
    val r_n2 = atom(times(n2), to("Buzz"))
    val r_n3 = atom(times(n3), to("Whizz"))

    val r3 = atom(contains(n1), to("Fizz"))
    val r2 = allof(r_n1, r_n2, r_n3)
    val rd = atom(always(true), nop)

    anyof(r3, r2, rd)
  }
}