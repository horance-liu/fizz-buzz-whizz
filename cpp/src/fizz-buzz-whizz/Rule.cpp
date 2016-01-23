#include "fizz-buzz-whizz/Rule.h"
#include <l0-infra/std/Algorithm.h>

using namespace std;

Rule atom(Matcher matcher, Action action) {
  return [=](auto n, auto& rr) {
    return rr.collect(matcher(n), action(n));
  };
}

namespace {
  Rule combine(const std::vector<Rule>& rules, bool shortcut) {
    return [=](auto n, auto& rr) {
      for(auto& rule: rules)
        if (rule(n, rr) == shortcut)
          return shortcut;
      return !shortcut;
    };
  }
}

Rule anyof(const std::vector<Rule>& rules) {
  return combine(rules, true);
}

Rule allof(const std::vector<Rule>& rules) {
  return [=](auto n, auto& rr) {
    RuleResult result;
    return rr.collect(combine(rules, false)(n, result), result);
  };
}
