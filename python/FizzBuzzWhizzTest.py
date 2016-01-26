import unittest


def times(n, s):
    return lambda x: s if x % n == 0 else ''
time3 = times(3, 'Fizz')
time5 = times(5, 'Buzz')
time7 = times(7, 'Whizz')


def allof(*rules):
    return lambda x: reduce(lambda s, rule: s + rule(x), rules, '')


def anyof(*rules):
    def lmb(x):
        for rule in rules:
            if rule(x):
                return rule(x)
    return lmb

r1 = anyof(time3, time5, time7)
r2 = anyof(allof(time3, time5, time7),
           allof(time3, time5),
           allof(time3, time7),
           allof(time5, time7))
r3 = lambda x: 'Fizz' if str(x).count('3') else ''
rd = lambda x: str(x)
lord_of_the_rule = anyof(r3, r2, r1, rd)


class FizzBuzzWhizzTest(unittest.TestCase):

    def test_rule_1(self):
        self.assertEqual('Fizz', lord_of_the_rule(3))
        self.assertEqual('Buzz', lord_of_the_rule(5))
        self.assertEqual('Whizz', lord_of_the_rule(7))

    def test_rule_2(self):
        self.assertEqual('FizzBuzzWhizz', r2(3 * 5 * 7))
        self.assertEqual('FizzBuzz', r2(3 * 5))
        self.assertEqual('BuzzWhizz', r2((5 * 7) * 2))

    def test_rule_3(self):
        self.assertEqual('Fizz', lord_of_the_rule(13))

    def test_priority_of_r3_greater_than_r2(self):
        # rather than 5*7 => BuzzWhizz
        self.assertEqual('Fizz', lord_of_the_rule(35))

    def test_rule_d(self):
        self.assertEqual('2', lord_of_the_rule(2))


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testName']
    unittest.main()
