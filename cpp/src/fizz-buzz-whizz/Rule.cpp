#include "fizz-buzz-whizz/Rule.h"
#include <l0-infra/std/Algorithm.h>

Rule atom(Matcher matcher, Action action) {
  return [=](auto n, auto& rr) {
    return rr.collect(matcher(n), action(n));
  };
}

Rule anyof(const std::vector<Rule>& rules) {
  return [=](auto n, auto& rr) {
    return stdext::any_of(rules, [&](auto& rule) {
      return rule(n, rr); });
  };
}

namespace {
  Rule allMatch(const std::vector<Rule>& rules) {
    return [=](auto n, auto& rr) {
      return stdext::all_of(rules, [&](auto& rule) {
        return rule(n, rr); });
    };
  }
}

Rule allof(const std::vector<Rule>& rules) {
  return [=](auto n, auto& rr) {
    RuleResult result;
    return rr.collect(allMatch(rules)(n, result), result);
  };
}
