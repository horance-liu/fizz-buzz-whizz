#include "fizz-buzz-whizz/Rule.h"
#include <numeric>
#include <algorithm>

Rule atom(const Matcher& matcher, const Action& action) {
  return [=](auto n) {
    return matcher(n) ? action(n) : "";
  };
}

Rule anyof(const std::vector<Rule>& rules) {
  return [=](auto n) {
    auto r = std::find_if(rules.begin(), rules.end(),
      [&](const auto& r) { return !r(n).empty(); });
    return r != std::end(rules) ? (*r)(n) : "";
  };
}

Rule allof(const std::vector<Rule>& rules) {
  return [=](auto n) {
    return std::accumulate(rules.begin(), rules.end(), std::string(""),
      [=](const auto& result, const auto& rule) {
        return result + rule(n);
    });
  };
}
