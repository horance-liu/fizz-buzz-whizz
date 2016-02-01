module Matcher
  def times(n)
    ->(x) { x % n == 0 }
  end

  def contains(n)
    ->(x) { x.to_s.include?(n.to_s) }
  end

  def always(b)
    ->(x) { b }
  end
end

module Action
  def to(str)
    ->(n) { str }
  end

  def nop 
    ->(x) { x.to_s }
  end
end

module Rule
  def atom(matcher, action)
    ->(n) { matcher.call(n) ? action.call(n) : '' } 
  end

  def allof(rules)
    ->(n) { strings(rules, n).join }
  end

  def anyof(rules)
    lambda do |n|
      result = strings(rules, n).find { |s| !s.empty? }
      result != nil ? result : ''
    end
  end

  def strings(rules, n)
    rules.map { |rule| rule.call(n) }
  end

  private :strings
end
