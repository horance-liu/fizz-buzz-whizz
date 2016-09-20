require 'spec_helper'
require 'rule'

describe "fizz buzz whizz" do
  include Game

  [ [3, 'Fizz' ],
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
      expect(spec(3, 5, 7).call(n)).to eq expect
    end
  end
end
