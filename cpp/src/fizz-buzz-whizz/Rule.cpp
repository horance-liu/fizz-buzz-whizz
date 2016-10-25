#include "fizz-buzz-whizz/Rule.h"
#include <numeric>
#include <algorithm>

Rule atom(Matcher&& matcher, Action&& action) {
  return [ matcher = std::move(matcher) 
         , action = std::move(action)](auto n) {
    return matcher(n) ? action(n) : "";
  };
}

Rule anyof(std::vector<Rule>&& rules) {
  return [rules = std::move(rules)](auto n) {
    auto found = std::find_if(rules.cbegin(), rules.cend(),
      [n](const auto& r) { return !r(n).empty(); });
    return found != std::cend(rules) ? (*found)(n) : "";
  };
}

Rule allof(std::vector<Rule>&& rules) {
  return [rules = std::move(rules)](auto n) {
    return std::accumulate(rules.cbegin(), rules.cend(), std::string(""),
      [n](const auto& acc, const auto& r) {
        return acc + r(n);
    });
  };
}
