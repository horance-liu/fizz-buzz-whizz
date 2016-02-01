require 'spec_helper'
require 'fizz_buzz_whizz'

describe "fizz buzz whizz" do
  include Matcher
  include Action
  include Rule
  
  def spec
  	r1_3 = atom(times(3), to("Fizz"))
    r1_5 = atom(times(5), to("Buzz"))
    r1_7 = atom(times(7), to("Whizz"))

    r1 = anyof([r1_3, r1_5, r1_7])

    r2 = anyof([
      allof([r1_3, r1_5, r1_7]),
      allof([r1_3, r1_5]),
      allof([r1_3, r1_7]),
      allof([r1_5, r1_7])])

    r3 = atom(contains(3), to("Fizz"))
    rd = atom(always(true), nop);

    anyof([r3, r2, r1, rd])
  end

  [ 
  	[3, 'Fizz' ],
    [5, 'Buzz' ],
    [7, 'Whizz' ],
    [3*5, 'FizzBuzz' ],
    [3*7, 'FizzWhizz' ],
    [5*7*2, 'BuzzWhizz' ],
    [3*5*7, 'FizzBuzzWhizz' ],
    [13, 'Fizz' ],
    [35, 'Fizz' ],
    [2,  '2' ]
  ].each do |n, expect|
  	it "#{n} -> #{expect}" do
      expect(spec.call(n)).to eq expect
    end
  end
end

