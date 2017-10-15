#include "fizz-buzz-whizz/Game.h"

Rule spec(int n1, int n2, int n3) {
  auto r_n1 = atom(times(n1), to("Fizz"));
  auto r_n2 = atom(times(n2), to("Buzz"));
  auto r_n3 = atom(times(n3), to("Whizz"));

  auto r2 = allof( { r_n1, r_n2, r_n3 });
  auto r3 = atom(contains(n1), to("Fizz"));
  auto rd = atom(always(), nop());

  return anyof( { r3, r2, rd });
}
